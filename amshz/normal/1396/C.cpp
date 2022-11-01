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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

ll n, a[xn], r1, r2, r3, d, dp[xn][2], b[xn], c[xn], ans;

int main(){
    InTheNameOfGod;
    
	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	for (int i = 1; i <= n; ++ i){
		b[i] = r1 * a[i] + r3;
		c[i] = min(r2 + r1, r1 * (a[i] + 2));
	}
	dp[0][1] = INF;
	for (int i = 1; i <= n; ++ i){
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + c[i] + d + d;
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + c[i]);
	}
	ans = min(dp[n][0], dp[n][1]);
	ans = min(ans, dp[n - 1][1] + b[n] - d);
	cout << ans + (n - 1) * d << endl;

    return 0;
}