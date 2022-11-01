# include <bits/stdc++.h>
 
using namespace std;
 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long                         ll;
typedef long double                       ld;
typedef pair <int, int>                   pii;
typedef pair <pii, int>                   ppi;
typedef pair <pii, pii>                   pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 20;
const int xm = 2e6 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 

int n, m, dp[1 << xn], a[xn][xn];
string s;

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> s;
	for (int i = 1; i < n; ++ i)
		++ a[s[i] - 'a'][s[i - 1] - 'a'], ++ a[s[i - 1] - 'a'][s[i] - 'a'];
	for (int mask = 1; mask < (1 << m); ++ mask){
		dp[mask] = inf;
		int ted = __builtin_popcount(mask);
		for (int i = 0; i < m; ++ i){
			if (!(mask & (1 << i))) continue;
			int cost = dp[mask - (1 << i)];
			for (int j = 0; j < m; ++ j){
				if (i == j) continue;
				if ((mask & (1 << j))) cost -= a[i][j] * (m - ted + 1);
				else cost += a[i][j] * (m - ted + 1);
			}
			dp[mask] = min(dp[mask], cost);
		}
	}
	cout << dp[(1 << m) - 1] << endl;
	
	return 0;
}