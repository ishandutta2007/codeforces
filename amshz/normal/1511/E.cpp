// khodaya khodet komak kon
// Maybe on the Moon
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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, dp[xn], ted, res, pw[xn], ans;
string S[xn];

int main(){
	InTheNameOfGod;

	pw[0] = 1;
	for (int i = 1; i < xn; ++ i)
		pw[i] = 2ll * pw[i - 1] % mod;
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		cin >> S[i], S[i] = '.' + S[i];
		for (int j = 1; j <= m; ++ j)
			ted += S[i][j] == 'o';
	}
	for (int i = 1; i <= n; ++ i){
		dp[0] = 1, res = 0;
		for (int j = 1; j <= m; ++ j){
			dp[j] = 0;
			if (S[i][j] == '*')
				res = 0, dp[j] = 1;
			else{
				++ res;
				if (j > 1 && res > 1)
					dp[j] = (dp[j - 2] + pw[res - 2]) % mod;
				ans = (ans + 1ll * dp[j] * pw[ted - res] % mod) % mod;
			}
		}
	}
	for (int i = 1; i <= m; ++ i){
		dp[0] = 1, res = 0;
		for (int j = 1; j <= n; ++ j){
			dp[j] = 0;
			if (S[j][i] == '*')
				res = 0, dp[j] = 1;
			else{
				++ res;
				if (j > 1 && res > 1)
					dp[j] = (dp[j - 2] + pw[res - 2]) % mod;
				ans = (ans + 1ll * dp[j] * pw[ted - res] % mod) % mod;
			}
		}
	}
	cout << 1ll * ans * power(2, mod - 2, mod) % mod << endl;

	return 0;
}