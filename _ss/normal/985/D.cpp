#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    //freopen("ss.inp","r",stdin);
    ll n,h;
    cin>>n>>h;
    if (h>=(2*n+h)/(h+1))
    {
        ll l=1,r=h,mid,t=h;
        while (l<=r)
        {
            mid=(l+r)/2;
            if (mid<(2*n+mid)/(mid+1)) l=mid+1;
            else r=mid-1,t=mid;
        }
        cout<<t;
        return 0;
    }
    ll l=h+1,r=1e18,mid,t=h;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (mid<(n+h*(h-1)/2+mid-1)/mid) l=mid+1;
        else r=mid-1,t=mid;
    }
    ll ans=t*2-h;
    l=h,r=1e18,t=h;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (mid<(n+h*(h-1)/2+mid)/(mid+1)) l=mid+1;
        else r=mid-1,t=mid;
    }
    ans=min(ans,t*2-h+1);
    cout<<ans;
    return 0;
}