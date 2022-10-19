#include"stdio.h"
#define ll long long
#define xunhuan for(i=0;i<n;i++)
ll x1,x2=2147483647,x,i;
ll a[100005],b[100005];
ll n;
ll k,t;
void solve()
{
    if(x1+1==x2)return;
    x=(x1+x2)/2;
    t=k;
    xunhuan
    {
        if(b[i]<a[i]*x)t-=a[i]*x-b[i];
        if(t<0)break;
    }
    if(t<0)x2=x;
    else x1=x;
    solve();
}
int main()
{
    while(1)
    {
        x1=0;
        if(scanf("%lld",&n)==EOF)break;
        scanf("%lld",&k);
        xunhuan scanf("%lld",a+i);
        xunhuan scanf("%lld",b+i);
        int max=0;
        xunhuan if(max<(b[i]+k)/a[i])max=(b[i]+k)/a[i];
        x2=max+1;
        solve();
        printf("%lld\n",x1);
    }
    return 0;
}