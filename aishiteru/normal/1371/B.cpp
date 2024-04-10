#include<stdio.h>
typedef long long ll;
ll Min(ll p,ll q){return p<q?p:q;}
int T,a,b;
int main(){
    scanf("%d",&T);
    while(T--) scanf("%d%d",&a,&b),printf("%lld\n",Min((a-1ll)*a/2+1,(b+1ll)*b/2));
    return 0;
}