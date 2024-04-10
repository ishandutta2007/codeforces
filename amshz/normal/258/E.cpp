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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, stm[xn], ftm[xn], TM, ans[xn];
int cnt[xn << 2], lazy[xn << 2], sum[xn << 2];
pii seg[xn << 2];
vector <int> adj[xn], Q[xn];

void preDFS(int v, int p = - 1){
	stm[v] = TM ++;
	for (int u : adj[v])
		if (u != p)
			preDFS(u, v);
	ftm[v] = TM;
}
void build(int id, int l, int r){
	seg[id].B = r - l;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id].A += lazy[id];
	sum[id] = r - l;
	if (!seg[id].A)
		sum[id] -= seg[id].B;
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
	seg[id] = {min(seg[lc].A, seg[rc].A), 0};
	if (seg[lc].A == seg[id].A)
		seg[id].B += seg[lc].B;
	if (seg[rc].A == seg[id].A)
		seg[id].B += seg[rc].B;
	sum[id] = r - l;
	if (!seg[id].A)
		sum[id] -= seg[id].B;
}
void DFS(int v, int p = - 1){
	for (int u : Q[v])
		update(1, 0, TM, stm[u], ftm[u], 1);
	ans[v] = sum[1];
	if (ans[v])
		-- ans[v];
	for (int u : adj[v])
		if (u != p)
			DFS(u, v);
	for (int u : Q[v])
		update(1, 0, TM, stm[u], ftm[u], - 1);
}

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	preDFS(1);
	while (m --){
		int v, u;
		cin >> v >> u;
		Q[v].push_back(v);
		Q[v].push_back(u);
		Q[u].push_back(v);
		Q[u].push_back(u);
	}
	build(1, 0, TM);
	DFS(1);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;

	return 0;
}