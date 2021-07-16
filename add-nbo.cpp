#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>

int add_nbo(char* file){
    FILE* f;
    f = fopen(file,"rb");

    uint32_t buffer;
    size_t fsize = fread(&buffer, 1, sizeof(f), f);
    if(fsize != sizeof(uint32_t)){
        fprintf(stderr, "error! fread return %lu \n", fsize);
        exit(1);
    }

    uint32_t res = ntohl(buffer);

    fclose(f);
    return res;
}

int main(int argc, char *argv[]) {
    if(argc != 3){
        fprintf(stderr, "error! Only 2 files.");
        return 1;
    }

    uint32_t a = add_nbo(argv[1]);
    uint32_t b = add_nbo(argv[2]);

    uint32_t add = a + b;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, add, add);

    return 0;
}
