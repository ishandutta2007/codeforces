#include<stdio.h>
int n, Comb[4010][4010];
long long Mod = 1000000007, D1[4010], D2[4010], D[4010], G[4010][4010], Res;
int main(){
    int i, j;
    for (i = 0; i <= 4000; i++){
        Comb[i][0] = 1;
        for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % Mod;
    }
    scanf("%d", &n);
    G[1][1] = 1;
    D1[1] = 1;
    D1[0] = 1;
    for (i = 2; i <= n; i++){
        for (j = 1; j <= i; j++){
            G[i][j] = (G[i][j] + G[i - 1][j - 1] + G[i - 1][j] * j) % Mod;
            D1[i] = (D1[i] + G[i][j])%Mod;
        }
    }
    for (i = 1; i <= n; i++){
        Res = (Res + Comb[n][i] * D1[n - i])%Mod;
    }
    printf("%lld\n", Res);
}