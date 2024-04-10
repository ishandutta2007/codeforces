// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
 
const int xn = 3e5 + 10;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 998244353;
const int base = 257;

int n, k, a[xn], par[xm][xn], H[xn], f[xn];
int dp[xn][2], Par[xn], sz[xn], ps[xn];
pii E[xn];
vector <int> adj[xn], G[xn], vec[xn];

void preDFS(int v){
	vec[a[v]].push_back(v);
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		par[0][u] = v;
		H[u] = H[v] + 1;
		preDFS(u);
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
		swap(v, u);
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= H[u] - H[v])
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; i >= 0; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
int get_root(int v){
	if (v == Par[v])
		return v;
	return Par[v] = get_root(Par[v]);
}
void dsu(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u])
		swap(v, u);
	sz[v] += sz[u];
	Par[u] = v;
	if ((a[v] > 0 && a[u] > 0 && a[v] != a[u]))
		a[v] = - 1;
	else if (a[v] == - 1 || a[u] == - 1)
		a[v] = - 1;
	else
		a[v] |= a[u];
}
void DFS(int v){
	for (int u : adj[v])
		if (u != par[0][v])
			DFS(u), ps[v] += ps[u];
	if (ps[v])
		dsu(v, par[0][v]);
}
void DFS2(int v, int p = - 1){
	dp[v][0] = 1;
	for (int u : G[v]){
		if (u == p)
			continue;
		DFS2(u, v);
		dp[v][0] = 1LL * dp[v][0] * dp[u][0] % mod;
	}
	for (int u : G[v])
		if (u != p && !a[v])
			dp[v][1] = (ll(dp[v][1]) + 1LL * dp[v][0] * power(dp[u][0], mod - 2, mod) % mod * dp[u][1] % mod) % mod;
	dp[v][0] = (dp[v][0] + dp[v][1]) % mod;
	if (a[v])
		dp[v][1] = dp[v][0];
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], sz[i] = 1, Par[i] = i;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		E[i] = {v, u};
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	preDFS(1);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	for (int i = 1; i <= k; ++ i){
		for (int j = 0; j < SZ(vec[i]) - 1; ++ j){
			int v = vec[i][j], u = vec[i][j + 1];
			++ ps[v], ++ ps[u];
			ps[LCA(v, u)] -= 2;
		}
	}
	DFS(1);
	for (int i = 0; i < n - 1; ++ i){
		int v = E[i].A, u = E[i].B;
		v = get_root(v);
		u = get_root(u);
		if (v == u)
			continue;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i)
		if (i == get_root(i) && a[i] == - 1)
			kill(0);
	DFS2(get_root(1));
	cout << dp[get_root(1)][1] << endl;
	
	return 0;
}