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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n+1);
    for(int i=1;i<=m;++i) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back({y, i});
    	g[y].push_back({x, i});
    }
    ++m;
    vector<int> odd;
    for(int i=1;i<=n;++i) {
    	if(sz(g[i]) & 1) {
    		odd.push_back(i);
    	}
    }
    while(!odd.empty()) {
    	int u = odd.back();
    	odd.pop_back();
    	int v = odd.back();
    	odd.pop_back();
    	g[u].push_back({v, m});
    	g[v].push_back({u, m});
    	++m;
    }
    if(~m & 1) {
    	g[1].push_back({1, m});
    	++m;
    }
    vector<bool> used(m + 1, 0);
    cout << m - 1 << "\n";
    vector<int> ans, st = {1};
    while(!st.empty()) {
    	int u = st.back();
    	while(!g[u].empty() && used[g[u].back().S]) {
    		g[u].pop_back();
    	}
    	if(g[u].empty()) {
    		ans.push_back(u);
    		st.pop_back();
    	}
    	else {
    		used[g[u].back().S] = 1;
    		st.push_back(g[u].back().F);
    	}
    }
    for(int i=1;i<ans.size();++i) {
    	if(i & 1) {
    		cout << ans[i-1] << " " << ans[i] << "\n";
    	}
    	else {
    		cout << ans[i] << " " << ans[i-1] << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}