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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 6e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 2e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, rnk[xm][xn], pw, P[xn], a[xn], ptr, m, lcp[xn];
int seg[xn << 2], mn[xn << 2], b[xn], c[2][xn];
ll ans;
string s, t[xn], S;
bool flag[xn];

bool cmp(int i, int j){
	if (rnk[pw - 1][i] != rnk[pw - 1][j])
		return rnk[pw - 1][i] < rnk[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > ptr)
		return i > j;
	return rnk[pw - 1][(1 << (pw - 1)) + i] < rnk[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
	for (int i = 1; i <= ptr; ++ i)
		rnk[0][i] = a[i], P[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + ptr + 1, cmp);
		rnk[pw][P[1]] = 1;
		for (int i = 2; i <= ptr; ++ i)
			rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (rnk[i][x] != rnk[i][y] || max(x, y) + (1 << i) - 1 > ptr)
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
void build(int id, int l, int r){
	seg[id] = 0;
	if (r - l == 1){
		mn[id] = lcp[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	mn[id] = min(mn[lc], mn[rc]);
}
bool update(int id, int l, int r, int ql, int qr, int val){
	if (qr <= l || r <= ql || qr <= ql)
		return true;
	if (ql <= l && r <= qr && mn[id] >= val){
		++ seg[id];
		return true;
	}
	if (r - l == 1)
		return false;
	int mid = l + r >> 1;
	if (update(lc, l, mid, ql, qr, val))
		return update(rc, mid, r, ql, qr, val);
	return false;
}
void get(int id, int l, int r, int f){
	if (r - l == 1){
		if (P[r] <= m)
			c[f][P[r]] += seg[id];
		return;
	}
	int mid = l + r >> 1;
	seg[lc] += seg[id], seg[rc] += seg[id];
	get(lc, l, mid, f), get(rc, mid, r, f);
}
void solve(int id){
	for (int i = 1; i <= m; ++ i)
		a[i] = s[i - 1];
	ptr = m;
	memset(flag, false, sizeof flag);
	for (int i = 1; i <= n; ++ i){
		a[++ ptr] = - i;
		flag[ptr + 1] = true;
		b[ptr + 1] = SZ(t[i]);
		for (char C : t[i])
			a[++ ptr] = C;
	}
	buildSA();
	for (int i = 1; i < ptr; ++ i)
		lcp[i] = LCP(P[i], P[i + 1]);
	build(1, 1, ptr);
	for (int i = 1; i < ptr; ++ i)
		if (flag[P[i]])
			update(1, 1, ptr, i, ptr, b[P[i]]);
	get(1, 1, ptr, id);
}

int main(){
	InTheNameOfGod;
	
	cin >> s;
	m = SZ(s);
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> t[i];
	solve(0);
	reverse(all(s));
	for (int i = 1; i <= n; ++ i)
		reverse(all(t[i]));
	solve(1);
	for (int i = 1; i < m; ++ i)
		ans += ll(c[0][i + 1]) * ll(c[1][m - i + 1]);
	cout << ans << endl;
			
	return 0;
}