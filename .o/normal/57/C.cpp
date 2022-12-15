#include<stdio.h>

#define SZ 200005
typedef long long lld;
const lld MOD = 1000000007ll;
int N;
lld fac[SZ], inv[SZ];
lld res;

lld pow(lld n, lld m){
    lld v = n, ret = 1;
    for(; m > 0; m >>= 1){
        if(m & 1) ret = (ret * v) % MOD;
        v = (v * v) % MOD;
    }
    return ret;
}

int main(){
    int i;

    scanf("%d",&N);

    fac[0] = 1;
    for(i=1; i<SZ; i++){
        fac[i] = (fac[i-1] * i) % MOD;
        inv[i] = pow(fac[i], MOD-2);
    }

    if(N == 1) res = 1;
    else{
        res = (fac[2*N-1] * inv[N]) % MOD;
        res = (res * inv[N-1]) % MOD;
    }

    res -= N; if(res < 0) res += MOD;
    res *= 2; res += N;
    printf("%I64d\n",res % MOD);
    return 0;
}