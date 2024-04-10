//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <ll, ll>                                    pll;
typedef pair <pll, pll>                                  ppp;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = 8 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

ppp dp[xm][xn];
ll n, a[xn], seg[xn << 2], ans;

void build(int id, int l, int r){
	if (r - l == 1){
		seg[id] = l;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid), build(rc, mid, r);
	seg[id] = seg[lc];
	if (a[seg[id]] < a[seg[rc]])
		seg[id] = seg[rc];
}
int get(int id, int l, int r, int ql, int qr){
	if (qr <= l || r <= ql)
		return 0;
	if (ql <= l && r <= qr)
		return seg[id];
	int mid = l + r >> 1;
	int x = get(lc, l, mid, ql, qr);
	int y = get(rc, mid, r, ql, qr);
	if (a[x] < a[y])
		return y;
	return x;
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i < n; ++ i)
		cin >> a[i];
	a[n] = n;
	build(1, 1, n + 1);
	for (ll i = n - 1; 1 <= i; -- i){
		dp[0][i] = {{a[i], a[i] - i}, {get(1, 1, n + 1, i, a[i] + 1), 0}};
		if (dp[0][i].B.A != i)
			dp[0][i].B.B = 1;
		for (int j = 1; j < xm; ++ j){
			if (dp[j - 1][i].A.A == n){
				dp[j][i] = dp[j - 1][i];
				continue;
			}
			ll v = dp[j - 1][i].A.A;
			ll sum = dp[j - 1][i].A.B;
			ll u = dp[j - 1][i].B.A;
			ll d = dp[j - 1][i].B.B;
			dp[j][i] = dp[j - 1][u];
			dp[j][i].B.B += d;
			dp[j][i].A.B += d * (dp[j][i].A.A - v) - (v - u) + sum;
		}
		ans += dp[xm - 1][i].A.B;
	}
	cout << ans << endl;

	return 0;
}