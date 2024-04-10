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
int mod = 1e9 + 7;//998244353;
const int base = 257;

int m, n, dp[xn][1 << xn], C[xn][xn], f[xn][xn][xn];
ll t;

struct matrix{
    int a[xn];
    matrix operator * (const matrix &t){
        matrix r;
        for (int i = 0; i <= m; ++ i)
        	r.a[i] = 0;
        for (int i = 0; i <= m; ++ i)
        	for (int j = 0; j <= m; ++ j)
        		for (int k = (i + j) % 2; k <= m; k += 2)
        			if (0 <= k + j - i && 0 <= k + i - j)
        				r.a[j] = (r.a[j] + 1ll * a[i] * t.a[k] % mod * f[i][j][k] % mod) % mod;
        return r;
    }
};
 
matrix Pow(matrix a, ll b){
    matrix res = a;
    if (b < 0)
    	return res;
    for (; b; b = b >> 1){
        if (b & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

int main(){
	fast_io;

	cin >> m >> t >> mod;
	n = (1 << m);
	for (int i = 0; i < n; ++ i)
		cin >> dp[0][i], dp[0][i] %= mod;
	matrix M;
	for (int i = 0; i <= m; ++ i)
		cin >> M.a[i], M.a[i] %= mod;
	for (int bit = 0; bit < m; ++ bit)
		for (int i = m; 1 <= i; -- i)
			for (int mask = 0; mask < n; ++ mask)
				dp[i][mask] = (dp[i][mask] + dp[i - 1][mask ^ (1 << bit)]) % mod;
	for (int i = 0; i < xn; ++ i)
		C[i][0] = 1;
	for (int i = 1; i < xn; ++ i)
		for (int j = 1; j <= i; ++ j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	for (int i = 0; i <= m; ++ i)
    	for (int j = 0; j <= m; ++ j)
    		for (int k = (i + j) % 2; k <= m; k += 2)
    			if (0 <= k + j - i && 0 <= k + i - j)
    				f[i][j][k] = (f[i][j][k] + 1ll * C[j][(k + j - i) / 2] % mod * C[m - j][(k + i - j) / 2] % mod) % mod;
	M = Pow(M, t - 1);
	for (int i = 0; i < n; ++ i){
		int ans = 0;
		for (int j = 0; j <= m; ++ j)
			ans = (ans + 1ll * dp[j][i] * M.a[j] % mod) % mod;
		cout << ans << endl;
	}

	return 0;
}