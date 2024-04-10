// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pll,  ll>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
 
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
 
const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, L, R, sz[xn], ck, mxh, ptr;
pii seg[xn << 2], last;
pip a[xn];
vector <pii> adj[xn];
vector <int> compress;
bool hide[xn];
 
void modify_mx(int pos, pii val){
	pos += n;
	for (seg[pos] = max(seg[pos], val); pos >>= 1;){
		if (seg[pos] >= val)
			return;
		seg[pos] = max(seg[pos << 1], seg[pos << 1 | 1]);
	}
}
void modify_eq(int pos, pii val){
	for (seg[pos += n] = val; pos >>= 1;){
		if (seg[pos] == val)
			return;
		seg[pos] = val;
	}
}
pii get(int l, int r){
	pii mx = {- inf, 0};
	for (l += n, r += n; l < r; l >>= 1, r >>= 1){
		if ((l & 1))
			mx = max(mx, seg[l ++]);
		if ((r & 1))
			mx = max(mx, seg[-- r]);
	}
	return mx;
}
void plant(int v, int p = - 1){
	sz[v] = 1;
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			plant(u.A, v), sz[v] += sz[u.A];
}
int find_centroid(int v, int s, int p = - 1){
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p && sz[u.A] * 2 > s)
			return find_centroid(u.A, s, v);
	return v;
}
int F(int x){
	if (x >= ck)
		return 1;
	else
		return - 1;
}
void get_paths(int v, int res, int h = 1, int p = - 1){
	if (last.A)
		return;
	pii x = get(max(0, L - h), max(0, R - h));
	if (res + x.A >= 0)
		last = {v, x.B};
	a[ptr ++] = {h, {res, v}};
	mxh = max(mxh, h);
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			get_paths(u.A, res + F(u.B), h + 1, v);
}
/*
void upd_paths(int v, int res, int h = 1, int p = - 1){
	modify_mx(h, {res, v}), mxh = max(mxh, h);
	for (pii u : adj[v])
		if (!hide[u.A] && u.A != p)
			upd_paths(u.A, res + F(u.B), h + 1, v);
}
*/
void solve(int v){
	if (last.A)
		return;
	plant(v);
	v = find_centroid(v, sz[v]);
	modify_mx(0, {0, v});
	hide[v] = true, mxh = 0;
	for (pii u : adj[v]){
		if (hide[u.A])
			continue;
		ptr = 0;
		get_paths(u.A, F(u.B));
		for (int i = 0; i < ptr; ++ i)
			modify_mx(a[i].A, a[i].B);
		//upd_paths(u.A, F(u.B));
	}
	for (int i = 0; i <= mxh; ++ i)
		modify_eq(i, {- inf, 0});
	for (pii u : adj[v])
		if (!hide[u.A])
			solve(u.A);
}
bool check(int x){
	memset(hide, false, sizeof hide);
	for (int i = 0; i < n; ++ i)
		modify_eq(i, {- inf, 0});
	last = {0, 0}, ck = x;
	solve(1);
	return (last.A > 0);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> L >> R, ++ R;
	for (int i = 0; i < n - 1; ++ i){
		int v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
		compress.push_back(w);
	}
	sort(all(compress));
	int l = 0, r = SZ(compress);
	while (r - l > 1){
		int mid = l + r >> 1;
		if (check(compress[mid]))
			l = mid;
		else
			r = mid;
	}
	check(compress[l]);
	cout << last.A << sep << last.B << endl;
			
	return 0;
}