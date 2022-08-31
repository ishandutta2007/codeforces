#include<stdio.h>
int n, w[10];
int main(){
    int i, c = 0, M = 0, j, t, r;
    scanf("%d", &n);
    while (n){
        w[c++] = n % 10;
        n /= 10;
    }
    for (i = 0; i < c; i++)if (M < w[i])M = w[i];
    printf("%d\n", M);
    for (i = 1; i <= M; i++){
        r = 0;
        t = 1;
        for (j = 0; j < c; j++){
            if (w[j]){
                w[j]--;
                r += t;
            }
            t *= 10;
        }
        printf("%d ", r);
    }
}