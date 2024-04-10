#include<stdio.h>
int K, cnt, cc, ct;
long long n, P[101000], D[101000];
int main(){
    scanf("%lld%d",&n,&K);
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            cc++;
            D[cc] = i;
            ct++;
            if(n!=i*i){
                P[cc] = n/i;
                ct++;
            }
        }
    }
    if(ct<K)printf("-1\n");
    else if(cc < K)printf("%lld ", P[ct-K+1]);
    else printf("%lld\n",D[K]);
}