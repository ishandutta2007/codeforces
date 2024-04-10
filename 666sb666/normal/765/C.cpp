#include <cstdio>
long long k,a,b;
int main(){
    scanf("%lld%lld%lld",&k,&a,&b);
    if (a<b){
        long long t=a;a=b;b=t;
    }
    if (b<k && a%k!=0){
        printf("-1\n");
        return 0;
    }
    long long ans=a/k+b/k;
    printf("%lld\n",ans);
    return 0;
}