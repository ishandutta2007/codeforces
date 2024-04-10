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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

struct node{
	ll mn, mx, ab, ba, ans;
};

int n, q, a[xn], ptr, L[xn], R[xn], c[xn], par[xn];
ll W, last, H[xn], lazy[xn << 2];
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
		c[u.B] = u.A;
		par[u.A] = v;
		DFS(u.A);
		a[ptr ++] = v;
	}
	R[v] = ptr;
}
node merge(node v, node u){
	node w;
	w.mx = max(v.mx, u.mx);
	w.mn = min(v.mn, u.mn);
	w.ab = max(v.ab, u.ab);
	w.ab = max(w.ab, v.mx - u.mn * 2LL);
	w.ba = max(v.ba, u.ba);
	w.ba = max(w.ba, u.mx - v.mn * 2LL);
	w.ans = max(v.ans, u.ans);
	w.ans = max(w.ans, v.ab + u.mx);
	w.ans = max(w.ans, u.ba + v.mx);
	return w;
}
void build(int id, int l, int r){
	if (r - l == 1){
		seg[id].mn = seg[id].mx = H[a[l]];
		seg[id].ab = seg[id].ba = - H[a[l]];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = merge(seg[lc], seg[rc]);
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id].mn += lazy[id];
	seg[id].mx += lazy[id];
	seg[id].ab -= lazy[id];
	seg[id].ba -= lazy[id];
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, ll val){
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
	
	cin >> n >> q >> W;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		ll w;
		cin >> v >> u >> w;
		E[i] = {{v, u}, w};
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
	}
	DFS(1);
	build(1, 0, ptr);
	while (q --){
		int ind;
		ll w;
		cin >> ind >> w;
		ind = (ind + last) % (n - 1);
		w = (w + last) % W;
		update(1, 0, ptr, L[c[ind]], R[c[ind]], w - f(c[ind]) + f(par[c[ind]]));
		cout << seg[1].ans << endl;
		last = seg[1].ans;
	}
	
	return 0;
}