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

const int xn = 2e5 + 10;
const int xm = 18;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, q, a[xn], H[xn], dp[xn], ptr, TM, seg[xn << 2];
int par[xm][xn], sz[xn], hd[xn], stm[xn], hvy[xn];
stack <int> sk;
set <pii> st[xn];
vector <int> G[xn], adj[xn];
bool mark[xn];

void preDFS(int v, int p = - 1){
	mark[v] = true;
	sk.push(v);
	dp[v] = H[v];
	for (int u : G[v]){
		if (mark[u]){
			dp[v] = min(dp[v], H[u]);
			continue;
		}
		H[u] = H[v] + 1;
		preDFS(u, v);
		dp[v] = min(dp[v], dp[u]);
	}
	if (dp[v] < H[v] - 1 || v == 1)
		return;
	++ ptr;
	while (true){
		int u = sk.top();
		sk.pop();
		adj[u].push_back(ptr);
		adj[ptr].push_back(u);
		if (u == v)
			break;
	}
	adj[p].push_back(ptr);
	adj[ptr].push_back(p);
}
void DFS(int v){
	for (int i = 1; i < xm; ++ i)
		par[i][v] = par[i - 1][par[i - 1][v]];
	sz[v] = 1;
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		par[0][u] = v;
		H[u] = H[v] + 1;
		DFS(u);
		sz[v] += sz[u];
		if (sz[hvy[v]] < sz[u])
			hvy[v] = u;
	}
}
void HLDFS(int v){
	stm[v] = TM ++;
	hd[v] = v;
	if (hvy[par[0][v]] == v)
		hd[v] = hd[par[0][v]];
	if (hvy[v])
		HLDFS(hvy[v]);
	for (int u : adj[v])
		if (u != par[0][v] && u != hvy[v])
			HLDFS(u);
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
	seg[id] = min(seg[lc], seg[rc]);
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return inf;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return min(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
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

int main(){
	fast_io;

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 0; i < m; ++ i){
		int v, u;
		cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	ptr = n;
	preDFS(1);
	H[1] = 0;
	H[0] = - 1;
	DFS(1);
	HLDFS(1);
	fill(seg, seg + (xn << 2), inf);
	for (int v = 2; v <= n; ++ v)
		st[par[0][v]].insert({a[v], v});
	for (int i = n + 1; i <= ptr; ++ i)
		st[i].insert({inf, - 1}), a[i] = (st[i].begin() -> A);
	for (int i = 1; i <= ptr; ++ i)
		modify(1, 0, TM, stm[i], a[i]);
	a[0] = inf;
	while (q --){
		char c;
		int v, u, w;
		cin >> c >> v;
		if (c == 'C'){
			cin >> w;
			modify(1, 0, TM, stm[v], w);
			st[par[0][v]].erase({a[v], v});
			a[v] = w;
			st[par[0][v]].insert({a[v], v});
			a[par[0][v]] = st[par[0][v]].begin() -> A;
			modify(1, 0, TM, stm[par[0][v]], a[par[0][v]]);
		}
		else{
			cin >> u;
			int ans = inf;
			int lca = LCA(v, u);
			while (H[lca] <= H[hd[v]])
				ans = min(ans, get(1, 0, TM, stm[hd[v]], stm[v] + 1)), v = par[0][hd[v]];
			ans = min(ans, get(1, 0, TM, stm[lca], stm[v] + 1));
			while (H[lca] <= H[hd[u]])
				ans = min(ans, get(1, 0, TM, stm[hd[u]], stm[u] + 1)), u = par[0][hd[u]];
			ans = min(ans, get(1, 0, TM, stm[lca], stm[u] + 1));
			if (n < lca)
				ans = min(ans, a[par[0][lca]]);
			cout << ans << endl;
		}
	}

	return 0;
}