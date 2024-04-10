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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> ans(n-1);
    vector<vector<pii>> g(n+1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, i-1}), g[y].push_back({x,i-1});
    }
    int lf = 1;
    for(int i=1;i<=n;++i) {
        if(sz(g[i]) >= 3) {
            cout << "-1\n";
            return 0;
        }
        if(sz(g[i]) == 1) {
            lf = i;
        }
    }
    vector<int> ed;
    function<void(int,int)> dfs = [&](int s, int p) {
        for(auto &[j, k]:g[s]) {
            if(j != p) {
                ed.push_back(k);
                dfs(j, s);
            }
        }
    };
    dfs(lf, 0);
    int cur = 2;
    for(auto &i:ed) {
        ans[i] = cur;
        cur = 5 - cur;
    }
    for(auto &j:ans) {
        cout << j << " ";
    }
    cout << "\n";
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
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}