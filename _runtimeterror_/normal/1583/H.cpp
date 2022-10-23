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

const int N = 200005;

int par[N][20], mx[N][20];
int e[N];
vector<pii> v[N];
int dep[N];

void dfs(int s,int p, int w) {
	par[s][0] = p;
	mx[s][0] = w;
	for(int i=1;i<20;++i) {	
		par[s][i] = par[par[s][i-1]][i-1];
		mx[s][i] = max(mx[s][i-1], mx[par[s][i-1]][i-1]);
	}
	for(auto &[j,w]:v[s]) {
		if(j != p) {
			dep[j] = dep[s] + 1;
			dfs(j, s, w);
		}
	}
}

int p[N], mx_id[N], cmp_ans[N], sub[N];

int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    for(int i=1;i<=n;++i) {
    	cin >> e[i];
    	p[i] = i;
    	mx_id[i] = i;
    	cmp_ans[i] = 0;
    	sub[i] = 1;
    }
    vector<array<int,4>> edges;
    for(int i=1;i<=n-1;++i) {
    	int x, y, w, t;
    	cin >> x >> y >> w >> t;
    	edges.push_back({w, t, x, y});
    	v[x].push_back({y, t});
    	v[y].push_back({x, t});
    }
    dfs(1, 0, 0);

    auto get = [&](int u, int v) {
    	if(dep[v] < dep[u]) {
    		swap(u, v);
    	}
    	int d = dep[v] - dep[u];
    	int ans = 0;
    	for(int i=0;i<20;++i) {
    		if(d & (1 << i)) {
    			amax(ans, mx[v][i]);
    			v = par[v][i];
    		}
    	}
    	if(v == u) {
    		return ans;
    	}
    	for(int i=19;i>=0;--i) {
    		if(par[u][i] != par[v][i]) {
    			amax(ans, mx[u][i]);
    			amax(ans, mx[v][i]);
    			v = par[v][i], u = par[u][i];
    		}
    	}
    	amax(ans, max(mx[u][0], mx[v][0]));
    	return ans;
    };
    function<int(int)> parent = [&](int x) {
    	return p[x] = (p[x] == x) ? x : parent(p[x]);
    };
    function<void(int,int)> merge = [&](int x,int y) {
    	x = parent(x), y = parent(y);
    	if(sub[y] < sub[x]) {
    		swap(x, y);
    	}
    	p[x] = y;
    	if(e[mx_id[y]] == e[mx_id[x]]) {
    		amax(cmp_ans[y], cmp_ans[x]);
    		amax(cmp_ans[y], get(mx_id[x], mx_id[y]));
    	}
    	else if(e[mx_id[y]] < e[mx_id[x]]) {
    		swap(cmp_ans[x], cmp_ans[y]);
    		swap(mx_id[y], mx_id[x]);
    	}
    };
    sort(edges.rbegin(), edges.rend());

    vector<pii> ans(Q + 1);
    vector<array<int, 3>> q;
    for(int i=1;i<=Q;++i) {
    	int v, x;
    	cin >> v >> x;
    	q.push_back({v, x, i});
    }
    sort(q.rbegin(), q.rend());
    int cur = 0;
    for(int i=0;i<Q;++i) {
    	while(cur < edges.size() && edges[cur][0] >= q[i][0]) {
    		merge(edges[cur][2], edges[cur][3]);
    		++cur;
    	}
    	ans[q[i][2]].F = e[mx_id[parent(q[i][1])]];
    	ans[q[i][2]].S = max(cmp_ans[parent(q[i][1])], get(q[i][1], mx_id[parent(q[i][1])]));
    }
    for(int i=1;i<=Q;++i) {
    	cout << ans[i].F << " " << ans[i].S << "\n";
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