// Har Har Mahadev
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


const int N = 1000005;

ll a[N],c[N];
ll par[N][20];
int _runtimeTerror_()
{
    int Q;
    cin>>Q>>a[1]>>c[1];
    int cur = 2;
    auto can = [&](int v)
    {
        if(a[v] == 0)
            return -1;
        for(int i=19;i>=0;--i)
        {
            if(a[par[v][i]] != 0)
                v = par[v][i];
        }
        return v;
    };
    for(int _=1;_<=Q;++_)
    {
        int tt;
        cin>>tt;
        if(tt == 1)
        {
            int p,have,cost;
            cin>>p>>have>>cost;
            ++p;
            int ver = _+1;
            par[ver][0] = p;
            for(int i=1;i<20;++i)
                par[ver][i] = par[par[ver][i-1]][i-1];
            a[ver] = have,c[ver] = cost;
        }
        else
        {
            int ver,w;
            cin>>ver>>w;
            ++ver;
            ll ans = 0;
            int done = 0;
            // debug(ver,w);
            while(w)
            {
                int u = can(ver);
                // debug(u,a[u]);
                if(u == -1)
                    break;
                if(a[u] >= w)
                {
                    ans += w * c[u];
                    a[u] -= w;
                    done += w;
                    w = 0;
                }
                else
                {
                    w -= a[u];
                    ans += a[u] * c[u];
                    done += a[u];
                    a[u] = 0;
                }
            }
            cout<<done<<" "<<ans<<"\n";
            cout<<flush;
        }
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