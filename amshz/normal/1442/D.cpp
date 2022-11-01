//khodaya khodet komak kon
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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 3e3 + 10;
const int xm = 13;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, k, a[xn][xn], sz[xn];
ll dp[xm][xn], ps[xn][xn], ans;

void build(int id, int l, int r, int h = 0){
	if (r - l == 1){
		for (int i = 0; i <= min(k, sz[l]); ++ i)
			ans = max(ans, ps[l][i] + dp[h][k - i]);
		return;
	}
	int mid = l + r >> 1;
	for (int i = 0; i <= k; ++ i)
		dp[h + 1][i] = dp[h][i];
	for (int i = l; i < mid; ++ i)
		for (int j = k; sz[i] <= j; -- j)
			dp[h + 1][j] = max(dp[h + 1][j], dp[h + 1][j - sz[i]] + ps[i][sz[i]]);
	build(rc, mid, r, h + 1);
	for (int i = 0; i <= k; ++ i)
		dp[h + 1][i] = dp[h][i];
	for (int i = mid; i < r; ++ i)
		for (int j = k; sz[i] <= j; -- j)
			dp[h + 1][j] = max(dp[h + 1][j], dp[h + 1][j - sz[i]] + ps[i][sz[i]]);
	build(lc, l, mid, h + 1);
}

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 1; i <= n; ++ i){
		cin >> sz[i];
		for (int j = 1; j <= sz[i]; ++ j){
			int x;
			cin >> x;
			if (k < j)
				continue;
			a[i][j] = x;
			ps[i][j] = ps[i][j - 1] + a[i][j];
		}
	}
	build(1, 1, n + 1);
	cout << ans << endl;

	return 0;
}