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

const int xn = 50 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, dp[xn][xn][xn][xn], ps[xn][xn];
string S[xn];

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> S[i];
		S[i] = '.' + S[i];
		for (int j = 1; j <= n; ++ j)
			ps[i][j] = ((S[i][j] == '#') + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1]);
	}
	for (int t1 = 0; t1 < n; ++ t1){
		for (int t2 = 0; t2 < n; ++ t2){
			for (int l1 = 1; l1 + t1 <= n; ++ l1){
				int r1 = l1 + t1;
				for (int l2 = 1; l2 + t2 <= n; ++ l2){
					int r2 = l2 + t2;
					if (!(ps[r1][r2] - ps[r1][l2 - 1] - ps[l1 - 1][r2] + ps[l1 - 1][l2 - 1]))
						continue;
					dp[l1][r1][l2][r2] = max(t1, t2) + 1;
					for (int i = l1; i < r1; ++ i)
						dp[l1][r1][l2][r2] = min(dp[l1][r1][l2][r2], dp[l1][i][l2][r2] + dp[i + 1][r1][l2][r2]);
					for (int i = l2; i < r2; ++ i)
						dp[l1][r1][l2][r2] = min(dp[l1][r1][l2][r2], dp[l1][r1][l2][i] + dp[l1][r1][i + 1][r2]);
				}
			}
		}
	}
	cout << dp[1][n][1][n] << endl;

	return 0;
}