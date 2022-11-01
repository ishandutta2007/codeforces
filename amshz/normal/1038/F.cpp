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

const int xn = 40 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, f[xn], pw[xn], dp[xn][xn], g[xn][xn], a[xn], m, ans;
string S;
bool flag;

int main(){
	fast_io;

	pw[0] = 1;
	for (int i = 1; i < xn; ++ i)
		pw[i] = pw[i - 1] * 2;
	cin >> n >> S;
	m = SZ(S);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			memset(a, 0, sizeof a);
			for (int k = 0; k < m; ++ k){
				if (S[k] == '1')
					++ a[(i + k) % n], -- a[(j + k) % n];
				else
					-- a[(i + k) % n], ++ a[(j + k) % n];
			}
			flag = false;
			for (int k = 0; k < n; ++ k)
				flag |= abs(a[k]) == 2;
			if (flag)
				continue;
			memset(a, 0, sizeof a);
			for (int k = 0; k < m; ++ k)
				++ a[(i + k) % n];
			if (a[j])
				g[i][j] = 1;
			else
				g[i][j] = pw[(j - i - m + n + n) % n];
		}
		g[i][i] = pw[n - m];
	}
	for (int s = 0; s < n; ++ s){
		memset(dp, 0, sizeof dp);
		dp[s][1] = 1;
		for (int i = s; i < n; ++ i){
			for (int j = 1; j <= n; ++ j){
				for (int k = 0; k < i; ++ k)
					dp[i][j] += dp[k][j - 1] * g[k][i];
				f[j] += dp[i][j] * g[i][s];
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (i % 2)
			ans += f[i];
		else
			ans -= f[i];
	}
	cout << ans << endl;

	return 0;
}