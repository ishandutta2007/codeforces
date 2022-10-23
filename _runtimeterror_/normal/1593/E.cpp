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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    vector<int> deg(n+1);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        ++deg[x], ++deg[y];
        g[x].push_back(y), g[y].push_back(x);
    }
    set<pii> s;
    for(int i=1;i<=n;++i) {
        s.insert({deg[i], i});
    }
    while(k--) {
        if(s.empty()) {
            break;
        }
        if(s.size() == 1) {
            s.clear();
            break;
        }
        vector<int> rm;
        while(!s.empty() && s.begin()->F == 1) {
            rm.push_back(s.begin()->S);
            s.erase(s.begin());
        }
        for(auto &i:rm) {
            for(auto &j:g[i]) {
                if(s.count({deg[j], j})) {
                    s.erase({deg[j], j});
                    --deg[j];
                    s.insert({deg[j], j});
                }
            }
        }
    }
    cout << sz(s) << "\n";
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}