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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 605;

ll w[N][N];

ll g[N][N];

ll fx[N][N];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            w[i][j] = INF,fx[i][j] = -INF,g[i][j] = -INF;
        w[i][i] = 0;
    }
    vector<pair<int,pii>> ed;
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        amin(w[x][y],z);
        amin(w[y][x],z);
        ed.push_back({z,{x,y}});
    }
    int Q;
    cin>>Q;
    for(int i=1;i<=Q;++i)
    {
        int u,v,l;
        cin>>u>>v>>l;
        amax(g[u][v],l);
        amax(g[v][u],l);
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                amin(w[i][j],w[i][k]+w[k][j]);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i == j)
                continue;
            for(int k=1;k<=n;++k)
            {
                amax(fx[i][j],g[i][k]-w[j][k]);
            }
        }
    }
    int ans = 0;
    for(auto [j,k]:ed)
    {
        auto [x,y] = k;
        bool valid = false;
        for(int i=1;i<=n;++i)
        {
            ll u = w[i][x] + j;
            valid = valid | (fx[i][y] >= u);
            valid = valid | (fx[i][x] >= w[i][y] + j);
            if(valid)
                break;
        }
        ans += valid;
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