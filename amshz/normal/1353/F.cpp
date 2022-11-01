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
const int xn = 1e2 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";
 
int qq, n, m;
ll num[xn][xn], ans, x, dp[xn][xn];
 
void Check(ll x){
	for (int i = 0; i < n; ++ i)	for (int j = 0; j < m; ++ j)	dp[i][j] = INF;
	if (num[0][0] >= x)		dp[0][0] = num[0][0] - x;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (num[i][j] < x)	 	continue;
			if (i) 		dp[i][j] = min(dp[i][j], dp[i - 1][j] + num[i][j] - x);
			if (j)		dp[i][j] = min(dp[i][j], dp[i][j - 1] + num[i][j] - x);
		}
	}
	ans = min(ans, dp[n - 1][m - 1]);
}
 
void Solve(){
	ans = INF;
	cin >> n >> m;
	for (int i = 0; i < n; ++ i)	for (int j = 0; j < m; ++ j)	cin >> num[i][j], num[i][j] -= i + j;
	for (int i = 0; i < n; ++ i)	for (int j = 0; j < m; ++ j)	Check(num[i][j]);
	cout << ans << endl;
}
 
int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --)	Solve();
	
	return 0;
}