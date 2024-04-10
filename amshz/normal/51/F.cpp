//khodaya khodet komak kon
# pragma comment(linker, "/stack:200000000")
# pragma GCC optimize("Ofast")
# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e3 + 10;
const int xm = 1e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, P[xn], H[xn], sz[xn];
int f[xn], dp[xn][2], ans = - 1, par[xn];
vector <int> adj[xn], vec, G[xn];
vector <pii> E;
bool mark[xn];

int get_root(int v){
	if (v == P[v])
		return v;
	return P[v] = get_root(P[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	P[u] = v;
	sz[v] += sz[u];
	++ ans;
	if (H[f[u]] < H[f[v]])
		f[v] = f[u];
}
void DFS(int v){
	mark[v] = true;
	vec.push_back(v);
	for (int u : adj[v]){
		if (mark[u]){
			if (H[u] >= H[v] || u == par[v])
				continue;
			int res = v;
			while (get_root(res) != get_root(u)){
				res = get_root(res);
				merge(f[res], par[f[res]]);
			}
			continue;
		}
		E.push_back({v, u});
		H[u] = H[v] + 1;
		par[u] = v;
		DFS(u);
	}
}
void DFS2(int v, int p = - 1){
	dp[v][1] = sz[v] = 1;
	for (int u : G[v]){
		if (u == p)
			continue;
		DFS2(u, v);
		dp[v][1] += dp[u][1];
		sz[v] += sz[u];
	}
	dp[v][0] = inf;
	for (int u : G[v])
		if (u != p)
			dp[v][0] = min(dp[v][0], dp[v][1] - 1 - dp[u][1] + dp[u][0]);
	dp[v][1] = min(dp[v][1], sz[v] - 1);
	if (dp[v][0] == inf)
		dp[v][0] = 0;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i){
		P[i] = f[i] = i;
		sz[i] = 1;
	}
	for (int i = 1; i <= n; ++ i){
		if (mark[i])
			continue;
		E.clear(), vec.clear();
		DFS(i), ++ ans;
		for (pii e : E){
			int v = get_root(e.A);
			int u = get_root(e.B);
			if (v == u)
				continue;
			G[v].push_back(u);
			G[u].push_back(v);
		}
		int mn = inf;
		for (int v : vec)
			if (v == get_root(v))
				DFS2(v), mn = min(mn, dp[v][0]);
		ans += mn;
	}
	cout << ans << endl;

	return 0;
}