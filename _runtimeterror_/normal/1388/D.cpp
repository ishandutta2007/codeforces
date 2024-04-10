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

const int N=200005;
vector<int> v[N];
ll a[N],b[N];
ll dp[N];
ll ans=0;
vector<int> aa,bb;

void dfs(int s,int p)
{
    ll mx=0;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            mx+=dp[j];
        }
    }
    dp[s]=max(0ll,mx+a[s]);
    if(dp[s]>0)
        aa.pb(s);
    else
        bb.pb(s);
    ans+=mx+a[s];
}

int _runtimeTerror_()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];
    vector<int> r;
    for(int i=1;i<=n;++i)
    {
        if(b[i]==-1)
        {
            r.pb(i);
            continue;
        }
        v[b[i]].pb(i);
    }
    //ll ans=0;
    for(auto j:r)
    {
        //cout<<j<<"\n";
        dfs(j,0);
        //cout<<"ans "<<ans<<"\n";
    }
    cout<<ans<<"\n";
    reverse(all(bb));
    for(auto j:aa)
        cout<<j<<" ";
    for(auto j:bb)
        cout<<j<<" ";
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