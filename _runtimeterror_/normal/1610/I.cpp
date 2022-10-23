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
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y), g[y].push_back(x);
    }
    vector<int> dp(n+1), vis(n+1), par(n+1);
    function<void(int,int)> dfs = [&](int s,int p) {
    	par[s] = p;
    	for(auto &j:g[s]) {
    		if(j != p) {
    			dfs(j, s);
    			dp[s] ^= 1 + dp[j];
    		}
    	}
    };
    dfs(1, 0);
    cout << (dp[1] ? "1" : "2");

    vis[1] = 1;

    int ans = dp[1];

    for(int i=2;i<=n;++i) {
    	int u = i;
    	if(!vis[u]) {
    		int pr = dp[u];
    		while(!vis[u]) {
    			ans ^= dp[u];
    			vis[u] = 1;
    			if(vis[par[u]]) {
    				ans ^= dp[par[u]];
    			}
    			int tmp = dp[par[u]];
    			dp[par[u]] ^= 1 + pr;
    			pr = tmp;
    			u = par[u];
    			ans ^= 1;
    		}
    		ans ^= dp[u];
    	}
    	cout << (ans ? "1" : "2");
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}