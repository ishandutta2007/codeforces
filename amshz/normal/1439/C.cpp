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

int n, q, a[xn], mx[xn << 2], mn[xn << 2], lazy[xn << 2];
ll seg[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		cin >> a[l];
		mn[id] = mx[id] = seg[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	mn[id] = min(mn[lc], mn[rc]);
	mx[id] = max(mx[lc], mx[rc]);
	seg[id] = seg[lc] + seg[rc];
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	mn[id] = mx[id] = lazy[id];
	seg[id] = 1ll * lazy[id] * (r - l);
	if (r - l > 1)
		lazy[lc] = lazy[rc] = lazy[id];
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql || val <= mn[id])
		return;
	if (ql <= l && r <= qr && mx[id] <= val){
		lazy[id] = val;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr, val);
	update(rc, mid, r, ql, qr, val);
	mx[id] = max(mx[lc], mx[rc]);
	mn[id] = min(mn[lc], mn[rc]);
	seg[id] = seg[lc] + seg[rc];
}
pii get(int id, int l, int r, int ql, int qr, pii val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql || mn[id] > val.A)
		return val;
	if (ql <= l && r <= qr && seg[id] <= val.A)
		return {val.A - seg[id], val.B + r - l};
	int mid = l + r >> 1;
	return get(rc, mid, r, ql, qr, get(lc, l, mid, ql, qr, val));
}

int main(){
	InTheNameOfGod;

	cin >> n >> q;
	build(1, 1, n + 1);
	while (q --){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
			update(1, 1, n + 1, 1, x + 1, y);
		else
			cout << get(1, 1, n + 1, x, n + 1, {y, 0}).B << endl;
	}

	return 0;
}