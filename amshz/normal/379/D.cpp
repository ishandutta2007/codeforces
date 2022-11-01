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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 50 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int k, x, n, m, dp[3][xn];

int main(){
	InTheNameOfGod;

	cin >> k >> x >> n >> m;
	for (int i = 0; i + i <= n; ++ i){
		for (int j = 0; j + j <= m; ++ j){
			for (int f1 = 0; f1 < 2; ++ f1){
				for (int f2 = 0; f2 < 2; ++ f2){
					for (int f3 = 0; f3 < 2; ++ f3){
						for (int f4 = 0; f4 < 2; ++ f4){
							if (n < i + i + f1 + f2)
								continue;
							if (m < j + j + f3 + f4)
								continue;
							dp[0][1] = f1, dp[1][1] = f2, dp[2][1] = i;
							dp[0][2] = f3, dp[1][2] = f4, dp[2][2] = j;
							for (int p = 3; p <= k; ++ p){
								dp[0][p] = dp[0][p - 2];
								dp[1][p] = dp[1][p - 1];
								dp[2][p] = dp[2][p - 1] + dp[2][p - 2] + bool(0 < dp[1][p - 2] && 0 < dp[0][p - 1]);
								if (x < dp[2][p]){
									dp[2][k] = inf;
									break;
								}
							}
							if (dp[2][k] != x)
								continue;
							int res = n - f1 - f2;
							if (f1)
								cout << "C";
							for (int p = 0; p < i; ++ p)
								cout << "AC";
							for (int p = 0; p < res - i - i; ++ p)
								cout << "B";
							if (f2)
								cout << "A";
							cout << endl;
							res = m - f3 - f4;
							if (f3)
								cout << "C";
							for (int p = 0; p < j; ++ p)
								cout << "AC";
							for (int p = 0; p < res - j - j; ++ p)
								cout << "B";
							if (f4)
								cout << "A";
							cout << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	kill("Happy new year!");

	return 0;
}