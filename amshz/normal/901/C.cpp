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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, q, ps[xn], H[xn], par[xn];
ll seg[xn << 2], lazy[xn << 2], ans[xn];
bool mark[xn];
vector <int> adj[xn];
vector <pii> Q[xn];

void DFS(int v){
	mark[v] = true;
	for (int u : adj[v]){
		if (u == par[v])
			continue;
		if (mark[u]){
			if (H[u] < H[v]){
				int mn = v, mx = v, w = v;
				while (w != u){
					w = par[w];
					mn = min(mn, w);
					mx = max(mx, w);
				}
				ps[mn] = min(ps[mn], mx);
			}
			continue;
		}
		H[u] = H[v] + 1;
		par[u] = v;
		DFS(u);
	}
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += 1ll * (r - l) * lazy[id];
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
	return (get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr));
}

int main(){
	fast_io;

	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	fill(ps, ps + n + 2, n + 1);
	for (int i = 1; i <= n; ++ i)
		if (!mark[i])
			DFS(i);
	cin >> q;
	for (int i = 0; i < q; ++ i){
		int l, r;
		cin >> l >> r;
		Q[l].push_back({r, i});
	}
	for (int i = n; 1 <= i; -- i){
		ps[i] = min(ps[i], ps[i + 1]);
		update(1, 1, n + 1, i, ps[i], 1);
		for (pii x : Q[i])
			ans[x.B] = get(1, 1, n + 1, i, x.A + 1);
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;

	return 0;
}