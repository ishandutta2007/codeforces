#include<stdio.h>
#include<algorithm>
#include<functional>
#include<assert.h>

const int N_ = 100005;
const int LEN = 10;
const int MOD = 1000000007;
typedef long long lld;
using namespace std;

int N, K;
lld fac[N_] = {1, };
int Lucky[1<<LEN], LN;
int Count[1<<LEN];
lld T[1<<LEN] = {1, };

lld FastPow(lld n, lld k){
    lld ret = 1, val = n;
    while(k > 0){
        if(k & 1) ret = (ret * val) % MOD;
        val = (val * val) % MOD;
        k >>= 1;
    }
    return ret;
}

lld Combi (lld n, lld k){
    lld ret = fac[n];
    if(n < k) return 0;
    ret *= FastPow(fac[k],   MOD - 2); ret %= MOD;
    ret *= FastPow(fac[n-k], MOD - 2); ret %= MOD;
    return ret;
}

void Generate_Lucky(){
    for(int i = 1; i < 10; ++i) for(int mask = 0; mask < (1 << i); ++mask){
        int &val = Lucky[++LN]; val = 0;
        for(int x = i - 1; x >= 0; x--){
            val *= 10;
            val += (mask & (1 << x)) ? 7 : 4;
        }
    }
}

lld res;
int A[1<<LEN], AN;

int main(){
    int i, j;

    scanf("%d%d",&N,&K);

    Generate_Lucky();

    for(i = 1; i <= N; i++){
        fac[i] = (fac[i-1] * i) % MOD;
        int dat; scanf("%d", &dat);
        int pos = lower_bound (Lucky + 1, Lucky + LN + 1, dat) - Lucky;
        if(pos > LN || Lucky[pos] != dat) pos = 0;
        Count[pos] ++;
    }

    for(i = 1; i <= LN; i++){
        if(Count[i]) A[++AN] = Count[i];
    }
    
    std::sort(A+1, A+AN+1);

    for(i = 1; i <= AN; i++) {
        for(j = i; j > 0; j--) T[j] = (T[j] + T[j - 1] * A[i]) % MOD;
    }

    for(i = 0; i <= K && i <= AN; i++) if(K - i <= *Count){
        res = (res + Combi(*Count, K - i) * T[i]) % MOD;
    }

    printf("%I64d\n",res);
    return 0;
}