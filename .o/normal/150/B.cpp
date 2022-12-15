#include<stdio.h>

typedef unsigned long long llu;
llu N, M, K;
#define INF 1000000007
int pow(llu n, llu m){
    int ret = 1;
    while(m){
        if(m & 1) ret = (ret * n) % INF;
        n = (n * n) % INF; m >>= 1;
    }
    return ret;
}
llu res;

int main(){
    int i, j;

    scanf("%d%d%d",&N,&M,&K);
    if(K == 1 || K > N) res = pow(M, N);
    else if(K == N) res = pow(M, (N+1)/2);
    else if(K & 1) res = M*M; else res = M;
    printf("%I64u\n",res);
    return 0;
}