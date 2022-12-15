#include<stdio.h>
 
int N;
int T[10000005][4];
const int MOD = 1000000007;
 
int main(){
    scanf("%d", &N);
    T[0][0] = 1;
    for(int i=1; i<=N; i++){
        int s = 0;
        for(int j=0; j<4; j++) s = (s + T[i - 1][j]) % MOD;
        for(int j=0; j<4; j++) T[i][j] = (s - T[i - 1][j] + MOD) % MOD;
    }
    printf("%d\n",T[N][0]);
    return 0;
}