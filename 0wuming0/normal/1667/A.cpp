#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[100005];
ll b[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    ll sum=1e18;
    for(int k=1;k<=n;k++)
    {
        ll ans=0;
        for(int i=1;i<=n;i++)b[i]=0;
        for(int i=k+1;i<=n;i++)
        {
            ll k=(b[i-1]+1)/a[i];
            ans+=k;
            b[i]=a[i]*k;
            while(b[i]<=b[i-1])
            {
                b[i]+=a[i];
                ans++;
            }
        }
        for(int i=k-1;i>=1;i--)
        {
            ll k=(b[i+1]+1)/a[i];
            ans+=k;
            b[i]=a[i]*k;
            while(b[i]<=b[i+1])
            {
                b[i]+=a[i];
                ans++;
            }
        }
        sum=min(sum,ans);
    }
    cout<<sum<<endl;
    return 0;
}