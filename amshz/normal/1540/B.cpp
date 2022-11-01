//khodaya khodet komak kon
# include <bits/stdc++.h>

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

const int xn = 2e2 + 10;
const int xm = 8;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, fact[xn], ifact[xn], ans, dist[xn], sz[xn], H[xn], par[xm][xn], dp[xn][xn];
vector <int> adj[xn];
bool f[xn];

int C(int n, int r){
	if (r < 0 || n < 0 || n - r < 0)
		return 0;
	return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
void DFS(int v){
	for (int i = 1; i < xm; ++ i)
		par[i][v] = par[i - 1][par[i - 1][v]];
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		H[u] = H[v] + 1;
		par[0][u] = v;
		DFS(u);
	}
}
int LCA(int v, int u){
	if (H[u] < H[v])
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
void build(int v){
	memset(H, 0, sizeof H);
	par[0][v] = 0, DFS(v);
}

int main(){
	InTheNameOfGod;

	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	for (int i = 1; i < xn; ++ i)
		dp[0][i] = 1;
	for (int i = 1; i < xn; ++ i)
		for (int j = 1; j < xn; ++ j)
			dp[i][j] = 1ll * power(2, mod - 2, mod) * (dp[i - 1][j] + dp[i][j - 1]) % mod;
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int v = 1; v <= n; ++ v){
		build(v);
		for (int u = 1; u < v; ++ u){
			for (int s = 1; s <= n; ++ s){
				int lca = LCA(u, s);
				int x = H[lca];
				int y = H[u] - H[lca];
				ans = (ans + dp[x][y]) % mod;
			}
		}
	}
	cout << 1ll * ans * power(n, mod - 2, mod) % mod << endl;

	return 0;
}