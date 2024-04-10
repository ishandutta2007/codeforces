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

const int N=500005;
vector<int> v[N],g[N];
int par[N],dep[N];
bool vis[N];
int n,m;

void dfs(int s,int p,int d)
{
    vis[s]=true;
    par[s]=p;
    dep[s]=d;
    for(auto j:v[s])
    {
        if(!vis[j])
        {
            dfs(j,s,d+1);
        }
    }
    g[dep[s]].pb(s);
}

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        v[i].clear(),par[i]=0,g[i].clear(),vis[i]=false;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    if(n==2)
    {
        assert(m==1);
        cout<<"PATH\n1 2\n";
        return 0;
    }
    dfs(1,0,0);
    pair<int,int> mx={-1,-1};
    int pairs=0;
    for(int i=1;i<=n;++i)
    {
        amax(mx,make_pair(dep[i],i));
        pairs+=g[i].size()/2;
    }
    if(mx.F>=(n+1)/2)
    {
        cout<<"PATH\n";
        cout<<mx.F+1<<"\n";
        while(mx.S!=1)
        {
            cout<<mx.S<<" ";
            mx.S=par[mx.S];
        }
        cout<<"1\n";
        return 0;
    }
    cout<<"PAIRING\n";
    cout<<pairs<<"\n";
    for(int i=1;i<=mx.F;++i)
    {
        int x=g[i].size();
        x-=x%2;
        for(int j=0;j<x;j+=2)
            cout<<g[i][j]<<" "<<g[i][j+1]<<"\n";
    }
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}