#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) ll x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
int main()
{
    fast
    ll n,m,k;
    cin>>n>>m>>k;
    ll x,s;
    cin>>x>>s;
    ll a[m],b[m];
    pair<ll,ll> p[m];
    for(ll i=0;i<m;i++)
        cin>>a[i];
    for(ll i=0;i<m;i++)
        {cin>>b[i];p[i]={b[i],a[i]};}
    ll c[k],d[k];
    for(ll i=0;i<k;i++)
        cin>>c[i];
    for(ll i=0;i<k;i++)
        cin>>d[i];
    sort(p,p+m);
    map<ll,ll> mm;
    mm[p[0].F]=p[0].S;
    set<ll> ss;
    ss.insert(p[0].F);
    ll mnn=p[0].S;
    for(ll i=1;i<m;i++)
    {
        if(mnn>p[i].S)
            {mm[p[i].F]=p[i].S;mnn=p[i].S;ss.insert(p[i].F);}
    }
    ll ans=n*x;
    // for(auto i:ss)
    //  cout<<i<<" "<<mm[i]<<endl;
    auto itx=ss.upper_bound(s);
    if(itx!=ss.begin())
        {
            itx--;
                ans=min(ans,n*mm[(*itx)]);
        }
    for(ll i=0;i<k;i++)
    {
        ll nn=n;
        if(s<d[i]) break;
        auto it=ss.upper_bound(s-d[i]);
        nn-=c[i];
        if(nn<=0)
        {
            ans=min(ans,(ll)0);
            break;
        }
        ans = min(ans,nn*x);
        if(it!=ss.begin())
        {
            it--;
            ans=min(ans,mm[(*it)]*nn);
        }
    }
    cout<<ans;
    return 0;
}