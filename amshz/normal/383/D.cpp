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

const int xn = 1e3 + 10;
const int xm = 2e4 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], sum, dp[xn][xm], ans;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], sum += a[i];
	dp[0][sum] = 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < xm; ++ j){
			if (0 <= j - a[i])
				dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
			if (j + a[i] < xm)
				dp[i][j] = (dp[i][j] + dp[i - 1][j + a[i]]) % mod;
		}
		ans = (ans + dp[i][sum]) % mod;
		dp[i][sum] = (dp[i][sum] + 1) % mod;
	}
	cout << ans << endl;

	return 0;
}