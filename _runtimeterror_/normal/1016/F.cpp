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

const int N = 300005;
vector<pii> v[N];

bool path[N];

int64_t fst[N],lst[N];
int par[N];

void dfs(int s,int p)
{
    par[s] = p;
    for(auto &[j,k]:v[s])
    {
        if(j == p)
            continue;
        fst[j] = fst[s] + k;
        dfs(j,s);
    }
}
void dfs2(int s,int p)
{
    for(auto &[j,k]:v[s])
    {
        if(j == p)
            continue;
        lst[j] = lst[s] + k;
        dfs2(j,s);
    }
}

void dfs3(int s,int p,int &cnt,ll &mx,ll &ls)
{
    amax(mx,fst[s]);
    amax(ls,lst[s]);
    ++cnt;
    for(auto &j:v[s])
    {
        if(j.F == p || path[j.F])
            continue;
        dfs3(j.F,s,cnt,mx,ls);
    }
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
    dfs(1,0);
    dfs2(n,0);
    vector<int> p;
    int cur = n;
    while(cur)
        p.push_back(cur),path[cur] = true,cur = par[cur];
    reverse(all(p));
    bool good = false;
    ll mx = -INF;
    set<pll> s;
    s.insert({-INF,n+10});
    for(int i = sz(p)-1;i>=0;--i)
    {
        int cnt = 0;
        ll d1 = 0,d2 = 0;
        dfs3(p[i],0,cnt,d1,d2);
        if(cnt >= 3)
        {
            good = true;
            break;
        }
        if(i < sz(p) - 1 && cnt == 1)
        {
            s.erase({lst[p[i+1]],p[i+1]});
            amax(mx,s.rbegin()->F+d1);
            s.insert({lst[p[i+1]],p[i+1]});
        }
        else if(cnt == 2)
        {
            amax(mx,s.rbegin()->F+d1);
        }
        if(cnt == 1)
            s.insert({d2,p[i]});
        else
            s.insert({d2,n+1});
    }
    while(m--)
    {
        int x;
        cin>>x;
        if(good)
            cout<<lst[1]<<"\n";
        else
            cout<<min(lst[1],int64_t(x + mx))<<"\n";
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