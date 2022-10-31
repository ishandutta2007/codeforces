// khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
 
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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, par[xn], sz[xn], dp[xn], H[xn];
int c[xn], ted;
pii E[xn];
bool mark[xn];
vector <pii> adj[xn];
vector <int> G[xn], leaf;

int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
void merge(int v, int u){
	v = get_root(v);
	u = get_root(u);
	if (v == u)
		return;
	if (sz[v] < sz[u] || true)
		swap(v, u);
	par[u] = v;
	sz[v] += sz[u];
}
void DFS2(int v, int p = - 1){
	int d = 1 - (v == get_root(1));
	for (int u : G[v])
		if (u != p)
			DFS2(u, v), ++ d;
	if (d == 1)
		leaf.push_back(v);
}
void DFS(int v, int p = - 1){
	mark[v] = true;
	dp[v] = H[v];
	for (pii u : adj[v]){
		if (mark[u.A]){
			if (u.A != p)
				dp[v] = min(dp[v], H[u.A]);
			continue;
		}
		H[u.A] = H[v] + 1;
		c[u.B] = u.A;
		DFS(u.A, v);
		dp[v] = min(dp[v], dp[u.A]);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		E[i] = {v, u};
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	DFS(1);
	if (n == 2)
		kill(- 1);
	for (int i = 1; i <= n; ++ i)
		adj[i].clear(), par[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; ++ i)
		if (!c[i] || dp[c[i]] < H[c[i]])
			merge(E[i].A, E[i].B);
	for (int i = 1; i <= m; ++ i){
		if (c[i] && dp[c[i]] >= H[c[i]]){
			int v = E[i].A, u = E[i].B;
			v = get_root(v), u = get_root(u);
			G[v].push_back(u);
			G[u].push_back(v);
		}
	}
	DFS2(get_root(1));
	ted = SZ(leaf);
	cout << (ted + 1) / 2 << endl;
	for (int i = 0; i < (ted + 1) / 2; ++ i)
		cout << leaf[i] << sep << leaf[i + ted / 2] << endl;
	
	return 0;
}