#include <cstdio>
int main(){
    int w,h;
    long long ans = 1LL;
    scanf("%d%d",&w,&h);
    for(int i=0;i<w+h;i++){
        ans = (ans*2LL)%998244353;
    }
    printf("%lld\n",ans);
}