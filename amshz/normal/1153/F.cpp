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
 
const ll md = 998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e10 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, k, l, dp[xn], fact[xn], ifact[xn], ans, inv, res;

ll C(ll r, ll n){
	if (r < 0 || r > n || n <= 0) return 0;
	return fact[n] * (ifact[r] * ifact[n - r] % md) % md;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k >> l;
	dp[0] = 1;
	for (ll i = 2; i < xn; i += 2)
		dp[i] = (dp[i - 2] * (i - 1) % md);
	fact[0] = ifact[0] = 1;
	for (ll i = 1; i < xn; ++ i){
		fact[i] = fact[i - 1] * i % md;
		ifact[i] = power(fact[i], md - 2);
	}
	for (ll i = 1; i < n + n; ++ i){
		for (ll j = k; j <= min(i, n + n - i); ++ j){
			res = C(j, i) * C(j, n + n - i) % md;
			res = res * (dp[i - j] * dp[n + n - i - j] % md) % md;
			res = res * fact[j] % md;
			ans = (ans + res) % md;
		}
	}
	ans = ans * power(dp[n + n], md - 2) % md;
	ans = ans * (l * power(n + n + 1, md - 2) % md) % md;
	cout << ans << endl;
	
	return 0;
}