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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = 21;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, dp[xm][1 << xm], res;
pii w[xn][xm];
string s[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i){
		cin >> s[i];
		m = SZ(s[i]);
		int c = 0;
		for (int j = 0; j < m; ++ j){
			if (s[i][j] == '1')
				c += 1 << j;
			w[i][j + 1].A = c;
		}
		c = 0;
		for (int j = m - 1; j >= 0; -- j){
			c *= 2;
			if (s[i][j] == '1') ++ c;
			w[i][m - j].B = c;
		}
	}
	for (int i = 0; i < xm; ++ i)
		for (int j = 0; j < 1 << xm; ++ j)
			dp[i][j] = inf;
	dp[0][0] = m;
	for (int i = 1; i < n; ++ i){
		int mn = inf, mx = 0;
		for (int j = 0; j <= m; ++ j){
			if (w[i][j].A == w[i - 1][j].B) mx = j;
			mn = min(mn, dp[j][w[i][j].A] + m - j);
		}
		mx = m - mx;
		for (int j = 0; j <= m; ++ j)
			dp[j][w[i - 1][j].B] = min(dp[j][w[i - 1][j].B], mn - mx);
		res += mx;
	}
	cout << dp[0][0] + res << endl;
	
	return 0;
}