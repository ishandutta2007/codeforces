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
const int xn = 1e6 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";
 
int qq, n, k, dp[xn], part[xn], ans, c[xn];
string s;
 
void Solve(){
	cin >> n >> k >> s;
	for (int i = 0; i <= n; ++ i) 	dp[i] = part[i] = c[i] = 0;
	s = '.' + s;
	for (int i = 1; i <= n; ++ i)	if (s[i] == '1')	c[i] = 1;
	ans = inf;
	for (int i = 1; i <= n; ++ i)	part[i] = part[i - 1] + c[i];
	for (int i = 1; i <= n; ++ i){
		dp[i] = 1 - c[i] + part[i - 1];
		if (i > k)		dp[i] = min(dp[i], dp[i - k] + part[i - 1] - part[i - k] + 1 - c[i]);
		ans = min(ans, part[n] - part[i] + dp[i]);
	}
	ans = min(ans, part[n]);
	cout << ans << endl;
}
 
int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --)	Solve();
	
	return 0;
}