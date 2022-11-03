#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fir first
#define sec second
#define m_p make_pair
#define pb push_back
ll a[300000],b[300000],c[300000],d[300000],k;
ll bs(ll u)
{
    ll l=0;
    ll r=k;
    while (r-l>1)
    {
        ll s=(l+r)/2;
        if (d[s]<=u) l=s; else r=s;
    }
    if (d[r]<=u) l=r;
    return(l);
}
///--------------------------------------------------------------------------------------------------------------///
int main()
{
    fast;
    ll n,m;
    
    cin>>n>>m>>k;
    ll x,s;
    cin>>x>>s;
    
    for (int i=1;i<=m;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
        cin>>b[i];
    for (int i=1;i<=k;i++)
        cin>>c[i];
    for (int i=1;i<=k;i++)
        cin>>d[i];
    ll last=bs(s);
    ll mn=x*(n-c[last]);
    for (int i=1;i<=m;i++)
    {
        ll zal=s-b[i];
        //cout<<zal<<'\n';
        if (zal>=0)
        {
            ll last=bs(zal);
            //cout<<i<<' '<<last<<'\n';
           // cout<<(n/c[last]+(n%c[last]!=0))<<'\n';
            mn=min(mn,min(a[i],x)*max((ll)0,n-c[last]));
            //cout<<mn<<'\n';
        }
    }
    
    cout<<mn;
}