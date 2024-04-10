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
 
const int xn = 4e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, q, Rank[xm][xn], pw, lcp[xn], seg[xn << 2];
int a[xn], b[xn], c[xn], L[xn], R[xn], P[xn], f[xn];
stack <int> st;
ll ans, res;
string S;

bool cmp(int i, int j){
	if (Rank[pw - 1][i] != Rank[pw - 1][j])
		return Rank[pw - 1][i] < Rank[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > n)
		return i > j;
	return Rank[pw - 1][(1 << (pw - 1)) + i] < Rank[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
	for (int i = 1; i <= n; ++ i)
		Rank[0][i] = S[i - 1], P[i] = f[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + n + 1, cmp);
		for (int i = 1; i <= n; ++ i)
			f[P[i]] = i;
		Rank[pw][P[1]] = 1;
		for (int i = 2; i <= n; ++ i)
			Rank[pw][P[i]] = Rank[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (Rank[i][x] != Rank[i][y])
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
void build(int id, int l, int r){
	if (r <= l)
		return;
	if (r - l == 1){
		seg[id] = lcp[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = min(seg[lc], seg[rc]);
}
int get(int id, int l, int r, int ql, int qr){
	if (ql == qr)
		return n - P[ql] + 1;
	if (qr <= l || r <= ql)
		return inf;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return min(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}
ll solve(int m){
	for (int i = 0; i < m; ++ i)
		c[i] = f[c[i]];
	sort(c, c + m);
	for (int i = 0; i < m - 1; ++ i)
		c[i] = get(1, 1, n, c[i], c[i + 1]);
	-- m;
	while (SZ(st))
		st.pop();
	for (int i = 0; i < m; ++ i){
		while (SZ(st) && c[st.top()] >= c[i])
			st.pop();
		L[i] = - 1;
		if (SZ(st))
			L[i] = st.top();
		st.push(i);
	}
	while (SZ(st))
		st.pop();
	for (int i = m - 1; i >= 0; -- i){
		while (SZ(st) && c[st.top()] > c[i])
			st.pop();
		R[i] = m;
		if (SZ(st))
			R[i] = st.top();
		st.push(i);
	}
	res = 0;
	for (int i = 0; i < m; ++ i)
		res += ll(R[i] - i) * ll(i - L[i]) * ll(c[i]);
	return res;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> q >> S;
	buildSA();
	for (int i = 1; i < n; ++ i)
		lcp[i] = LCP(P[i], P[i + 1]);
	build(1, 1, n);
	while (q --){
		int k, l;
		cin >> k >> l;
		for (int i = 0; i < k; ++ i)
			cin >> a[i];
		for (int i = 0; i < l; ++ i)
			cin >> b[i];
		for (int i = 0; i < k; ++ i)
			c[i] = a[i];
		for (int i = 0; i < l; ++ i)
			c[i + k] = b[i];
		ans = solve(k + l);
		for (int i = 0; i < k; ++ i)
			c[i] = a[i];
		ans -= solve(k);
		for (int i = 0; i < l; ++ i)
			c[i] = b[i];
		ans -= solve(l);
		cout << ans << endl;
	}
			
	return 0;
}