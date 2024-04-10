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

const int xn = 7e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, dp[10][xn][xn], pw[11][xn], a[xn], cnt[10];
int ans, ps[10], C[xn][xn], psw[xn];
string S;

int calc(int l, int r){
	l = n - l;
	r = n - r;
	if (!l)
		return psw[r];
	return (psw[r] - psw[l - 1] + mod) % mod;
}
void solve(){
	ps[0] = cnt[0];
	for (int c = 1; c < 10; ++ c)
		ps[c] = cnt[c] + ps[c - 1];
	for (int c = 0; c < 10; ++ c){
		int x = 0;
		if (c)
			x = ps[c - 1];
		int y = ps[9] - x;
		for (int i = x + 1; i <= n - y + 1; ++ i)
			ans = (ans + 1ll * pw[c][i - x - 1] * pw[10 - c][n - i + 1 - y] % mod * C[n - ps[9]][i - x - 1] % mod * calc(i + cnt[c] - 1, i) % mod * c % mod) % mod;
		x = ps[c];
		y = ps[9] - x;
		for (int i = x + 1; i <= n - y; ++ i)
			ans = (ans + 1ll * pw[10][n - i] * dp[c][n - ps[9]][i - x] % mod * c % mod) % mod;
	}
}

int main(){
	fast_io;

	for (int i = 0; i < xn; ++ i)
		C[i][0] = 1;
	for (int i = 1; i < xn; ++ i)
		for (int j = 1; j <= i; ++ j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	for (int i = 0; i < 11; ++ i){
		pw[i][0] = 1;
		for (int j = 1; j < xn; ++ j)
			pw[i][j] = 1ll * pw[i][j - 1] * i % mod;
	}
	psw[0] = 1;
	for (int i = 1; i < xn; ++ i)
		psw[i] = (pw[10][i] + psw[i - 1]) % mod;
	for (int c = 0; c < 10; ++ c){
		for (int i = 1; i < xn; ++ i){
			for (int j = 1; j <= i; ++ j){
				dp[c][i][j] = 1ll * (c + 1) * dp[c][i - 1][j - 1] % mod;
				dp[c][i][j] = (dp[c][i][j] + 1ll * (9 - c) * dp[c][i - 1][j] % mod) % mod;
				dp[c][i][j] = (dp[c][i][j] + 1ll * C[i - 1][j - 1] * pw[c][j - 1] % mod * pw[10 - c][i - j] % mod) % mod;
			}
		}
	}
	cin >> S;
	n = SZ(S);
	for (int i = 1; i <= n; ++ i)
		a[i] = S[i - 1] - '0';
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < a[i]; ++ j)
			++ cnt[j], solve(), -- cnt[j];
		++ cnt[a[i]];
	}
	solve();
	cout << ans << endl;

	return 0;
}