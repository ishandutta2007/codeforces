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

const int N = 500005;

ll c[N];
map<ll,vector<pair<int,int>>> ed;

struct DSU {
    vector<int> p,r;
    int n;
    int components;
    DSU(int _):n(_),components(_) {
        p.resize(n+1);
        r.resize(n+1);
        for(int i=0;i<=_;++i)
            p[i]=i,r[i]=0;
    }
    int parent(int i) {
        return p[i]=(p[i]==i)?i:parent(p[i]);
    }
    void merge(int x,int y) {
        x=parent(x);
        y=parent(y);
        if(x==y)
            return ;
        if(r[x]>r[y])
            p[y]=x;
        else
            p[x]=y;
        if(r[x]==r[y])
            ++r[y];
        --components;
    }
};

int _runtimeTerror_()
{
    ll ans = 0;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        cin>>c[i];
    ans += power(2,n,M)*((1LL<<k)%M)%M;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        ed[c[x]^c[y]].pb({x,y});
    }
    DSU dsu(n);
    for(auto &j:ed)
    {
        int cnt = 0;
        for(auto &k:j.S)
            dsu.p[k.F] = k.F,dsu.p[k.S] = k.S;
        dsu.components = n;
        for(auto &k:j.S)
        {
            dsu.merge(k.F,k.S);
        }
        ans -= power(2,n,M);
        ans %= M;
        ans += power(2,dsu.components,M);
        ans = (ans + M)%M;
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