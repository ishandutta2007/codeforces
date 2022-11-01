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
typedef pair <ll, ll>                     pii;
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
 
const ll md = 1e9 + 7;//998244353;
const int xn = 1e3 + 10;
const int xm = 2e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, m, x, dp[xn][xn], Catalan[xn][xn], fact[xm], ifact[xm], ans, s, g, w;

ll C(ll r, ll n){
	if (r > n || r < 0) return 0;
	return zarb(fact[n], zarb(ifact[r], ifact[n - r]));
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> x;
	if (n > m) Kill(0);
	fact[0] = ifact[0] = 1;
	for (ll i = 1; i < xm; ++ i){
		fact[i] = zarb(fact[i - 1], i);
		ifact[i] = power(fact[i], md - 2);
	}
	for (int k = 1; k <= n + n; ++ k){
		dp[0][0] = 1;
		Catalan[0][k] = 1;
		for (int i = 1; i <= n + n; ++ i){
			for (int j = 0; j <= n; ++ j){
				if (j > i) break;
				dp[i][j] = 0;
				if (j) dp[i][j] = dp[i - 1][j - 1];
				if (i != k) dp[i][j] = jaam(dp[i][j], dp[i - 1][j + 1]);
			}
			Catalan[i][k] = dp[i][0];
		}
	}
	for (int i = n; i <= n + n; ++ i){
		if (i > m) break;
		s = n + n - i;
		ans = jaam(ans, zarb(zarb(C(s - 1, i - 1), Catalan[i - s][1]), C(i - 1, m - 1)));
		for (int j = 1; j <= i; ++ j){
			if (j > x) break;
			g = zarb(C(j - 1, x - 1), C(i - j, m - x));
			for (int k = 0; k <= min(s, ll(j - 1)); ++ k){
				w = zarb(C(k, j - 1), C(s - k, i - j));
				w = zarb(w, zarb(g, Catalan[i - s][j - k]));
				ans = jaam(ans, w);
			}
		}
	}
	cout << zarb(ans, fact[n]) << endl;
	return 0;
}