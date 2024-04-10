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

int qq, n, a[xn], b[xn];
ll ans, sum, sum2;
bool dp[xn][xn * xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, sum = 0, sum2 = 0;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], sum += a[i], sum2 += a[i] * a[i];
		for (int j = 1; j <= n; ++ j)
			cin >> b[j], sum += b[j], sum2 += b[j] * b[j];
		memset(dp, false, sizeof dp);
		dp[0][0] = true;
		for (int i = 1; i <= n; ++ i){
			for (int j = 0; j <= sum; ++ j){
				dp[i][j] = false;
				if (0 <= j - a[i])
					dp[i][j] |= dp[i - 1][j - a[i]];
				if (0 <= j - b[i])
					dp[i][j] |= dp[i - 1][j - b[i]];
			}
		}
		ans = INF;
		for (int i = 0; i <= sum; ++ i)
			if (dp[n][i])
				ans = min(ans, i * i + (sum - i) * (sum - i) + (n - 2) * sum2);
		if (n == 1)
			ans = 0;
		cout << ans << endl;
	}

	return 0;
}