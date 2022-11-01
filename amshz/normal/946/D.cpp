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

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, k, a[xn][xn], dp[xn][xn], last[2][xn];
string S;

int main(){
	fast_io;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i){
		cin >> S, S = '.' + S;
		for (int j = 1; j <= m + 1; ++ j){
			last[0][j] = last[0][j - 1];
			if (j - 1 && S[j - 1] == '1')
				last[0][j] = j - 1;
		}
		last[1][m + 1] = m + 1;
		for (int j = m; j >= 0; -- j){
			last[1][j] = last[1][j + 1];
			if (j < m && S[j + 1] == '1')
				last[1][j] = j + 1;
		}
		for (int j = 0; j < xn; ++ j)
			a[i][j] = inf;
		int pt1 = 0, pt2;
		for (int j = 0; j <= m; ++ j){
			pt2 = m + 1;
			for (int l = 0; j + l <= m; ++ l){
				a[i][j + l] = min(a[i][j + l], max(0, last[0][pt2] - last[1][pt1] + 1));
				pt2 = last[0][pt2];
			}
			pt1 = last[1][pt1];
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j <= k; ++ j){
			dp[i][j] = inf;
			for (int l = 0; l <= j; ++ l)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + a[i][l]);
		}
	}
	cout << dp[n][k] << endl;

	return 0;
}