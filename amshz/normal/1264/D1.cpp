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
 
const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, dp[2][xn][xn], part[xn], ans;
string s;

int main(){
	InTheNameOfGod;
	
	cin >> s;
	n = SZ(s), s = '.' + s;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < xn; ++ j){
			if (s[i] != '(')
				dp[0][i][j] = (dp[0][i][j] + dp[0][i - 1][j]) % mod;
			if (s[i] != ')' && j)
				dp[0][i][j] = (dp[0][i][j] + dp[0][i - 1][j - 1]) % mod;
		}
	}
	dp[1][n + 1][0] = 1;
	for (int i = 0; i < xn; ++ i)
		part[i] = 1;
	for (int i = n; i >= 1; -- i){
		if (s[i] != '(')
			for (int j = 1; j < xn; ++ j)
				ans = (ans + 1LL * dp[0][i - 1][j] * part[j - 1] % mod) % mod;
		for (int j = 0; j < xn; ++ j){
			if (s[i] != ')')
				dp[1][i][j] = (dp[1][i][j] + dp[1][i + 1][j]) % mod;
			if (s[i] != '(' && j)
				dp[1][i][j] = (dp[1][i][j] + dp[1][i + 1][j - 1]) % mod;
			part[j] = dp[1][i][j];
			if (j)
				part[j] = (part[j] + part[j - 1]) % mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}