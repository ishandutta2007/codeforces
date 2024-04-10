#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        scanf("%lld%lld",&n,&x);
        for(int i=1;i<=n;i++)scanf("%lld",a+i);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)a[i]+=a[i-1];
        ll ans=0,now=0;
        for(int i=n;i>=1;i--)
        {
            //0--1e100
            //i*k+a[i]<=x
            if(a[i]>x)continue;
            ans+=i*((x-a[i])/i-now+1);
            //cout<<i<<" "<<now<<" "<<(x-a[i])/i-now+1<<" "<<i*((x-a[i])/i-now+1)<<endl;
            now=(x-a[i])/i+1;
            //cout<<i<<" "<<now<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}