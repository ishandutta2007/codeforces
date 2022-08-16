#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
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

const int N = 200005;
vector<int> v[N];

ll a[N],dp[N],sub[N];
ll cnt[N];

void dfs(int s,int p)
{
    dp[s] = a[s];
    sub[s] = 0;
    ll mx = -1;
    if(sz(v[s])==1 && s!=1)
        cnt[s] = 1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            sub[s] += sub[j];
            amax(mx,dp[j]);
            cnt[s] += cnt[j];
        }
    }
    if(mx==-1)
    {
        sub[s] = a[s];
        return ;
    }
    // cout<<cnt[s]<<" "<<sub[s]<<" "<<mx<<"\n";
    ll u = mx*cnt[s];
    u -= sub[s];
    dp[s] = mx;
    if(u<=a[s])
    {
        u = a[s]-u;
        dp[s] = mx + (u/cnt[s]) + ((u%cnt[s])!=0);
    }
    sub[s] += a[s];
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        int p;
        cin>>p;
        v[p].pb(i),v[i].pb(p);
    }
    for(int i=1;i<=n;++i)
        cin>>a[i];
    dfs(1,0);
    cout<<dp[1]<<"\n";
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