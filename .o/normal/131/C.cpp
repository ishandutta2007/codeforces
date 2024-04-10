#include<stdio.h>

#define N_ 31
#define M_ 31
typedef unsigned long long llu;
llu C[N_][M_];
int N, M, T;
llu res;

int main(){
    int i, j;

    scanf("%d%d%d",&N,&M,&T);

    C[0][0] = 1; int F = (N > M ? N : M);
    for(i=1; i<=F; i++) for(C[i][0] = 1, j=1; j<=i; j++){
        C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    for(i=4; i<T; i++){
        if(i <= N && T-i <= M) res += C[N][i] * C[M][T-i];
    }
    printf("%I64u\n",res);
    return 0;
}