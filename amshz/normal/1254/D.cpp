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

const int xn = 1.5e5 + 10;
const int xm = 18;
const int sq = 700;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, q, TM, stm[xn], ftm[xn], a[xn];
int sz[xn], INV, fen[xn], par[xn];
vector <int> adj[xn];
vector <pip> vec[xn];
 
void mofen(int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[pos] = (fen[pos] + val) % mod;
}
int gefen(int pos){
	int res = 0;
	for (pos += 5; 0 < pos; pos -= pos & - pos)
		res = (res + fen[pos]) % mod;
	return res;
}
bool cmp(int v, int u){
	return sz[v] < sz[u];
}
void preDFS(int v){
	sz[v] = 1;
	for (int u : adj[v]) {
		if (u == par[v])
			continue;
		par[u] = v;
		preDFS(u);
		sz[v] += sz[u];
	}
	sz[par[v]] += n + 1;
	sort(all(adj[v]), cmp);
	sz[par[v]] -= n + 1;
	if (par[v])
		adj[v].pop_back();
}
void DFS(int v){
	stm[v] = ++ TM;
	for (int u : adj[v]){
		if (u == par[v])
			continue;
		DFS(u);
		if (!SZ(vec[v]) || sz[u] != vec[v].back().A)
			vec[v].push_back({sz[u], {stm[u], ftm[u]}});
		vec[v].back().B.B = ftm[u];
	}
	ftm[v] = TM;
}
void update(int l, int r, int val) {
	if (l <= r)
		mofen(l, val), mofen(r + 1, (mod - val) % mod);
}
 
int main(){
	fast_io;

	cin >> n >> q;
	INV = power(n, mod - 2, mod);
	for (int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	preDFS(1), DFS(1);
	while (q --) {
		int t, v, d, k, res;
		cin >> t;
		if (t == 1){
			cin >> v >> d;
			a[v] = (a[v] + d) % mod;
			k = 1ll * d * sz[v] % mod * INV % mod;
			update(1, stm[v] - 1, k);
			update(ftm[v] + 1, n, k);
			for (pip x : vec[v])
				update(x.B.A, x.B.B, 1ll * d * (n - x.A) % mod * INV % mod);
		}
		else{
			cin >> v;
			cout << (gefen(stm[v]) + a[v]) % mod << endl;
		}
	}

	return 0;
}