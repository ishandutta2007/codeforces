//khodaya khodet komak kon
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
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, k, dp[xn][xn][2], fact[xn], ifact[xn];
vector <ppp> vec[xn + xn][2];

ll C(ll r, ll n){
	if (r < 0 || n - r < 0)
		return 0;
	return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	//InTheNameOfGod;
	
	fact[0] = 1;
	for (ll i = 1; i < xn; ++ i)
		fact[i] = fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (ll i = xn - 2; i >= 0; -- i)
		ifact[i] = ifact[i + 1] * (i + 1) % mod;
	cin >> n >> k;
	for (int i = 0; i < xn; ++ i){
		for (int f1 = 0; f1 < 2; ++ f1){
			for (int j = 0; j < xn; ++ j){
				for (int f2 = 0; f2 < 2; ++ f2){
					if (i - f1 < 0 || j - f2 < 0)
						continue;
					pii x = {i + j + 1 - min(f1, f2), i + j};
					x.B = bool(x.A > x.B);
					vec[x.A][x.B].push_back({{i, f1}, {j, f2}});
				}
			}
		}
	}
	dp[1][0][0] = 1;
	for (ll s = 2; s <= n; ++ s){
		for (ll t = 1; t <= k; ++ t){
			dp[s][t][0] = dp[s - 1][t][1] * s % mod;
			dp[s][t][1] = dp[s - 1][t - 1][0] * s % mod;
			for (int f = 0; f < 2; ++ f){
				for (ppp x : vec[t][f]){
					for (ll i = 1; i < s - 1; ++ i){
						ll res = dp[i][x.A.A][x.A.B] * dp[s - i - 1][x.B.A][x.B.B] % mod;
						res = res * C(i - 1, s - 2) % mod * s % mod;
						dp[s][t][f] = (dp[s][t][f] + res) % mod;
					}
				}
			}
		}
	}
	cout << (dp[n][k][0] + dp[n][k][1]) * power(n, mod - 2, mod) % mod << endl;
	
	return 0;
}