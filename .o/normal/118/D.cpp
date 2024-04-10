#include <stdio.h>
#include <string.h>

const int N_ = 105;
const int MOD = 100000000;

int A[N_][N_], B[N_][N_];
int N, N1, N2, K1, K2;
int res;

int main(){
    int i, j, k;
    
    scanf("%d%d%d%d", &N1, &N2, &K1, &K2);
    
    A[0][0] = B[0][0] = 1;
    for(i = 1; i <= K1; i++) A[i][0] = 1;
    for(i = 1; i <= K2; i++) B[0][i] = 1;
    
    for(i = 1; i <= N1; i++){
        for(j = 1; j <= N2; j++){
            for(k = 1; k <= K1 && k <= i; k++){
                A[i][j] = (A[i][j] + B[i - k][j]) % MOD;
            }
            for(k = 1; k <= K2 && k <= j; k++){
                B[i][j] = (B[i][j] + A[i][j - k]) % MOD;
            }
        }
    }
    
    printf("%d\n", (A[N1][N2] + B[N1][N2]) % MOD);
    return 0;
}