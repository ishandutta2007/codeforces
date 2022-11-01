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

const int xn = 2e2 + 10;
const int xm = 1e3 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, dp[xn][xn][xm], a[xn];

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 0; i <= k; ++ i)
		dp[0][0][i] = 1;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j <= i; ++ j){
			for (int c = 0; c + (a[i + 1] - a[i]) * j <= k; ++ c){
				int d = c + (a[i + 1] - a[i]) * j;
				dp[i + 1][j][d] = (dp[i + 1][j][d] + dp[i][j][c]) % mod;
				dp[i + 1][j][d] = (dp[i + 1][j][d] + 1ll * dp[i][j][c] * j % mod) % mod;
				dp[i + 1][j + 1][d] = (dp[i + 1][j + 1][d] + dp[i][j][c]) % mod;
				if (j)
					dp[i + 1][j - 1][d] = (dp[i + 1][j - 1][d] + 1ll * dp[i][j][c] * j % mod) % mod;
			}
		}
	}
	cout << dp[n][0][k] << endl;

	return 0;
}