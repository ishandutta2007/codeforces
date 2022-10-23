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
    vector<int> f(n+1,0);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=k;++i) {
    	int x;
    	cin >> x;
    	f[x] = 1;
    }
    bool ans = false;
    for(int i=1;i<=n-1;++i) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y), g[y].push_back(x);
    }
    vector<int> ch(n+1, 0), dep(n+1, 0);
    function<int(int,int)> dfs1 = [&](int s, int p) {
    	int mn = 1e9;
    	for(auto &j:g[s]) {
    		if(j == p) {
    			continue;
    		}
    		dep[j] = dep[s] + 1;
    		amin(mn, dfs1(j, s));
    	}
    	if(f[s] == 1) {
    		amin(mn, dep[s]);
    	}
    	if(mn - dep[s] <= dep[s]) {
    		ch[s] = 1;
    	}
    	return mn;
    };
    dfs1(1, 0);
    function<void(int,int)> dfs2 = [&](int s,int p) {
    	if(ch[s]) {
    		return ;
    	}
    	if(sz(g[s]) == 1 && s != 1) {
    		ans = true;
    		return ;
    	}
    	for(auto &j:g[s]) {
    		if(j != p) {
    			dfs2(j, s);
    		}
    	}
    };
    dfs2(1, 0);
    cout << (ans ? "YES" : "NO") << "\n";
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