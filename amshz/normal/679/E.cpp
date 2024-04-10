//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize("O2")
 
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
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const ll inf = 1e18 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, q, a[xn], val[xn << 2], mn[xn << 2];
pll lazy[xn << 2];

ll F(ll x){
	ll res = 1;
	while (res < x)
		res *= 42LL;
	return res - x;
}
void build(int id, int l, int r){
	if (r - l == 1){
		cin >> a[l];
		val[id] = a[l];
		mn[id] = F(a[l]);
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	val[id] = 0;
	if (val[lc] == val[rc])
		val[id] = val[rc];
	mn[id] = min(mn[lc], mn[rc]);
}
void shift(int id, int l, int r){
	if (lazy[id].A){
		val[id] = lazy[id].B;
		mn[id] = F(lazy[id].B);
	}
	else{
		if (val[id]){
			val[id] += lazy[id].B;
			mn[id] = F(val[id]);
		}
		else
			mn[id] -= lazy[id].B;
	}
	if (r - l > 1){
		if (lazy[id].A)
			lazy[lc] = lazy[rc] = lazy[id];
		else{
			lazy[lc].B += lazy[id].B;
			lazy[rc].B += lazy[id].B;
		}
	}
	lazy[id] = {0, 0};
}
void update(int id, int l, int r, int ql, int qr, ll x, int t){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr && (val[id] || mn[id] >= x || t == 2)){
		if (t == 2)
			lazy[id] = {1, x};
		else
			lazy[id].B += x;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, x, t);
	update(rc, mid, r, ql, qr, x, t);
	val[id] = 0;
	if (val[lc] == val[rc])
		val[id] = val[rc];
	mn[id] = min(mn[lc], mn[rc]);
}
ll get(int id, int l, int r, int pos){
	shift(id, l, r);
	if (r - l == 1)
		return val[id];
	int mid = l + r >> 1;
	if (pos < mid)
		return get(lc, l, mid, pos);
	return get(rc, mid, r, pos);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> q;
	build(1, 1, n + 1);
	while (q --){
		ll t, l, r, x;
		cin >> t;
		if (t == 1){
			cin >> x;
			cout << get(1, 1, n + 1, x) << endl;
		}
		else if (t == 2){
			cin >> l >> r >> x;
			update(1, 1, n + 1, l, r + 1, x, 2);
		}
		else{
			cin >> l >> r >> x;
			update(1, 1, n + 1, l, r + 1, x, 3);
			while (!mn[1])
				update(1, 1, n + 1, l, r + 1, x, 3);
		}
	}
	
	return 0;
}