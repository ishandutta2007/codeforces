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

const int xn = 21;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 31607;//1e9 + 7;//998244353;
const int base = 257;

int n, a[xn][xn], tot = 10000, ans, pw[xn * xn + 1];
int c[2][1 << xn][xn], zr[xn], inv[xn][xn], INV = power(tot, mod - 2, mod);
bool f[xn][xn];

int solve(){
	int res = 0;
	for (int j = 0; j < n; ++ j){
		int sum = 1, ted = 0, sabet = 1;
		for (int i = 0; i < n; ++ i){
			if (f[i][j])
				sabet = sabet * a[i][j] % mod;
			else
				++ ted, sum = sum * a[i][j] % mod;
		}
		c[0][0][j] = ((pw[ted] - sum + mod) % mod) * sabet % mod;
		c[1][0][j] = pw[ted] * sabet % mod;
	}
	for (int mask = 0; mask < (1 << n); ++ mask){
		if (mask){
			int last = 0;
			for (int i = 0; i < n; ++ i)
				if ((mask & (1 << i)))
					last = i;
			int mask2 = mask ^ (1 << last);
			for (int i = 0; i < n; ++ i){
				c[0][mask][i] = c[0][mask2][i];
				c[1][mask][i] = c[1][mask2][i];
				if (f[last][i])
					continue;
				c[1][mask][i] = c[1][mask][i] * INV % mod * a[last][i] % mod;
				c[0][mask][i] = (c[0][mask][i] - c[1][mask2][i] * INV % mod * (tot - a[last][i]) % mod + mod) % mod;
			}
		}
		int sum = 1;
		for (int i = 0; i < n; ++ i)
			sum = sum * c[0][mask][i] % mod;
		int ted = __builtin_popcount(mask);
		if (ted % 2)
			res = (res - sum + mod) % mod;
		else
			res = (res + sum) % mod;
		//cout << mask << " : " << sum << endl;
	}
	return res;
}

int main(){
	fast_io;

	//tot = 2;
	pw[0] = 1;
	for (int i = 1; i <= xn * xn; ++ i)
		pw[i] = pw[i - 1] * tot % mod;
	cin >> n;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			cin >> a[i][j];
			//a[i][j] = 1;
			//inv[i][j] = power(a[i][j], mod - 2, mod) * (tot - a[i][j]) % mod;
		}
	}
	ans = (ans + solve()) % mod;
	//cout << ans << endl;
	//return 0;
	memset(f, false, sizeof f);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			if (i == j)
				f[i][j] = true;
	ans = (ans - solve() + mod) % mod;
	memset(f, false, sizeof f);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			if (i + j == n - 1)
				f[i][j] = true;
	ans = (ans - solve() + mod) % mod;
	memset(f, false, sizeof f);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j)
			if (i == j || i + j == n - 1)
				f[i][j] = true;
	ans = (ans + solve()) % mod;
	ans = (pw[n * n] - ans + mod) % mod;
	ans = ans * power(pw[n * n], mod - 2, mod) % mod;
	cout << ans << endl;

	return 0;
}