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
 
const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], b[xn], dp[xn][xn * xn];
ld sum, ans;

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < xn * xn; ++ j)
			dp[i][j] = - inf;
	dp[0][0] = 0;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i] >> b[i];
		sum += ld(b[i]) / ld(2);
		for (int j = xn - 1; j >= 1; -- j)
			for (int k = a[i]; k < xn * xn; ++ k)
				dp[j][k] = max(dp[j][k], dp[j - 1][k - a[i]] + b[i]);
	}
	for (int i = 1; i <= n; ++ i){
		ans = 0;
		for (int j = 0; j < xn * xn; ++ j)
			ans = max(ans, min(sum + ld(dp[i][j]) / ld(2), ld(j)));
		cout << fixed << setprecision(12) << ans << sep;
	}
	cout << endl;
			
	return 0;
}