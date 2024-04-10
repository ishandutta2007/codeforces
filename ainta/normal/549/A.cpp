#include<stdio.h>
int n, m;
int i, j, k, l, c, r;
char p[60][60];
int main(){
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++){
        scanf("%s", p[i] + 1);
    }
    for (i = 1; i < n; i++){
        for (j = 1; j < m; j++){
            c = 0;
            for (k = 0; k < 2; k++){
                for (l = 0; l < 2; l++){
                    if (p[i + k][j + l] == 'f')c |= 1;
                    if (p[i + k][j + l] == 'a')c |= 2;
                    if (p[i + k][j + l] == 'c')c |= 4;
                    if (p[i + k][j + l] == 'e')c |= 8;
                }
            }
            if (c == 15)r++;
        }
    }
    printf("%d\n", r);
}