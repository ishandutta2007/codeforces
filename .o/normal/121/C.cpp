#include<stdio.h>
#include<string.h>

typedef long long lld;
lld N, L, K;
lld Fac[17];
int A[17]; bool Ck[17];

bool isLucky(lld n){
    while(n > 0){
        if(n % 10 != 7 && n % 10 != 4) return false;
        n /= 10;
    }
    return true;
}

lld res;

int main(){
    int i, j;

    scanf("%I64d%I64d",&N,&K);
    Fac[0] = 1;
    for(i=1; i<=15; i++) Fac[i] = Fac[i-1] * i;
    for(L=1; L<=15; L++) if(Fac[L] >= K) break;
    if(N <= 15 && K > Fac[N]) return 0 * puts("-1");
    
    // Get K-th permutation
    --K; for(i=1; i<=L; i++){
        for(j=1; j<=L; j++) if(!Ck[j]){
            if(K >= Fac[L-i]) K -= Fac[L-i];
            else break;
        }
        Ck[j] = true;
        if(isLucky(i+N-L) && isLucky(j+N-L)) ++res;
    }

    // Count Lucky Numbers
    N -= L;
    for(i=1; i<10; i++){
        for(j=0; j<(1<<i); j++){
            lld num = 0;
            for(int k=0; k<i; k++){
                num *= 10; num += ((j & (1<<k)) ? 4 : 7);
            }
            if(num <= N) ++res;
        }
    }

    printf("%I64d\n",res);
    return 0;
}