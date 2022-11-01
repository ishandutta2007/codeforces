// khodaya khodet komak kon
// Toxicity
# include <bits/stdc++.h>

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
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, pw, P[xn], rnk[xm][xn], dp[xn], ptr;
int f[xn], lcp[xn << 2], seg[xn << 2], ans;
string S;

bool cmp(int i, int j){
	if (rnk[pw - 1][i] != rnk[pw - 1][j])
		return rnk[pw - 1][i] < rnk[pw - 1][j];
	if (max(i, j) + (1 << (pw - 1)) > n)
		return i > j;
	return rnk[pw - 1][(1 << (pw - 1)) + i] < rnk[pw - 1][(1 << (pw - 1)) + j];
}
void buildSA(){
	for (int i = 1; i <= n; ++ i)
		rnk[0][i] = S[i - 1] - 'a', P[i] = i;
	for (pw = 1; pw < xm; ++ pw){
		sort(P + 1, P + n + 1, cmp);
		rnk[pw][P[1]] = 1;
		for (int i = 2; i <= n; ++ i)
			rnk[pw][P[i]] = rnk[pw][P[i - 1]] + cmp(P[i - 1], P[i]);
	}
}
int LCP(int x, int y){
	int res = 0;
	for (int i = xm - 1; i >= 0; -- i){
		if (rnk[i][x] != rnk[i][y] || max(x, y) + (1 << i) - 1 > n)
			continue;
		x += 1 << i, y += 1 << i;
		res |= (1 << i);
	}
	return res;
}
void build(int id, int l, int r){
	if (r - l == 1){
		lcp[id] = LCP(P[l], P[r]);
		f[P[l]] = l, f[P[r]] = r;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	lcp[id] = min(lcp[lc], lcp[rc]);
}
void modify(int id, int l, int r, int pos, int val){
	if (pos >= n)
		return;
	if (r - l == 1){
		seg[id] = val;
		return;
	}
	int mid = l + r >> 1;
	if (pos < mid)
		modify(lc, l, mid, pos, val);
	else
		modify(rc, mid, r, pos, val);
	seg[id] = max(seg[lc], seg[rc]);
}
int get1(int id, int l, int r, int ql, int qr, int d){
	if (qr <= l || r <= ql || qr <= ql || d <= lcp[id])
		return 0;
	if  (r - l == 1)
		return l;
	int mid = l + r >> 1;
	int x = get1(rc, mid, r, ql, qr, d);
	if (x == 0)
		return get1(lc, l, mid, ql, qr, d);
	return x;
}
int get2(int id, int l, int r, int ql, int qr, int d){
	if (qr <= l || r <= ql || qr <= ql || d <= lcp[id])
		return n;
	if  (r - l == 1)
		return l;
	int mid = l + r >> 1;
	int x = get2(lc, l, mid, ql, qr, d);
	if (x == n)
		return get2(rc, mid, r, ql, qr, d);
	return x;
}
int get(int id, int l, int r, int ql, int qr){
	if (r <= ql || qr <= l || qr <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	return max(get(lc, l, mid, ql, qr), get(rc, mid, r, ql, qr));
}
int check(int ind, int d){
	if (!ind)
		return 0;
	int r = get2(1, 1, n, ind, n, d);
	int l = get1(1, 1, n, 1, ind, d);
	return get(1, 1, n, l + 1, r + 1);
}

int main(){
	InTheNameOfGod;

	cin >> n >> S;
	if (n == 1)
		kill(1);
	buildSA(), build(1, 1, n), ptr = 1;
	for (int i = n; i >= 1; -- i){
		while (max(check(f[i], ptr - 1), check(f[i + 1], ptr - 1)) + 1 < ptr)
			-- ptr, modify(1, 1, n, f[i + ptr], dp[i + ptr]);
		dp[i] = ptr ++, ans = max(ans, dp[i]);
	}
	cout << ans << endl;

	return 0;
}