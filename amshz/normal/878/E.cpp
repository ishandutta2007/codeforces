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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 2e9 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, seg[xn << 2], lazy[xn << 2];
int pw[xn], pt, a[xn], ans[xn], inv[xn];
pair <pii, ll> sk[xn];
vector <pii> query[xn];

void bld(int id, int l, int r){
	if (r - l == 1){
		cin >> a[l];
		seg[id] = 2LL * a[l] % mod;
		seg[id] = (seg[id] + mod) % mod;
		return;
	}
	int mid = l + r >> 1;
	bld(lc, l, mid), bld(rc, mid, r);
	seg[id] = (seg[lc] + seg[rc]) % mod;
}
void shift(int id, int l, int r){
	if (!lazy[id])
		return;
	seg[id] = 1LL * seg[id] * pw[lazy[id]] % mod;
	if (r - l > 1){
		lazy[lc] += lazy[id];
		lazy[rc] += lazy[id];
	}
	lazy[id] = 0;
}
void update(int id, int l, int r, int ql, int qr, int val){
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
	seg[id] = (seg[lc] + seg[rc]) % mod;
}
int get(int id, int l, int r, int ql, int qr){
	shift(id, l, r);
	if (qr <= l || r <= ql || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return (get(lc, l, mid, ql, qr) + get(rc, mid, r, ql, qr)) % mod;
}
ll Pow(ll x, int y){
	if (y > 31)
		return INF;
	return min(INF, x * pw[y]);
}

int main(){
	InTheNameOfGod;
	
	pw[0] = inv[0] = 1;
	pw[1] = 2, inv[1] = power(2, mod - 2, mod);
	for (int i = 2; i < xn; ++ i){
		pw[i] = 2LL * pw[i - 1] % mod;
		inv[i] = 1LL * inv[i - 1] * inv[1] % mod;
	}
	cin >> n >> q;
	bld(1, 1, n + 1);
	for (int i = 0; i < q; ++ i){
		int l, r;
		cin >> l >> r;
		ans[i] = (a[l] + mod) % mod;
		if (l < r)
			query[r].push_back({l + 1, i});
	}
	for (int i = 1; i <= n; ++ i){
		pair <pii, ll> res = {{i, i}, a[i]};
		while (pt && res.B > 0){
			-- pt;
			int t = sk[pt].A.B - sk[pt].A.A + 1;
			update(1, 1, n + 1, res.A.A, i + 1, t);
			res.A.A = sk[pt].A.A;
			res.B = min(INF, sk[pt].B + Pow(res.B, t));
		}
		sk[pt ++] = res;
		for (pii x : query[i]){
			int l = 0, r = pt;
			while (r - l > 1){
				int mid = l + r >> 1;
				if (x.A < sk[mid].A.A)
					r = mid;
				else
					l = mid;
			}
			ans[x.B] = (ans[x.B] + get(1, 1, n + 1, sk[l].A.B + 1, i + 1)) % mod;
			ans[x.B] = (ans[x.B] + 1LL * get(1, 1, n + 1, x.A, sk[l].A.B + 1) * inv[x.A - sk[l].A.A] % mod) % mod;
		}
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;
			
	return 0;
}