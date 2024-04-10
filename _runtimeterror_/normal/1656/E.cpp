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
    int n = 1e5;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        // x = 1, y = i;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }

    vector<int> ans(n + 1);
    function<int(int,int,int)> dfs = [&](int s, int p, int dep) {
        int cur = 0;
        if(dep == 0) {
            cur = 0;
        }
        else if(dep & 1) {
            cur = 1;
        }
        else {
            cur = -1;
        }

        int sum = 0;
        for(auto &j:g[s]) {
            if(j == p) {
                continue;
            }
            sum += dfs(j, s, dep + 1);
        }
        ans[s] = cur - sum;
        return cur;
    };
    dfs(1, 0, 0);
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " ";
        // assert(ans[i] >= -1e5 and ans[i] <= 1e5);
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}