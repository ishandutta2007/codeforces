//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e3 + 10;
const int xm = 1e5;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, k, a[xn], ans, p[xn], part[xn][xn], dp[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], p[i] = i;
	sort(a + 1, a + n + 1);
	for (int d = 1; d * (k - 1) <= xm; ++ d){
		for (int i = n; i >= 1; -- i){
			while (p[i] <= n && a[p[i]] - a[i] < d)
				++ p[i];
			dp[1] = 1;
			part[i][1] = part[i + 1][1] + 1;
			for (int j = 2; j <= k; ++ j){
				dp[j] = 0;
				if (p[i] != i)
					dp[j] = (dp[j] + part[p[i]][j - 1]) % mod;
				part[i][j] = (part[i + 1][j] + dp[j]) % mod;
			}
			ans = (ans + dp[k]) % mod;
		}
	}
	cout << ans << endl;
			
	return 0;
}