#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef long long lld;
lld N;
lld res;

lld gcd(lld a, lld b){
    lld c; while(b){
        c=a%b; a=b; b=c;
    } return a;
}

int main(){
    lld i, j, k;
    scanf("%I64d",&N);
    if(N == 1) return 0 * puts("1");
    if(N == 2) return 0 * puts("2");

    for(k=1; (1<<k)<=N; ++k); 
    if(k > 5) k = 5;
    for(i=3; i<=N; i++){
        lld t = i * (i-1);
        for(j=i-k; j<=i; j++){
            if(j < 0) j = 1;
            lld v = t / gcd(t,j) * j;
            if(v > res) res = v;
        }
    }

    printf("%I64d\n",res);

    //for(int i=1; i<=N; i++) real(i);

    return 0;
}