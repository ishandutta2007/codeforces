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

const int N = 100005;

set<int> v[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<ll> w(n+1),deg(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>w[i];
        v[i].clear();
    }
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        ++deg[x],++deg[y];
        v[x].insert(y),v[y].insert(y);
    }
    vector<int> u;
    for(int i=1;i<=n;++i)
    {
        u.pb(i);
        --deg[i];
    }
    sort(all(u),[&](int x,int y)
    {
        return w[x]>w[y];
    });
    int cur = 0;
    ll ans = 0;
    for(int i=1;i<=n;++i)
        ans += w[i];
    cout<<ans<<" ";
    for(int i=2;i<=n-1;++i)
    {
        int pr = cur;
        while(cur<n && deg[u[cur]] == 0)
            ++cur;
        ans += w[u[cur]];
        --deg[u[cur]];
        cout<<ans<<" ";
    }
    cout<<"\n";
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