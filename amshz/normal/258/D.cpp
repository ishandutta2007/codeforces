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
const int xn = 1e3 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e10 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, num[xn], q, a, b;
ld dp[xn][xn], ans, nim = ld(1) / ld(2), x;

int main(){
	InTheNameOfGod;
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i)	 cin >> num[i];
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			if (num[i] > num[j]) 	dp[i][j] = ld(1);
	while (q --){
		cin >> a >> b;
		if (a > b) swap(a, b);
		for (int i = 1; i < a; ++ i)
			dp[i][a] = dp[i][b] = (dp[i][a] + dp[i][b]) / ld(2);
		for (int i = b + 1; i <= n; ++ i)
			dp[a][i] = dp[b][i] = (dp[a][i] + dp[b][i]) / ld(2);
		for (int i = a + 1; i < b; ++ i){
			x = dp[a][i] - dp[i][b];
			dp[a][i] = ld(1 + x) / ld(2);
			dp[i][b] = ld(1 - x) / ld(2);
		}
		dp[a][b] = nim;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)	ans += dp[i][j];
	cout << fixed << setprecision(10);
	cout << ans << endl;
	
	return 0;
}