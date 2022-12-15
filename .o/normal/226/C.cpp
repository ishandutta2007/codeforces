#include<stdio.h>
#include<string.h>

typedef long long lld;

lld M, L, R, K, N;

struct S{
    lld a,b,c,d;
    S(): a(0), b(0), c(0), d(0) { }
    S operator*(const S&t){
        S r; 
        r.a = ( a * t.a + b * t.c ) % M;
        r.b = ( a * t.b + b * t.d ) % M;
        r.c = ( c * t.a + d * t.c ) % M;
        r.d = ( c * t.b + d * t.d ) % M;
        return r;
    }
};

int main(){
    lld i;

    scanf("%lld%lld%lld%lld",&M,&L,&R,&K);
    for(i = 1; i * i <= R; i++){
        if(R/i - (L-1)/i >= K) N = (N > i ? N : i);
        lld t = R / i;
        if(R/t - (L-1)/t >= K) N = (N > t ? N : t);
    }
    
    S now, tmp; bool ck = false;
    tmp.b = tmp.c = tmp.d = 1 % M;
    for(i = 1; i <= N; i <<= 1){
        if(N & i){
            if(!ck) now = tmp, ck = true;
            else now = now * tmp;
        } tmp = tmp * tmp;
    }

    printf("%lld\n",now.b);
    return 0;
}