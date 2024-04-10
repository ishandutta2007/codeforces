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
 
const int xn = 4e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int qq, n, a[xn], dp[xn][xn], ans;

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		ans = inf;
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j < n + n; ++ j){
				dp[i][j] = inf;
				if (i == 1){
					dp[i][j] = abs(a[i] - j);
					continue;
				}
				for (int k = 1; k < j; ++ k)
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(a[i] - j));
			}
		}
		for (int i = 1; i < n + n; ++ i)
			ans = min(ans, dp[n][i]);
		cout << ans << endl;
	}
	
	return 0;
}