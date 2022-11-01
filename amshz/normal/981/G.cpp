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
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, q, seg[xn << 2];
pii lazy[xn << 2], res;
set <pii> st[xn];
 
void build(int id = 1, int l = 1, int r = n + 1){
	lazy[id].A = 1;
	if (r - l == 1)
		return;
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
}
void shift(int id, int l, int r){
	seg[id] = (ll(seg[id]) * ll(lazy[id].A) % mod + ll(lazy[id].B) * ll(r - l) % mod) % mod;
	if (r - l > 1){
		lazy[lc].A = ll(lazy[lc].A) * ll(lazy[id].A) % mod;
		lazy[lc].B = (ll(lazy[lc].B) * ll(lazy[id].A) % mod + lazy[id].B) % mod;
		lazy[rc].A = ll(lazy[rc].A) * ll(lazy[id].A) % mod;
		lazy[rc].B = (ll(lazy[rc].B) * ll(lazy[id].A) % mod + lazy[id].B) % mod;
	}
	lazy[id] = {1, 0};
}
void update(int ql, int qr, int val, int id = 1, int l = 1, int r = n + 1){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		if (val == 0){
			lazy[id].A = ll(lazy[id].A) * 2LL % mod;
			lazy[id].B = ll(lazy[id].B) * 2LL % mod;
		}
		else
			lazy[id].B = (ll(lazy[id].B) + ll(val) + ll(mod)) % mod;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(ql, qr, val, lc, l, mid);
	update(ql, qr, val, rc, mid, r);
	seg[id] = (seg[lc] + seg[rc]) % mod;
}
int get(int ql, int qr, int id = 1, int l = 1, int r = n + 1){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return (get(ql, qr, lc, l, mid) + get(ql, qr, rc, mid, r)) % mod;
}
void add(pii x){
	update(max(x.A, res.A), min(x.B, res.B) + 1, - 1);
	update(max(x.A, res.A), min(x.B, res.B) + 1, 0);
	res.A = min(res.A, x.A), res.B = max(res.B, x.B);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> q;
	build();
	while (q --){
		int t, l, r, x;
		cin >> t;
		if (t == 1){
			cin >> l >> r >> x;
			update(l, r + 1, 1);
			res = {l, r};
			while (SZ(st[x])){
				if (st[x].lower_bound(res) == st[x].end()) break;
				pii y = *st[x].lower_bound(res);
				if (y.A > r) break;
				add(y), st[x].erase(y);
			}
		 	if (SZ(st[x]) && st[x].lower_bound(res) != st[x].begin()){
				pii y = *prev(st[x].lower_bound(res));
				if (y.B >= res.A) add(y), st[x].erase(y);
			}
			st[x].insert(res);
		}
		else{
			cin >> l >> r;
			cout << get(l, r + 1) << endl;
		}
	}
	
	return 0;
}