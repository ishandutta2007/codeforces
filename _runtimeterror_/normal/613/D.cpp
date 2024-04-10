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

const int N = 100005;

bitset<N> safe;
bool vis[N];

const int LOGN=20;
vector<int> v[N],g[N];
ll dep[N],par[N][LOGN];
int in[N],out[N],cur=0;
int dp[N][2];
int cnt[N];
void dfs(ll s,ll p)
{
    in[s] = cur++;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1,par[j][0]=s;
            dfs(j,s);
        }
    }
    out[s] = cur-1;
}
void sparseMatrix(ll n)
{
    for(ll i=1;i<LOGN;++i)
        for(ll j=1;j<=n;++j)
                par[j][i]=par[par[j][i-1]][i-1];
}
ll lca(ll u,ll v)
{
    if(dep[u]>dep[v])swap(u,v);
    ll df=dep[v]-dep[u];
    for(ll i=0;i<LOGN;++i)
        if(df&(1<<i))v=par[v][i];
    if(u==v)return u;
    for (ll i=LOGN-1; i>=0; i--) 
    {
        if(par[u][i]!=par[v][i]) 
        { 
            u=par[u][i]; 
            v=par[v][i];
        } 
    }
    return par[u][0]; 
}
ll pl(ll a,ll b)
{
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}

int legend(vector<int> &v)
{
    sort(all(v),[&](int x,int y)
    {
        return in[x]<in[y];
    });
    int nx = sz(v);
    for(int i=0;i<nx-1;++i)
        v.push_back(lca(v[i],v[i+1]));
    sort(all(v),[&](int x,int y)
    {
        return in[x]<in[y];
    });
    v.resize(unique(all(v))-v.begin());
    vector<int> ed;
    auto isAncestor = [&](int x,int y)
    {
        return in[y]>=in[x] && in[y]<=out[x];
    };
    for(int j:v)
    {
        g[j].clear();
    }
    nx = sz(v);
    ed.pb(v[0]);
    for(int i=1;i<nx;++i)
    {
        while(!isAncestor(ed.back(),v[i]))
            ed.pop_back();
        g[ed.back()].pb(v[i]);
        ed.pb(v[i]);
    }
    return ed[0];
}

void print(int s,int p)
{
    cout<<s<<" ";
    for(int j:g[s])
        if(j!=p)
            print(j,s);
}

void dfs2(int s,int p)
{
    dp[s][1] = dp[s][0] = 2e9;

    int c = 0,d = 0,e = 2e9,f = 0;

    for(int j:g[s])
    {
        if(j!=p)
        {
            dfs2(j,s);
            c += min(dp[j][0],dp[j][1]);
            d += dp[j][0];
            amin(e,-dp[j][0]+dp[j][1]);
        }
    }
    if(!safe[s])
    {
        amin(dp[s][0],c+1),amin(dp[s][0],d);
        amin(dp[s][1],d+e);
    }   
    else
    {
        amin(dp[s][0],1+d);
        amin(dp[s][1],d);
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    sparseMatrix(n);
    int Q;
    cin>>Q;
    for(int i=0;i<Q;++i)
    {
        int k,ans = 0;
        cin>>k;
        vector<int> x(k);
        for(int j=0;j<k;++j)
        {
            cin>>x[j];
            safe[x[j]] = 1; 
            if(vis[x[j]] || vis[par[x[j]][0]] || cnt[x[j]])
                ans = -1;
            vis[x[j]] = true;
            ++cnt[par[x[j]][0]];
        }
        int root = legend(x);
        dfs2(root,0);
        for(int j:x)
        {
            safe[j] = 0;
            vis[j] = false;
            vis[par[j][0]] = false;
            cnt[par[j][0]] = 0;
        }
        if(ans == -1)
            cout<<-1<<"\n";
        else
            cout << min(dp[root][1],dp[root][0])<<"\n";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}