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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;


struct matrix{
	int n, m, a[xn][xn];
	matrix operator * (const matrix &t){
		matrix r;
		r.n = n, r.m = t.m;
		for (int i = 0; i < n; ++ i){
			for (int j = 0; j < t.m; ++ j){
				r.a[i][j] = 0;
				for (int k = 0; k < m; ++ k)
					r.a[i][j] = (r.a[i][j] + 1ll * a[i][k] * t.a[k][j] % mod) % mod;
			}
		}
		return r;
	}
};

ll n;
int k, m, sum, ans;
vector <int> vec;

int main(){
	fast_io;

	cin >> n >> k;
	while (n)
		vec.push_back(n % k), n /= k, ++ m;
	matrix T[m];
	for (int i = 0; i < m; ++ i)
		T[i].n = T[i].m = k + 1;
	for (int i = 0; i < m; ++ i)
		for (int j = 0; j < xn; ++ j)
			for (int l = 0; l < xn; ++ l)
				T[i].a[j][l] = 0;
	for (int i = 0; i <= k; ++ i)
		T[0].a[i][i] = 1;
	for (int i = 0; i <= k; ++ i)
		T[0].a[i][0] = 1;
	matrix S[k];
	for (int i = 0; i < k; ++ i){
		S[i].n = S[i].m = k + 1;
		for (int j = 0; j < k; ++ j)
			S[i].a[j][(i + j) % k] = 1;
		S[i].a[k][k] = 1;
	}
	for (int i = 1; i < m; ++ i){
		for (int j = 0; j <= k; ++ j)
			T[i].a[j][j] = 1;
		for (int j = 0; j < k; ++ j)
			T[i] = (T[i] * T[i - 1]) * S[1];
	}
	matrix M;
	for (int j = 0; j < xn; ++ j)
		for (int l = 0; l < xn; ++ l)
			M.a[j][l] = 0;
	M.n = 1, M.m = k + 1;
	M.a[0][k] = 1;
	for (int i = m - 1; i >= 0; -- i){
		for (int j = 0; j < vec[i]; ++ j)
			M = ((M * S[(sum + j) % k]) * T[i]) * S[(k + k - sum - j) % k];
		sum = (sum + vec[i]) % k;
	}
	for (int i = 0; i <= k; ++ i)
		ans = (ans + M.a[0][i]) % mod;
	cout << ans << endl;

	return 0;
}