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

const int xn = 30 + 10;
const int xm = 2e2 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a[xn], k, b[xn];
pii f[xn][xn][xn][xn];
ld dp[xm][xn][xn], ans, P;

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			if (i == j)
				continue;
			dp[0][i][j] += bool(a[i] < a[j]);
			for (int l = 1; l <= n; ++ l){
				for (int r = 1; r <= n; ++ r){
					fill(b + 1, b + n + 1, 0);
					b[i] = 1, b[j] = 2;
					reverse(b + l, b + r + 1);
					int x, y;
					for (int i = 1; i <= n; ++ i){
						if (b[i] == 1)
							x = i;
						else if (b[i] == 2)
							y = i;
					}
					f[i][j][l][r] = {x, y};
				}
			}
		}
	}
	P = ld(n) * ld(n + 1) / ld(2);
	P = ld(1) / P;
	for (int t = 0; t < k; ++ t)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				if (i != j)
					for (int l = 1; l <= n; ++ l)
						for (int r = l; r <= n; ++ r)
							dp[t + 1][f[i][j][l][r].A][f[i][j][l][r].B] += dp[t][i][j] * P;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j < i; ++ j)
			ans += dp[k][i][j];
	cout << fixed << setprecision(12) << ans << endl;

	return 0;
}