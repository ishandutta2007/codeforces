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
        int n;
        ll k;
        cin>>n>>k;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        ll ans=1e18;
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            ll now=n-1-i;
            ll aim=k/(n-i);aim-=2;
            while(aim*(n-i)<=k)aim++;
            aim--;
            if(aim<a[0])now+=a[0]-aim;
            ans=min(ans,now);
            k-=a[i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}