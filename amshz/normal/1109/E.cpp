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
typedef pair <ll, ll>                                    pll;
typedef pair <pll,  ll>                                  ppi;
typedef pair <ld , pii>                                  pip;
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
const int xm = 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, k, a[xn], b[xn], fen[xm][xn], phi;
int seg[xn << 2], lazy[xn << 2], md, sum[xn << 2];
bool prm[xn];

void calc_phi(){
    phi = md = mod;
    int t = mod;
    for (int i = 2; i * i <= t; ++ i){
        if (t % i)
			continue;
        while (t % i == 0)
			t /= i;
        phi -= phi / i;
    }
    if (t > 1)
		phi -= phi / t;
    -- phi;
}
void mofen(int id, int pos, int val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[id][pos] += val;
}
int gefen(int id, int pos){
	int res = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		res += fen[id][pos];
	return res;
}
void build(int id, int l, int r){
	seg[id] = lazy[id] = sum[id] = 1;
	if (r - l == 1){
		cin >> a[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	sum[id] = (sum[lc] + sum[rc]) % mod;
}
void update2(int id, int l, int r, int ql, int qr, int val){
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		seg[id] = 1ll * seg[id] * val % mod;
		return;
	}
	int mid = l + r >> 1;
	update2(lc, l, mid, ql, qr, val);
	update2(rc, mid, r, ql, qr, val);
}
int get2(int id, int l, int r, int pos){
	if (r - l == 1)
		return seg[id];
	int mid = l + r >> 1;
	if (pos < mid)
		return 1ll * seg[id] * get2(lc, l, mid, pos) % mod;
	return 1ll * seg[id] * get2(rc, mid, r, pos) % mod;
}
void shift(int id, int l, int r){
	if (lazy[id] == 1)
		return;
	sum[id] = 1ll * sum[id] * lazy[id] % mod;
	if (r - l > 1){
		lazy[lc] = 1ll * lazy[lc] * lazy[id] % mod;
		lazy[rc] = 1ll * lazy[rc] * lazy[id] % mod;
	}
	lazy[id] = 1;
}
void update1(int id, int l, int r, int ql, int qr, int val){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return;
	if (ql <= l && r <= qr){
		lazy[id] = 1ll * lazy[id] * val % mod;
		shift(id, l, r);
		return;
	}
	int mid = l + r >> 1;
	update1(lc, l, mid, ql, qr, val);
	update1(rc, mid, r, ql, qr, val);
	sum[id] = (sum[lc] + sum[rc]) % mod;
}
void modify(int id, int l, int r, int pos, int val){
	if (r - l == 1){
		sum[id] = val;
		return;
	}
	int mid = l + r >> 1;
	shift(lc, l, mid), shift(rc, mid, r);
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
	sum[id] = (sum[lc] + sum[rc]) % mod;
}
int get1(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return sum[id];
	int mid = l + r >> 1;
	return (get1(lc, l, mid, ql, qr) + get1(rc, mid, r, ql, qr)) % mod;
}
void query1(int l, int r, int x){
	//int l, r, x, y;
	//cin >> l >> r >> x;
	update1(1, 1, n + 1, l, r + 1, x);
	for (int i = 0; i < k; ++ i){
		int y = 0;
		while (x % b[i] == 0)
			++ y, x /= b[i];
		mofen(i, l, y);
		mofen(i, r + 1, - y);
	}
	update2(1, 1, n + 1, l, r + 1, x);
}

int main(){
	InTheNameOfGod;

	cin >> n >> mod, calc_phi();
	for (int i = 2; i < xn; ++ i){
		if (prm[i])
			continue;
		if (md % i == 0)
			b[k ++] = i;
		while (md % i == 0)
			md /= i;
	}
	if (md > 1)
		b[k ++] = md;
	build(1, 1, n + 1);
	for (int i = 1; i <= n; ++ i)
		query1(i, i, a[i]);
	cin >> q;
	while (q --){
		int t, l, r, x, y, ind, res;
		cin >> t;
		if (t == 1){
			cin >> l >> r >> x;
			query1(l, r, x);
		}
		else if (t == 2){
			cin >> ind >> x, res = 1;
			for (int i = 0; i < k; ++ i){
				y = 0;
				while (x % b[i] == 0)
					++ y, x /= b[i];
				mofen(i, ind, - y);
				mofen(i, ind + 1, y);
				res = 1ll * res * power(b[i], gefen(i, ind), mod) % mod;
			}
			update2(1, 1, n + 1, ind, ind + 1, power(x, phi, mod));
			res = 1ll * res * get2(1, 1, n + 1, ind) % mod;
			modify(1, 1, n + 1, ind, res);
		}
		else{
			cin >> l >> r;
			cout << get1(1, 1, n + 1, l, r + 1) << endl;
		}
	}

	return 0;
}