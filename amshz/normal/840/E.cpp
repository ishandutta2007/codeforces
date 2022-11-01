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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 5e4 + 10;
const int xm = - 20 + 10;
const int sq = 256;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, q, a[xn], f[xn][256 + 10], H[xn], ptr;
int par[xn], bach[xn][2], P[xn];
vector <int> adj[xn];

void add_trie(int v, int bit, int val){
	if (bit == - 1)
		return;
	bool vj = bool(0 < (val & (1 << bit)));
	if (bach[v][vj] == - 1)
		bach[v][vj] = ++ ptr;
	add_trie(bach[v][vj], bit - 1, val);
}
int get_trie(int v, int bit, int val){
	if (bit == - 1)
		return 0;
	int nd = (val & (1 << bit));
	bool vj = (0 < nd);
	if (bach[v][!vj] + 1)
		return (1 << bit) + get_trie(bach[v][!vj], bit - 1, val);
	return get_trie(bach[v][vj], bit - 1, val);
}
void DFS(int v){
	if (sq <= H[v]){
		int ptv = v;
		ptr = 0;
		for (int i = 0; i < sq; ++ i){
			add_trie(0, 15, a[ptv] ^ i);
			ptv = par[ptv];
		}
		P[v] = ptv;
		for (int i = 0; i * sq + H[v] < n; ++ i)
			f[v][i] = get_trie(0, 15, i * sq);
		for (int i = 0; i <= ptr; ++ i)
			bach[i][0] = bach[i][1] = - 1;
	}
	for (int u : adj[v]){
		if (u == par[v])
			continue;
		par[u] = v;
		H[u] = H[v] + 1;
		DFS(u);
	}
}

int main(){
	fast_io;

	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i < n; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < xn; ++ i)
		bach[i][0] = bach[i][1] = - 1;
	DFS(1);
	while (q --){
		int v, u, w = 0, ans = 0;
		cin >> u >> v;
		while (sq <= H[v] - H[u]){
			ans = max(ans, f[v][w]);
			++ w;
			v = P[v];
		}
		w *= sq;
		while (v != u){
			ans = max(ans, w ^ a[v]);
			v = par[v];
			++ w;
		}
		ans = max(ans, w ^ a[v]);
		cout << ans << endl;
	}

	return 0;
}