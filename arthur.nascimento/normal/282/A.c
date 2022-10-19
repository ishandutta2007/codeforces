#include <stdio.h>

int main() {
    int n, x = 0, i, j, jaFizOperacao;
    char entrada[4];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", entrada);
        if (strcmp(entrada, "X++") == 0 || strcmp(entrada, "++X") == 0 || strcmp(entrada, "+X+") == 0) x++;
        else if (strcmp(entrada, "X--") == 0 || strcmp(entrada, "--X") == 0 || strcmp(entrada, "-X-") == 0) x--;
    }
    printf("%d\n", x);
    
    return 0;
}