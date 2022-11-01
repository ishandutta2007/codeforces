//khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
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
# define rc                                              lc | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1.3e6 + 10;
const int xm = 12 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, q, lcp[xn], m, col[xn], pw, P[xn], rnk[xm][xn], w[xn];
int seg[xn << 2], ptr, a[xn], S[xn], f[xn], par[xm][xn];
pii b[xn], mx[xn << 2], ans[xn];
string s, t[xn];
vector <int> vec[xn << 2], V[xn], adj[xn];
vector <ppi> query[xn];

bool cmp(int i, int j){
	if (rnk[pw - 1][i] != rnk[pw - 1][j])
		return rnk[pw - 1][i] < rnk[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > m)
		return i > j;
	return rnk[pw - 1][(1 << (pw - 1)) + i] < rnk[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
	for (int i = 1; i <= m; ++ i)
		rnk[0][i] = S[i], P[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + m + 1, cmp);
		rnk[pw][P[1]] = 1;
		for (int i = 2; i <= m; ++ i)
			rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (rnk[i][x] != rnk[i][y])
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = lcp[l];
		vec[id].push_back(l);
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	if (seg[lc] <= seg[rc])
		for (int x : vec[lc])
			vec[id].push_back(x);
	if (seg[rc] <= seg[lc])
		for (int x : vec[rc])
			vec[id].push_back(x);
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
void findmin(int id, int l, int r, int ql, int qr, int val, int ind){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		if (seg[id] > val)
			return;
		for (int x : vec[id])
			V[ind].push_back(x);
		return;
	}
	int mid = l + r >> 1;
	findmin(lc, l, mid, ql, qr, val, ind);
	findmin(rc, mid, r, ql, qr, val, ind);
}
void suff_tree(int id, int l, int r){
	b[id] = {l, r};
	if (l == r){
		if (a[P[l]] > - inf && a[P[l]] <= 0)
			f[- a[P[l]]] = id;
		else if (a[P[l]] > 0)
			col[l] = a[P[l]];
		return;
	}
	w[id] = get(1, 1, m, l, r);
	findmin(1, 1, m, l, r, w[id], id);
	V[id].push_back(r);
	int last = l;
	for (int x : V[id]){
		int u = ++ ptr;
		par[0][u] = id;
		adj[id].push_back(u);
		suff_tree(u, last, x);
		last = x + 1;
	}
}
pii Max(pii i, pii j){
	if (i.A != j.A)
		return max(i, j);
	return min(i, j);
}
void Build(int id, int l, int r){
	if (r - l == 1){
		mx[id].B = l;
		return;
	}
	int mid = l + r >> 1;
	Build(lc, l, mid), Build(rc, mid, r);
	mx[id] = Max(mx[lc], mx[rc]);
}
void modify(int id, int l, int r, int pos, int val){
	if (!pos)
		return;
	if (r - l == 1){
		mx[id].A += val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
	mx[id] = Max(mx[lc], mx[rc]);
}
pii get3(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return {0, n};
	if (ql <= l && r <= qr)
		return mx[id];
	int mid = l + r >> 1;
	return Max(get3(lc, l, mid, ql, qr), get3(rc, mid, r, ql, qr));
}
void DFS(int v){
	int arshad = 0;
	for (int u : adj[v])
		if (b[u].B - b[u].A > b[arshad].B - b[arshad].A)
			arshad = u;
	for (int u : adj[v]){
		if (u == arshad)
			continue;
		DFS(u);
		for (int i = b[u].A; i <= b[u].B; ++ i)
			modify(1, 1, n + 1, col[i], - 1);
	}
	if (arshad)
		DFS(arshad);
	for (int u : adj[v]){
		if (u == arshad)
			continue;
		for (int i = b[u].A; i <= b[u].B; ++ i)
			modify(1, 1, n + 1, col[i], 1);
	}
	if (b[v].A == b[v].B)
		modify(1, 1, n + 1, col[b[v].A], 1);
	for (ppi x : query[v])
		ans[x.B] = get3(1, 1, n + 1, x.A.A, x.A.B + 1);
}

int main(){
	InTheNameOfGod;
	
	cin >> s;
	for (int i = 0; i < SZ(s); ++ i)
		S[++ m] = s[i], a[m] = - i - 1;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> t[i];
		S[++ m] = a[m] = - i - inf;
		for (int j = 0; j < SZ(t[i]); ++ j)
			S[++ m] = t[i][j], a[m] = i;
	}
	buildSA();
	for (int i = 1; i < m; ++ i)
		lcp[i] = LCP(P[i], P[i + 1]);
	build(1, 1, m);
	suff_tree(++ ptr, 1, m);
	for (int i = 1; i < xm; ++ i)
		for (int v = 1; v <= ptr; ++ v)
			par[i][v] = par[i - 1][par[i - 1][v]];
	cin >> q;
	for (int i = 0; i < q; ++ i){
		int l, r, l2, r2;
		cin >> l >> r >> l2 >> r2;
		int v = f[l2];
		for (int i = xm - 1; i >= 0; -- i)
			if (w[par[i][v]] > r2 - l2)
				v = par[i][v];
		query[v].push_back({{l, r}, i});
	}
	Build(1, 1, n + 1);
	DFS(1);
	for (int i = 0; i < q; ++ i)
		cout << ans[i].B << sep << ans[i].A << endl;
	
	return 0;
}