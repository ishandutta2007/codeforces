// khodaya khodet komak kon
// Nightcall - London Grammer
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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, lazy[xn << 2], stm[xn], ftm[xn], TM, sz[xn], a[xn];
ll c[xn];
pii mx[xn << 2], mn[xn << 2];
vector <int> adj[xn];
set <int> st;

void DFS(int v, int p = - 1){
	stm[v] = TM ++;
	sz[v] = 1;
	for (int u : adj[v]){
		if (u == p)
			continue;
		if (v)
			a[u] = a[v];
		else
			a[u] = u;
		DFS(u, v);
		sz[v] += sz[u];
	}
	ftm[v] = TM;
}
void build(int id, int l, int r){
	mx[id] = mn[id] = {0, r - l};
	lazy[id] = 0;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	mx[id].A += lazy[id];
	mn[id].A += lazy[id];
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		++ lazy[id];
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr);
	update(rc, mid, r, ql, qr);
	mx[id].A = max(mx[lc].A, mx[rc].A);
	mx[id].B = 0;
	if (mx[lc].A == mx[id].A)
		mx[id].B += mx[lc].B;
	if (mx[rc].A == mx[id].A)
		mx[id].B += mx[rc].B;
	mn[id].A = min(mn[lc].A, mn[rc].A);
	mn[id].B = 0;
	if (mn[lc].A == mn[id].A)
		mn[id].B += mn[lc].B;
	if (mn[rc].A == mn[id].A)
		mn[id].B += mn[rc].B;
}
pii get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return {- 1, 0};
	if (ql <= l && r <= qr)
		return mx[id];
	int mid = l + r >> 1;
	pii x = get(lc, l, mid, ql, qr);
	pii y = get(rc, mid, r, ql, qr);
	pii z;
	z.A = max(x.A, y.A);
	z.B = 0;
	if (x.A == z.A)
		z.B += x.B;
	if (y.A == z.A)
		z.B += y.B;
	return z;
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 0; i < n; ++ i)
			adj[i].clear();
		for (int i = 1; i < n; ++ i){
			int v, u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		c[0] = 1ll * n * (n - 1) / 2, c[1] = 0;
		TM = 0, DFS(0), build(1, 0, n);
		for (int u : adj[0])
			c[1] += 1ll * sz[u] * (sz[u] - 1) / 2;
		c[1] = c[0] - c[1];
		st.clear();
		for (int v = 1; v < n; ++ v){
			update(1, 0, n, stm[v], ftm[v]);
			update(1, 0, n, stm[a[v]], ftm[a[v]]);
			st.insert(a[v]);
			if (SZ(st) == 1){
				ll x = mx[1].B, y = mn[1].B;
				if (mx[1].A != v + v)
					x = 0;
				if (mn[1].A != 0)
					y = 0;
				c[v + 1] = x * y;
			}
			else if (SZ(st) == 2){
				int V = *st.begin();
				st.erase(V);
				int u = *st.begin();
				st.insert(V);
				pii X = get(1, 0, n, stm[V], ftm[V]);
				pii Y = get(1, 0, n, stm[u], ftm[u]);
				ll x = X.B;
				ll y = Y.B;
				if (X.A + Y.A != v + v)
					x = 0; 
				c[v + 1] = x * y;
			}
			else
				c[v + 1] = 0;
		}
		c[n + 1] = 0;
		for (int i = 0; i <= n; ++ i)
			cout << c[i] - c[i + 1] << sep;
		cout << endl;
	}

	return 0;
}
/*
1
4
0 1
0 2
2 3
*/