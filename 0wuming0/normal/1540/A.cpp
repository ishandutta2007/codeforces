#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100105];
ll s[100105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        sort(a,a+n);
        for(int i=0;i<n+10;i++)
        {
            s[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            s[i]=n-i;
        }
        for(int i=2;i<=n+1;i++)
        {
            s[i]-=i-1;
        }
        for(int i=1;i<=n;i++)s[i]+=s[i-1];
        ll ans=0;
        ans-=a[n-1];
        for(int i=n-1;i>=1;i--)a[i]-=a[i-1];
        for(int i=0;i<n;i++)ans+=s[i]*a[i];
        cout<<-ans<<endl;
    }
    return 0;
}