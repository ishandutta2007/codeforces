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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define md                                              (l + r >> 1)
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
//ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;
 
int n, k, seg[xn << 2], ptr, col[xm][xn], m, q, a[xn];
int par[xn * xm], sz[xn * xm], Par[xn * xm], Sz[xn * xm];
vector <int> adj[xn];
 
int get_root(int v){
	if (v == par[v])
		return v;
	return par[v] = get_root(par[v]);
}
int get_Root(int v){
	if (v == Par[v])
		return v;
	return Par[v] = get_Root(Par[v]);
}
void build(int id, int l, int r, int h){
	for (int i = l; i < r; ++ i){
		col[h][i] = ++ ptr;
		par[ptr] = ptr;
		sz[ptr] = 1;
	}
	seg[id] = r - l;
	if (r - l == 1)
		return;
	for (int i = l; i < r; ++ i){
		for (int j : adj[i]){
			if (j >= r)
			 	continue;
			int v = get_root(col[h][i]);
			int u = get_root(col[h][j]);
			if (v == u)
			 	continue;
			if (sz[v] < sz[u])
				swap(v, u);
			par[u] = v;
			sz[v] += sz[u];
			-- seg[id];
		}
	}
	for (int i = l; i < r; ++ i)
		par[col[h][i]] = get_root(col[h][i]);
	build(lc, l, md, h + 1), build(rc, md, r, h + 1);
}
void build_get(int id, int l, int r, int ql, int qr, int h){
	if (qr <= l || r <= ql)
		return;
	if (ql <= l && r <= qr){
		for (int i = l; i < min(r, l + k); ++ i){
			Par[col[h][i]] = par[col[h][i]];
			Sz[col[h][i]] = sz[par[col[h][i]]];
			Par[Par[col[h][i]]] = Par[col[h][i]];
			a[i] = h;
		}
		for (int i = max(r - k, l); i < r; ++ i){
			Par[col[h][i]] = par[col[h][i]];
			Sz[col[h][i]] = sz[par[col[h][i]]];
			Par[par[col[h][i]]] = Par[col[h][i]];
			a[i] = h;
		}
		return;
	}
	build_get(lc, l, md, ql, qr, h + 1);
	build_get(rc, md, r, ql, qr, h + 1);
}
int get(int id, int l, int r, int ql, int qr, int h){
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int ans = get(lc, l, md, ql, qr, h + 1);
	ans += get(rc, md, r, ql, qr, h + 1);
	if (ql >= md || qr <= md)
		return ans;
	for (int i = max(max(l, ql), md - k); i < md; ++ i){
		for (int j : adj[i]){
			if (j < md || j >= min(r, qr))
				continue;
			int v = get_Root(col[a[i]][i]);
			int u = get_Root(col[a[j]][j]);
			if (v == u)
				continue;
			-- ans;
			if (Sz[v] < Sz[u])
				swap(v, u);
			Par[u] = v;
			Sz[v] += Sz[u];
		}
	}
	return ans;
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> k >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		if (v > u)
			swap(v, u);
		adj[v].push_back(u);
	}
	build(1, 1, n + 1, 0);
	cin >> q;
	while (q --){
		int l, r;
		cin >> l >> r;
		build_get(1, 1, n + 1, l, r + 1, 0);
		cout << get(1, 1, n + 1, l, r + 1, 0) << endl;
	}
	
	return 0;
}