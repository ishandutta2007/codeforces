#include<stdio.h>
#include<string.h>
#include<algorithm>

#define INF 1000000007
int N, M, K;
int C[1005][2005];

int main(){
    int i, j;

    scanf("%d%d%d",&N,&M,&K);

    C[0][0] = 1;
    for(i=1; i<=1000; i++) for(j=1,C[i][0]=1; j<=i; j++){
        C[i][j] = C[i-1][j-1] + C[i-1][j];
        if(C[i][j] > INF) C[i][j] -= INF;
    }

    printf("%I64d\n",((long long)C[N-1][K*2] * C[M-1][K*2]) % INF);
    return 0;
}