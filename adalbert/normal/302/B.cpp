#include <bits/stdc++.h>
using namespace std;
#define sec second
#define fir first
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef int ll;
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
///------------------------------------------------------------///

///------------------------------------------------------------///

ll a[100000],sum[100000];
///------------------------------------------------------------///
int main()
{
    fast;
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        ll c,t;
        cin>>c>>t;
        a[i]=c*t;
    }
    for (int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=m;i++)
    {
        ll t;
        cin>>t;
        ll l=1;
        ll r=n;
        while (r-l>1)
        {
            ll d=(l+r)/2;
            if (sum[d]<t) l=d; else r=d;
        }
        while (sum[l]<t) l++;
        cout<<l<<'\n';
    }
}