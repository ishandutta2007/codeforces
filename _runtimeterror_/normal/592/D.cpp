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

const int N = 200005;
vector<int> v[N],g[N];
bool bad[N];
int sub[N];
int dep[N];
int n,m;
int cnt = 0;

void dfs2(int s,int p)
{
    ++cnt;
    for(auto j:g[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s]+1;
            dfs2(j,s);
        }
    }
}

void dfs(int s,int p)
{
    sub[s] = bad[s];
    for(int j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            sub[s] += sub[j];
        }
    }
    if(sub[s]<m && sub[s]>0)
        g[p].pb(s),g[s].pb(p);
}

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=m;++i)
    {
        int x;
        cin>>x;
        bad[x] = true;
    }
    dfs(1,0);
    int r = -1,one = -1;
    for(int i=1;i<=n;++i)
    {
        if(!g[i].empty())
            r = i;
        if(bad[i])
            one = i;
    }
    if(r==-1)
    {
        cout<<one<<" "<<0<<"\n";
        return 0;
    }
    dfs2(r,0);
    int ans = 0;
    ans += 2*(cnt-1);
    pair<int,int> p = {2e9,-1};
    for(int i=1;i<=n;++i)
        p = min(p,{-dep[i],i});
    assert(p.F!=0);
    dep[p.S] = 0;
    dfs2(p.S,0);
    int u = p.S;
    p = {2e9,-1};
    for(int i=1;i<=n;++i)
    {
        p = min(p,{-dep[i],i});
    }
    ans += p.F;
    cout<<min(p.S,u)<<"\n"<<ans<<"\n";
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