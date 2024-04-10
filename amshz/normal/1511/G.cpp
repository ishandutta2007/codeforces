// khodaya khodet komak kon
// Maybe on the Moon
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

const int xn = 5e5 + 10;
const int xm = 18;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], q, seg[xm][xn << 2], ans[xn][xm], cnt[xn], m;
vector <pii> query[xn];

void update(int id, int l, int r, int bit, int ql, int qr){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[bit][id] ^= 1;
		return;
	}
	int mid = l + r >> 1;
	update(lc, l, mid, bit, ql, qr);
	update(rc, mid, r, bit, ql, qr);
}
int get(int id, int l, int r, int bit, int pos){
	if (pos >= xn)
		return 0;
	if (r - l == 1)
		return seg[bit][id];
	int mid = l + r >> 1;
	if (pos < mid)
		return seg[bit][id] ^ get(lc, l, mid, bit, pos);
	return seg[bit][id] ^ get(rc, mid, r, bit, pos);
}

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], cnt[a[i]] ^= 1;
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int l, r;
		cin >> l >> r;
		query[r].push_back({l, i});
		query[l].push_back({l, i});
	}
	for (int i = 1; i <= m; ++ i){
		int res = 0;
		if (cnt[i]){
			for (int bit = 0; bit < xm; ++ bit){
				if ((i & (1 << bit))){
					update(1, 0, xn, bit, 0, res + 1);
					int x = (1 << bit) - (res + 1);
					update(1, 0, xn, bit, (1 << (bit + 1)) - x, xn);
				}
				else
					update(1, 0, xn, bit, res + 1, res + (1 << bit) + 1);
				res += (i & (1 << bit));
			}
		}
		for (pii x : query[i])
			for (int bit = 0; bit < xm; ++ bit)
				ans[x.B][bit] ^= get(1, 0, xn, bit, x.A % (1 << (bit + 1)));
	}
	for (int i = 1; i <= q; ++ i){
		int res = 0;
		for (int bit = 0; bit < xm; ++ bit)
			res += ans[i][bit];
		if (res)
			cout << 'A';
		else
			cout << 'B';
	}
	cout << endl;

	return 0;
}