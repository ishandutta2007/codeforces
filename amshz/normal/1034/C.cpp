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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244853;
const int base = 257;
 
int n, dp[xn], b[xn];
ll ans, sum, a[xn];
vector <int> adj[xn];
 
void DFS(int v){
	for (int u : adj[v])
		DFS(u), a[v] += a[u];
	if (sum / __gcd(sum, a[v]) < xn)
		++ b[sum / __gcd(sum, a[v])];
}
 
int main(){
	InTheNameOfGod;
 
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], sum += a[i];
	for (int i = 2; i <= n; ++ i){
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	DFS(1);
	for (int i = n; i >= 1; -- i)
		for (int j = i + i; j <= n; j += i)
			b[j] += b[i];
	dp[1] = 1;
	for (int i = 1; i <= n; ++ i){
		if (b[i] < i)
			dp[i] = 0;
		ans = (ans + dp[i]) % mod;
		for (int j = i + i; j <= n; j += i){
			dp[j] += dp[i];
			if (dp[j] >= mod)
				dp[j] -= mod;
		}
	}
	cout << ans << endl;
 
	return 0;
}