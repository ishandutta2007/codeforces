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
 
const ll md = 1e9 + 7;//998244353;
const int xn = 20 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
int jaam(ll a, ll b){return (a + b) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

string ans;
char num[16] = {'0', '1', '2', '3', '4' , '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
ll Lim[xn], k, dp[xn][xn][2], fact[xn], sum, n, ted, ptr, s, t;

ll C(ll r, ll n){
	if (r < 0 || r > n) return 0;
	return fact[n] / fact[r] / fact[n - r];
}

void Solve(){
	memset(dp, 0, sizeof dp);
	for (int j = 0; j <= n; ++ j) 	dp[0][j][0] = dp[0][j][1] = 1;
	for (ll i = 1; i <= 10; ++ i){
		for (ll j = 1; j <= n; ++ j){
			for (int f = 0; f < 2; ++ f){
				for (ll l = 0; l <= min(i, Lim[n - j]); ++ l){
					if (j == n && !f) dp[i][j][f] += dp[i - l][j - 1][f] * C(l, i - 1);
					else dp[i][j][f] += dp[i - l][j - 1][f] * C(l, i);
				}
			}
		}
	}
}

int main(){
	InTheNameOfGod;
	
	fact[0] = 1;
	for (ll i = 1; i <= 20; ++ i)	fact[i] = fact[i - 1] * i;
	
	n = 16;
	cin >> k >> t;
	for (int i = 0; i < n; ++ i) Lim[i] = t;
	Solve();
	while (sum < k) 	sum += dp[++ ted][n][0];
	sum -= dp[ted][n][0];
	while (ted){
		ptr = -1;
		if (!s) ++ ptr;
		while (sum < k){
			++ ptr;
			if (!Lim[ptr]) continue;
			-- Lim[ptr];
			Solve();
			++ Lim[ptr];
			sum += dp[ted - 1][n][1];
		}
		ans += num[ptr];
		sum -= dp[ted - 1][n][1];
		-- Lim[ptr], -- ted;
		++ s;
	}
	cout << ans << endl;
	
	return 0;
}