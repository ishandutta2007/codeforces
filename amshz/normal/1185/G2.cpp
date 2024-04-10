// khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
 
const int xn = 50 + 1;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;
 
int n, T, knap[2][xn][xn * xn], dp[xn][xn][xn * xn];
int f[xn][xn][xn][3], ans, fact[xn], res, sum;
vector <int> vec[3];
 
int main(){
	InTheNameOfGod;
	
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1LL * fact[i - 1] * i % mod;
	cin >> n >> T;
	for (int i = 1; i <= n; ++ i){
		int x, y;
		cin >> x >> y;
		vec[y - 1].push_back(x);
		if (y == 1)
			sum += x;
	}
	knap[0][0][0] = knap[1][0][0] = 1;
	for (int i = 0; i < 2; ++ i)
		for (int x : vec[i])
			for (int j = SZ(vec[i]); j > 0; -- j)
				for (int k = x; k <= T; ++ k)
					knap[i][j][k] = (knap[i][j][k] + knap[i][j - 1][k - x]) % mod;
	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < xn * xn; ++ j)
			dp[i][0][j] = knap[1][i][j];
	for (int x : vec[2])
		for (int i = 0; i <= SZ(vec[1]); ++ i)
			for (int j = SZ(vec[2]); j > 0; -- j)
				for (int k = x; k <= T; ++ k)
					dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - x]) % mod;
	f[0][0][1][2] = f[0][1][0][1] = f[1][0][0][0] = 1;
	for (int i = 0; i <= SZ(vec[0]); ++ i){
		for (int j = 0; j <= SZ(vec[1]); ++ j){
			for (int k = 0; k <= SZ(vec[2]); ++ k){
				if (i + j + k < 2)
					continue;
				if (i)
					f[i][j][k][0] = (f[i - 1][j][k][1] + f[i - 1][j][k][2]) % mod;
				if (j)
					f[i][j][k][1] = (f[i][j - 1][k][0] + f[i][j - 1][k][2]) % mod;
				if (k)
					f[i][j][k][2] = (f[i][j][k - 1][0] + f[i][j][k - 1][1]) % mod;
			}
		}
	}
	for (int i = 0; i <= SZ(vec[0]); ++ i){
		for (int j = 0; j <= SZ(vec[1]); ++ j){
			for (int k = 0; k <= SZ(vec[2]); ++ k){
				for (int t = 1; t < 3; ++ t)
					f[i][j][k][0] = (f[i][j][k][0] + f[i][j][k][t]) % mod;
				for (int t = 0; t <= sum; ++ t){
					res = f[i][j][k][0];
					res = 1LL * res * knap[0][i][t] % mod;
					res = 1LL * res * dp[j][k][T - t] % mod;
					res = 1LL * res * fact[i] % mod;
					res = 1LL * res * fact[j] % mod;
					res = 1LL * res * fact[k] % mod;
					ans = (ans + res) % mod;
				}
			}
		}
	}
	cout << ans << endl;
 
	return 0;
}