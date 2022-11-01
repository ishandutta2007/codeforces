# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, k, par[xn], P[xn], root, sz[xn], jad[xn], H[xn];
ll c[xn], dp[2][xn], w[xn];
pii E[xn];
bool flag[xn], mark[xn];
vector <pii> adj[xn], G[xn];

int get_root(int v){
	if (v == par[v]) return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u) return;
	if (sz[v] < sz[u]) swap(v, u);
	par[u] = v;
	sz[v] += sz[u];
	if (H[jad[v]] < H[jad[u]]) jad[u] = jad[v];
	else jad[v] = jad[u]; 
}
void DFS3(int v){
	dp[1][v] += dp[1][P[v]] - w[v];
	if (dp[1][v] < 0) dp[1][v] = 0;
	dp[1][v] += c[v];
	for (pii u : G[v]){
		if (u.A == P[v]) continue;
		DFS3(u.A);
	}
}
void DFS2(int v){
	for (pii u : G[v]){
		if (u.A == P[v]) continue;
		P[u.A] = v;
		w[u.A] = u.B;
		DFS2(u.A);
		if (dp[0][u.A] - u.B < 0) continue;
		dp[0][v] += dp[0][u.A] - u.B;
	}
	for (pii u : G[v]){
		if (u.A == P[v]) continue;
		dp[1][u.A] = dp[0][v];
		if (dp[0][u.A] - u.B > 0) dp[1][u.A] -= dp[0][u.A] - u.B;
	}
	dp[0][v] += c[v];
}
void DFS(int v){
	mark[v] = true;
	sz[v] = 1;
	for (pii x : adj[v]){
		int u = x.A;
		if (u == P[v]) continue;
		if (mark[u]){
			int res = v;
			while (get_root(res) != get_root(u)){
				res = jad[get_root(res)];
				merge(P[res], res);
			}
			continue;
		}
		P[u] = v;
		H[u] = H[v] + 1;
		DFS(u);
		flag[v] |= flag[u];
	}
	if (!flag[v]) merge(v, P[v]);
}

int main(){
    InTheNameOfGod;
    
	cin >> n >> m >> k;
	while (k --){
		int v;
		cin >> v;
		flag[v] = true;
		root = v;
	}
	for (int i = 1; i <= n; ++ i){
		cin >> c[i];
		par[i] = i;
		sz[i] = 1;
		jad[i] = i;
	}
	for (int i = 1; i <= m; ++ i) cin >> w[i];
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		E[i] = {v, u};
		adj[v].push_back({u, w[i]});
		adj[u].push_back({v, w[i]});
	}
	DFS(root);
	for (int i = 1; i <= n; ++ i){
		int v = get_root(i);
		if (v != i) c[v] += c[i];
		flag[v] |= flag[i];
	}
	root = get_root(root);
	for (int i = 1; i <= m; ++ i){
		int v = E[i].A;
		int u = E[i].B;
		v = get_root(v);
		u = get_root(u);
		if (v == u) continue;
		G[v].push_back({u, w[i]});
		G[u].push_back({v, w[i]});
	}
	P[root] = 0;
	DFS2(root);
	P[root] = 0;
	DFS3(root);
	for (int i = 1; i <= n; ++ i){
		int v = get_root(i);
		cout << dp[0][v] + dp[1][v] - c[v] << sep;
	}
	cout << endl;

    return 0;
}