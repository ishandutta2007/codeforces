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
 
const int xn = 3e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

ll qq, n, num[xn], dp[xn], ans, part[2][xn];
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 0; i < n; ++ i) cin >> num[i];
    	if (n == 1){
    		cout << num[0] << endl;
    		continue;
		}
    	dp[0] = num[0];
    	dp[1] = num[1];
    	dp[1] = max(dp[1], dp[0]);
    	part[0][0] = num[0];
    	for (int i = 1; i < n; ++ i){
    		part[0][i] = part[0][i - 1];
    		if (i % 2 == 0) part[0][i] += num[i];
		}
		part[1][n] = 0;
		for (int i = n - 1; i >= 0; -- i){
			part[1][i] = part[1][i + 1];
			if (i % 2 == 0) part[1][i] += num[i];
		}
		ans = max(part[0][n - 1], part[1][2] + dp[1]);
    	for (int i = 2; i < n; ++ i){
    		dp[i] = part[0][i];
    		if (i % 2 == 0) dp[i] = max(dp[i], dp[i - 2] + num[i - 1]);
    		else dp[i] = max(dp[i], dp[i - 2] + num[i]);
    		ans = max(ans, dp[i] + part[1][i + 1]);
		}
		cout << ans << endl;
	}
	
    return 0;
}