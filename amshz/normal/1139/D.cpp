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

ll n, ans, dp[xn], res, zr[xn];
vector <ll> magh[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (ll i = 1; i <= n; ++ i)
		for (ll j = i; j <= n; j += i)	magh[j].push_back(i);
	for (ll i = 1; i <= n; ++ i) reverse(all(magh[i]));
	for (ll i = 2; i <= n; ++ i){
		res = n;
		for (ll j = 0; j < SZ(magh[i]); ++ j){
			zr[j] = n / magh[i][j];
			for (ll k = 0; k < j; ++ k)
				if (magh[i][k] % magh[i][j] == 0)
					zr[j] -= zr[k];
			res = (res + zr[j] * dp[magh[i][j]] % md) % md;
		}
		dp[i] = res * power(n - zr[0], md - 2) % md;
		ans = (ans + dp[i]) % md;
	}
	ans = (ans * power(n, md - 2) + 1) % md;
	cout << ans << endl;
	return 0;
}