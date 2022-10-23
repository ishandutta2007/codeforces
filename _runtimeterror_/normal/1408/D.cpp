#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    ll n,m;
    cin>>n>>m;
    vector<pll> a(n),b(m);
    for(int i=0;i<n;++i)
        cin>>a[i].F>>a[i].S;
    for(int i=0;i<m;++i)
        cin>>b[i].F>>b[i].S;
    vector<pll> v;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(b[j].F-a[i].F>=0 && b[j].S-a[i].S>=0)
                v.pb({b[j].F-a[i].F,b[j].S-a[i].S});
        }
    }
    if(v.empty())
    {
        cout<<"0\n";return 0;
    }
    sort(all(v));
    ll ans = INF;
    v.resize(unique(all(v))-v.begin());
    // hor 0
    int nn =sz(v);
    vector<ll> suf(sz(v)+1);
    suf.back()=0;
    for(int i=nn-1;i>=0;--i)
        suf[i] = max(suf[i+1],v[i].S);
    amin(ans,suf[0]+1);
    for(int i=0;i<nn;++i)
    {
        // cout<<v[i]<<"\n";
        ll u = v[i].F+1;
        if(i!=nn-1)
            u += suf[i+1]+1;
        amin(ans,u);
    }
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}