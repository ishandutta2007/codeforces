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

const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int m, k, qq, a[xn];
ll f[xn], n, dp[2][xn];

int main(){
	fast_io;

	f[1] = m = dp[0][0] = a[0] = 1;
	while (f[m - 1] + f[m] < INF)
		++ m, f[m] = f[m - 1] + f[m - 2];
	cin >> qq;
	while (qq --){
		cin >> n, k = 0;
		for (int i = m; 1 <= i; -- i)
			if (f[i] <= n)
				n -= f[i], a[++ k] = i;
		reverse(a + 1, a + k + 1);
		for (int i = 1; i <= k; ++ i){
			dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
			dp[1][i] = dp[0][i - 1] * ((a[i] - a[i - 1] + 1) / 2 - 1);
			dp[1][i] += dp[1][i - 1] * ((a[i] - a[i - 1] + 2) / 2 - 1);
		}
		cout << dp[0][k] + dp[1][k] << endl;
	}

	return 0;
}