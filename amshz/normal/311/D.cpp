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

const int xn = 1e5 + 10;
const int xm = 48;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 95542721;//998244353;
const int base = 257;

int n, q, seg[xn << 2][xm], lst[xm], lazy[xn << 2];

void build(int id, int l, int r){
	if (r - l == 1){
		cin >> seg[id][0], seg[id][0] %= mod;
		for (int i = 1; i < xm; ++ i)
			seg[id][i] = 1ll * seg[id][i - 1] * seg[id][i - 1] % mod * seg[id][i - 1] % mod;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	for (int i = 0; i < xm; ++ i)
		seg[id][i] = (seg[lc][i] + seg[rc][i]) % mod;
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	for (int i = 0; i < xm; ++ i)
		lst[i] = seg[id][i];
	for (int i = 0; i < xm; ++ i)
		seg[id][i] = lst[(i + lazy[id]) % xm];
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		++ lazy[id];
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, ql, qr);
	update(rc, mid, r, ql, qr);
	for (int i = 0; i < xm; ++ i)
		seg[id][i] = (seg[lc][i] + seg[rc][i]) % mod;
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id][0];
	int mid = l + r >> 1;
	return (get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr)) % mod;
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	build(1, 1, n + 1);
	cin >> q;
	while (q --){
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
			cout << get(1, 1, n + 1, l, r + 1) << endl;
		else
			update(1, 1, n + 1, l, r + 1);
	}

	return 0;
}