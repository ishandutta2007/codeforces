/* 
 * File:   main.cpp
 * Author: tncks0121
 *
 * Created on 2012 12 28 (),  10:45
 */
#include<stdio.h>
#include<stdlib.h>

typedef long long lld;
const int MOD = 1000000007;
const int N_ = 105;

lld N, M, K;
int Combi[N_][N_];
lld Value[N_][2];
lld T[N_][N_ * N_];

lld Power (lld a, lld b){
    lld ret = 1;
    while(b > 0){
        if(b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {
    int i, j, k;

    scanf("%lld%lld%lld",&N,&M,&K);

    for(i = 1; i <= N; i++){
        Combi[i][0] = Combi[i][i] = 1;
        for(j = 1; j < i; j++)
            Combi[i][j] = (Combi[i - 1][j - 1] + Combi[i - 1][j]) % MOD;
    }

    for(i = 0; i <= N; i++) for(j = 0; j <= 1; j++){
        Value[i][j] = Power(Combi[N][i], (M / N) + j);
    }

    T[0][0] = 1;
    for(i = 1; i <= N; i++) for(j = 0; j <= K; j++){
        lld &v = T[i][j];
        for(k = 0; k <= N && k <= j; k++){
            v += (T[i - 1][j - k] * Value[k][(i <= M % N)]) % MOD;
            v %= MOD;
        }
    }

    printf("%lld\n",T[N][K]);
    return 0;
}