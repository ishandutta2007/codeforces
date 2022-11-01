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
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 2e3 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = SQ + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 100 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 100 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, m, c[xn][xn], part[xn][xn], dp[xn][xn], last[26][xn], Last;
string a, b;

int main(){
	InTheNameOfGod;
	
	cin >> a >> b;
	n = SZ(a), m = SZ(b);
	a = '.' + a, b = '.' + b;
	for (int i = 0; i < 26; ++ i){
		Last = 0;
		for (int j = 1; j <= n; ++ j){
			if (a[j] == abc[i]) Last = j;
			last[i][j] = Last;
		}
	}
	for (int i = 1; i <= m; ++ i) c[0][i] = -1;
	c[0][0] = 1;
	for (int i = 1; i <= n; ++ i){
		c[i][0] = i + 1;
		for (int j = 1; j <= m; ++ j){
			if (!last[b[j] - 'a'][i]) c[i][j] = -1;
			else c[i][j] = c[last[b[j] - 'a'][i] - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j <= i; ++ j){
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			int x = j - i + c[i][m] - 1 + m;
			if (c[i][m] != -1 && x <= c[i][m] - 1 && x >= 0)
				dp[i][j] = max(dp[i][j], dp[c[i][m] - 1][x] + 1);
		}
	}
	for (int i = 0; i <= n; ++ i) cout << dp[n][i] << sep;
	cout << endl;
	
	return 0;
}