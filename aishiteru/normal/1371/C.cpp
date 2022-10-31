#include<stdio.h>
int T;
long long a,b,n,m;
int main(){
    scanf("%d",&T);
    while(T--) scanf("%lld%lld%lld%lld",&a,&b,&n,&m),n+m>a+b||(a<b?a:b)<m?puts("No"):puts("Yes");
    return 0;
}