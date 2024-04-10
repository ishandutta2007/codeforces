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

const int xn = 3e3 + 10;
const int xm = - 20 + 10;
const int sq = 12;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, c, a[xn], pw[xn], inv[xn], cnt[xn], dp[xn][xn], f[xn], pd[2][xn][1 << sq];

int main(){
	fast_io;

	for (int i = 1; i < xn; ++ i){
		pw[i] = (pw[i - 1] + pw[i - 1] + 1) % mod;
		inv[i] = power(pw[i], mod - 2, mod);
	}
	pw[0] = inv[0] = 1;
	cin >> n >> c;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	if (sq < c){
		dp[0][0] = 1;
		for (int l = 0; l < n; ++ l){
			int t = c, res = 1;
			for (int r = l + 1; r <= n; ++ r){
				t -= (cnt[a[r]] == 0);
				++ cnt[a[r]];
				res = 1ll * res * inv[cnt[a[r]] - 1] % mod;
				if (!t)
					for (int k = 0; k <= l / c; ++ k)
						dp[r][k + 1] = (dp[r][k + 1] + 1ll * res * dp[l][k] % mod) % mod;
				res = 1ll * res * pw[cnt[a[r]]] % mod;
			}
			for (int r = l + 1; r <= n; ++ r)
				-- cnt[a[r]];
		}
		int t = c, res = 1;
		for (int i = n; i >= 0; -- i){
			for (int j = 0; j <= n / c; ++ j)
				f[j] = (f[j] + 1LL * dp[i][j] * (pw[n - i] + (i == n ? 0 : 1) - (t ? 0 : res))) % mod;
			t -= cnt[a[i]] == 0;
			++ cnt[a[i]];
			res = 1ll * res * inv[cnt[a[i]] - 1] % mod * pw[cnt[a[i]]] % mod;
		}
		-- f[0];
		for (int i = 0; i <= n; ++ i)
			cout << (f[i] + mod) % mod << sep;
		cout << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++ i)
		-- a[i];
	pd[0][0][0] = 1;
	for (int i = 1; i <= n; i ++){
        int id1 = 1 - i % 2, id2 = i % 2;
        for (int j = 0; j <= i / c; ++ j){
            pd[id2][j][0] = pd[id1][j][0];
            if (j)
                pd[id2][j][0] = (pd[id2][j][0] + pd[id1][j - 1][((1 << c) - 1) ^ (1 << a[i])]) % mod;
            for (int mask = 1; mask < (1 << c) - 1; ++ mask){
                pd[id2][j][mask] = pd[id1][j][mask];
                if (mask >> a[i] & 1)
                    pd[id2][j][mask] = ((pd[id2][j][mask] + pd[id1][j][mask ^ (1 << a[i])]) % mod + pd[id1][j][mask]) % mod;
            }
        }
    }
    for (int i = 0; i <= n / c; ++ i)
        for (int j = 0; j < (1 << c) - 1; ++ j)
            f[i] = (f[i] + pd[n % 2][i][j]) % mod;
    -- f[0];
    for (int i = 0; i <= n; i ++)
        cout << (f[i] + mod) % mod << sep;
    cout << endl;

	return 0;
}