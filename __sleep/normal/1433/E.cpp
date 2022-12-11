#include<cstdio>
long long ans=1,n,fact=1,c;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<n/2;i++)
        fact*=i;
    for(int i=n;i>n/2;i--)
        ans*=i;
    for(int i=1;i<=n/2;i++)
        ans/=i;
    printf("%lld",ans*fact*fact/2);
    return 0;
}