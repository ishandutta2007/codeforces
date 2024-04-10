#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N_ 105
const int MOD = 1000000007;
typedef long long lld;
int N;
int C[N_][N_];
int A[10];
int T[10][N_];
lld res;

int main(){
    int i, j, k;

    scanf("%d",&N);
    for(i=0; i<10; i++) scanf("%d",A+i);

    C[0][0] = 1;
    for(i=1; i<=N; i++) for(C[i][0]=C[i][i]=1, j=1; j<i; j++){
        C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
    
    for(j=A[9]; j<=N; j++) T[9][j] = 1;
    for(i=8; i>=0; i--) for(j=0; j<=N; j++) for(k=A[i]; k<=j; k++){
        T[i][j] = (T[i][j] + (lld)T[i+1][j-k] * C[j-!i][k]) % MOD;
    }

    for(i=1; i<=N; i++){
        res = (res + T[0][i]) % MOD;
    }
    printf("%I64d\n",res);
    return 0;
}