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
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, rnk[xm][xn], pw, P[xn], a[xn];
int f[xn], q, lcp[xn], mn[xn << 2];
vector <int> seg[xn << 2];

bool cmp(int i, int j){
	if (rnk[pw - 1][i] != rnk[pw - 1][j])
		return rnk[pw - 1][i] < rnk[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > m)
		return i > j;
	return rnk[pw - 1][(1 << (pw - 1)) + i] < rnk[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
	for (int i = 1; i <= m; ++ i)
		rnk[0][i] = a[i], P[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + m + 1, cmp);
		rnk[pw][P[1]] = 1;
		for (int i = 2; i <= m; ++ i)
			rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (rnk[i][x] != rnk[i][y] || max(x, y) + (1 << i) - 1 > m)
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
void build(int id, int l, int r){
	if (r - l == 1){
		mn[id] = lcp[l];
		if (P[l] < n)
			seg[id].push_back(P[l]);
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	for (int x : seg[lc])
		seg[id].push_back(x);
	for (int x : seg[rc])
		seg[id].push_back(x);
	sort(all(seg[id]));
	mn[id] = min(mn[lc], mn[rc]);
}
int get_mn(int id, int l, int r, int ql, int qr){
	if (qr <= ql || r <= ql || qr <= l)
		return inf;
	if (ql <= l && r <= qr)
		return mn[id];
	int mid = l + r >> 1;
	return min(get_mn(lc, l, mid, ql, qr), get_mn(rc, mid, r, ql, qr));
}
int get(int id, int l, int r, int ql, int qr, int val, int f){
	if (qr <= ql || qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr){
		if (!f){
			int lb = - 1, rb = SZ(seg[id]);
			while (rb - lb > 1){
				int mid = lb + rb >> 1;
				if (seg[id][mid] < val)
					lb = mid;
				else
					rb = mid;
			}
			return rb;
		}
		int lb = - 1, rb = SZ(seg[id]);
		while (rb - lb > 1){
			int mid = lb + rb >> 1;
			if (seg[id][mid] <= val)
				lb = mid;
			else
				rb = mid;
		}
		return SZ(seg[id]) - rb;
	}
	int mid = l + r >> 1;
	return get(lc, l, mid, ql, qr, val, f) + get(rc, mid, r, ql, qr, val, f);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i < n; ++ i)
		a[i] -= a[i + 1];
	a[n] = - inf;
	for (int i = n + 1; i <= n + n; ++ i)
		a[i] = - a[i - n];
	m = n + n;
	buildSA();
	for (int i = 1; i <= m; ++ i)
		f[P[i]] = i;
	for (int i = 1; i < m; ++ i)
		lcp[i] = LCP(P[i], P[i + 1]);
	build(1, 1, m);
	cin >> q;
	while (q --){
		int l, r;
		cin >> l >> r;
		if (l == r){
			cout << n - 1 << endl;
			continue;
		}
		int ind = f[l + n], sz = r - l;
		int lb = ind, rb = m;
		while (rb - lb > 1){
			int mid = lb + rb >> 1;
			if (get_mn(1, 1, m, ind, mid) >= sz)
				lb = mid;
			else
				rb = mid;
		}
		int R = rb;
		lb = 1, rb = ind;
		while (rb - lb > 1){
			int mid = lb + rb >> 1;
			if (get_mn(1, 1, m, mid, ind) >= sz)
				rb = mid;
			else
				lb = mid;
		}
		int L = rb;
		int ans = 0;
		ans += get(1, 1, m, L, R, l - sz, 0);
		ans += get(1, 1, m, L, R, r, 1);
		cout << ans << endl;
	}
	
	return 0;
}