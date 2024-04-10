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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

struct node{
	int mn, mx[2], ab[2], ba[2], ans;
};

int n, q, a[xn], ptr, L[xn], R[xn], c[xn], par[xn];
int H[xn], lazy[xn << 2], dist[xn];
pair <pii, ll> E[xn];
vector <pii> adj[xn];
node seg[xn << 2];

void DFS(int v){
	L[v] = ptr;
	a[ptr ++] = v;
	for (pii u : adj[v]){
		if (u.A == par[v])
			continue;
		H[u.A] = H[v] + E[u.B].B;
		dist[u.A] = dist[v] + 1;
		c[u.B] = u.A;
		par[u.A] = v;
		DFS(u.A);
		a[ptr ++] = v;
	}
	R[v] = ptr;
}
node merge(node v, node u){
	node w;
	w.mn = min(v.mn, u.mn);
	w.ans = max(v.ans, u.ans);
	for (int i = 0; i < 2; ++ i){
		w.mx[i] = max(v.mx[i], u.mx[i]);
		w.ab[i] = max(v.ab[i], u.ab[i]);
		w.ab[i] = max(w.ab[i], v.mx[i] - u.mn * 2);
		w.ba[i] = max(v.ba[i], u.ba[i]);
		w.ba[i] = max(w.ba[i], u.mx[i] - v.mn * 2);
		w.ans = max(w.ans, v.ab[i] + u.mx[i]);
		w.ans = max(w.ans, u.ba[i] + v.mx[i]);
	}
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].mn = seg[id].mx[H[a[l]] % 2] = dist[a[l]];
		seg[id].mx[1 - H[a[l]] % 2] = - inf;
		seg[id].ab[H[a[l]] % 2] = seg[id].ba[H[a[l]] % 2] = - dist[a[l]];
		seg[id].ab[1 - H[a[l]] % 2] = seg[id].ba[1 - H[a[l]] % 2] = - inf;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = merge(seg[lc], seg[rc]);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	swap(seg[id].mx[0], seg[id].mx[1]);
	swap(seg[id].ab[0], seg[id].ab[1]);
	swap(seg[id].ba[0], seg[id].ba[1]);
	if (r - l > 1){
		lazy[lc] ^= 1;
		lazy[rc] ^= 1;
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] ^= 1;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr);
	update(rc, mid, r, ql, qr);
	seg[id] = merge(seg[lc], seg[rc]);
}
ll get(int id, int l, int r, int pos){
	shift(id, l, r);
	if (r - l == 1)
		return seg[id].mn;
	int mid = l + r >> 1;
	if (pos < mid)
		get(lc, l, mid, pos);
	else
		get(rc, mid, r, pos);
}
ll f(int v){
	if (!v)
		return 0;
	return get(1, 0, ptr, L[v]);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i < n; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		E[i] = {{v, u}, w};
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	DFS(1);
	build(1, 0, ptr);
	cin >> q;
	while (q --){
		int ind;
		cin >> ind;
		update(1, 0, ptr, L[c[ind]], R[c[ind]]);
		cout << seg[1].ans << endl;
	}
	
	return 0;
}