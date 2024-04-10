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
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
const int xm = 32;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, q, a[xn][xm], seg[xn << 2][xm], b[xm], ans;

void build(int id, int l, int r){
	if (r - l == 1){
		for (int j = 0; j < k; ++ j)
			cin >> a[l][j];
		for (int mask = 0; mask < (1 << k); ++ mask){
			for (int j = 0; j < k; ++ j){
				if ((mask & (1 << j)))
					seg[id][mask] += a[l][j];
				else
					seg[id][mask] -= a[l][j];
			}
		}
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	for (int mask = 0; mask < (1 << k); ++ mask)
		seg[id][mask] = max(seg[lc][mask], seg[rc][mask]);
}
void modify(int id, int l, int r, int pos){
	if (r - l == 1){
		for (int j = 0; j < k; ++ j)
			cin >> a[l][j];
		for (int mask = 0; mask < (1 << k); ++ mask){
			seg[id][mask] = 0;
			for (int j = 0; j < k; ++ j){
				if ((mask & (1 << j)))
					seg[id][mask] += a[l][j];
				else
					seg[id][mask] -= a[l][j];
			}
		}
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos);
	else
		modify(rc, mid, r, pos);
	for (int mask = 0; mask < (1 << k); ++ mask)
		seg[id][mask] = max(seg[lc][mask], seg[rc][mask]);
}
void get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		for (int mask = 0; mask < (1 << k); ++ mask)
			b[mask] = max(b[mask], seg[id][mask]);
		return;
	}
	int mid = l + r >> 1;
	get(lc, l, mid, ql, qr);
	get(rc, mid, r, ql, qr);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	build(1, 1, n + 1);
	cin >> q;
	while (q --){
		int t, l, r, x;
		cin >> t;
		if (t == 1){
			cin >> x;
			modify(1, 1, n + 1, x);
		}
		else{
			cin >> l >> r;
			for (int mask = 0; mask < (1 << k); ++ mask)
				b[mask] = - inf;
			ans = - inf;
			get(1, 1, n + 1, l, r + 1);
			for (int mask = 0; mask < (1 << k); ++ mask)
				ans = max(ans, b[mask] + b[(1 << k) - mask - 1]);
			cout << ans << endl;
		}
	}
	
	return 0;
}