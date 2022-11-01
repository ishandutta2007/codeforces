//khodaya khodet komak kon
#pragma GCC optimize("Ofast")
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

int n, h, m, ps[xn][xn][xn], dp[xn][xn][xn];

int get(int x, int l1, int r1, int l2, int r2){
	return ps[x][l2][r2] - ps[x][l1 - 1][r2] - ps[x][l2][r1 - 1] + ps[x][l1 - 1][r1 - 1];
}

int main(){
	fast_io;

	cin >> n >> h >> m;
	while (m --){
		int l, r, x, c;
		cin >> l >> r >> x >> c;
		ps[x][l][r] += c;
	}
	for (int i = 1; i < xn; ++ i)
		for (int j = 0; j < xn; ++ j)
			for (int k = 0; k < xn; ++ k)
				ps[i][j][k] += ps[i - 1][j][k];
	for (int i = 0; i < xn; ++ i)
		for (int j = 1; j < xn; ++ j)
			for (int k = 0; k < xn; ++ k)
				ps[i][j][k] += ps[i][j - 1][k];
	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < xn; ++ j)
			for (int k = 1; k < xn; ++ k)
				ps[i][j][k] += ps[i][j][k - 1];
	for (int i = 1; i <= h; ++ i){
		for (int t = 1; t <= n; ++ t){
			for (int l = 1; l + t - 1 <= n; ++ l){
				dp[i][t][l] = dp[i - 1][t][l];
				for (int j = 0; j < t; ++ j)
					dp[i][t][l] = max(dp[i][t][l], dp[i][j][l] + dp[i - 1][t - j - 1][l + j + 1] + i * i - get(i - 1, l, l + j, l + j, l + t - 1));
			}
		}
	}
	cout << dp[h][n][1] << endl;

	return 0;
}