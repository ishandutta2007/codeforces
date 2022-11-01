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
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, H[xn], L[xn], R[xn], ptr, a[xn], b[xn], ans[xn];
int P[xn], seg[xn << 2], par[xm][xn], lazy[xn << 2];
vector <int> adj[xn];
vector <pair <int, pii> > vec[2][xn];

void DFS(int v){
	P[ptr] = v;
	L[v] = ptr ++;
	R[v] = ptr;
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		H[u] = H[v] + 1;
		par[0][u] = v;
		DFS(u);
		R[v] = R[u];
	}
}
int LCA(int v, int u){
	if (H[v] > H[u])
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
int find_par(int v, int h){
	for (int i = xm - 1; i >= 0; -- i)
		if ((1 << i) <= h)
			v = par[i][v], h -= (1 << i);
	return v;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = H[P[l]];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] += lazy[id];
	if (r - l > 1){
		lazy[id << 1] += lazy[id];
		lazy[id << 1 | 1] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] += val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(id << 1, l, mid, ql, qr, val);
	update(id << 1 | 1, mid, r, ql, qr, val);
	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(id << 1, l, mid, ql, qr), get(id << 1 | 1, mid, r, ql, qr));
}
void DFS2(int v){
	for (pair <int, pii> x : vec[0][v])
		ans[x.A] = max(ans[x.A], get(1, 0, n, x.B.A, x.B.B));
	for (pair <int, pii> x : vec[1][v]){
		ans[x.A] = max(ans[x.A], get(1, 0, n, 0, x.B.A));
		ans[x.A] = max(ans[x.A], get(1, 0, n, x.B.B, n));
	}
	for (int u : adj[v]){
		if (u == par[0][v])
			continue;
		update(1, 0, n, 0, n, 1);
		update(1, 0, n, L[u], R[u], - 2);
		DFS2(u);
		update(1, 0, n, 0, n, - 1);
		update(1, 0, n, L[u], R[u], 2);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= n; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	cin >> m;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		if (H[v] > H[u])
			swap(v, u);
		int lca = LCA(v, u);
		int d = H[v] + H[u] - 2 * H[lca];
		d = (d + 1) / 2 - 1;
		int x = find_par(u, d);
		vec[0][u].push_back({i, {L[x], R[x]}});
		vec[1][v].push_back({i, {L[x], R[x]}});
	}
	build(1, 0, n);
	DFS2(1);
	for (int i = 1; i <= m; ++ i)
		cout << ans[i] << endl;
	
	return 0;
}