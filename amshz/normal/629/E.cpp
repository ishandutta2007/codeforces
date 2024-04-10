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

const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, stm[xn], ftm[xn], H[xn], TM, sz[xn], par[xm][xn];
vector <int> adj[xn];
vector <pii> Q[xn];
ll dp[xn], seg[xn << 2], lazy[xn << 2];
pll ans[xn], ted[xn];
pii a[xn];

void preDFS(int v){
	stm[v] = TM ++;
	dp[v] = H[v];
	sz[v] = 1;
	for (int i = 1; i < xm; ++ i)
		par[i][v] = par[i - 1][par[i - 1][v]];
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		H[u] = H[v] + 1;
		par[0][u] = v;
		preDFS(u);
		dp[v] += dp[u];
		sz[v] += sz[u];
	}
	ftm[v] = TM;
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += lazy[id] * (r - l);
	if (1 < r - l){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	seg[id] = seg[lc] + seg[rc];
}
ll get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr);
}
void DFS(int v){
	for (pii x : Q[v])
		ans[x.B].B = seg[1] - get(1, 0, n, stm[x.A], ftm[x.A]);
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		update(1, 0, n, 0, n, 1);
		update(1, 0, n, stm[u], ftm[u], - 2);
		DFS(u);
		update(1, 0, n, 0, n, - 1);
		update(1, 0, n, stm[u], ftm[u], 2);
	}
}
int LCA(int v, int u){
	if (H[u] < H[v])
		swap(v, u);
	for (int i = xm - 1; 0 <= i; -- i)
		if ((1 << i) <= H[u] - H[v])
			u = par[i][u];
	if (v == u)
		return v;
	for (int i = xm - 1; 0 <= i; -- i)
		if (par[i][v] != par[i][u])
			v = par[i][v], u = par[i][u];
	return par[0][v];
}
int dist(int v, int u){
	return H[v] + H[u] - 2 * H[LCA(v, u)];
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 1; i < n; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	preDFS(1);
	for (int i = 2; i <= n; ++ i)
		update(1, 0, n, stm[i], ftm[i], 1);
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		a[i] = {v, u};
		if (stm[u] < stm[v])
			swap(v, u);
		if (ftm[v] < ftm[u]){
			ll x = dp[v] - 1ll * H[v] * sz[v];
			ll y = dp[u] - 1ll * H[u] * sz[u];
			ans[i] = {x, y};
			ted[i] = {sz[v], sz[u]};
		}
		else{
			int res = u;
			for (int i = xm - 1; 0 <= i; -- i)
				if (H[v] < H[par[i][res]])
					res = par[i][res];
			ans[i].A = dp[u] - 1ll * H[u] * sz[u];
			ted[i] = {sz[u], n - sz[res]};
			Q[v].push_back({res, i});
		}
	}
	DFS(1);
	cout << fixed << setprecision(9);
	for (int i = 1; i <= m; ++ i){
		ld res = ans[i].A * ted[i].B;
		res += ans[i].B * ted[i].A;
		res /= ld(ted[i].A * ted[i].B);
		res += dist(a[i].A, a[i].B) + 1;
		cout << res << endl;
	}

	return 0;
}