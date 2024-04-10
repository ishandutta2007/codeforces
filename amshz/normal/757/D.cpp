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

const int xn = 76;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, dp[xn][1 << xm], ans;
string S;

int main(){
	InTheNameOfGod;

	cin >> n >> S;
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++ i){
		int sum = - 1;
		for (int j = i - 1; j >= 0; -- j){
			if (S[j] == '1' && i - j > 20)
				break;
			if (S[j] == '1')
				sum += (1 << (i - j - 1));
			if (sum > 19)
				break;
			if (sum < 0)
				continue;
			for (int mask = 0; mask < (1 << xm); ++ mask){
				if (!(mask & (1 << sum)))
					continue;
				dp[i][mask] = (dp[i][mask] + dp[j][mask]) % mod;
				dp[i][mask] = (dp[i][mask] + dp[j][mask ^ (1 << sum)]) % mod;
			}
		}
		dp[i][0] = 1;
	}
	for (int j = 1; j <= n; ++ j){
		int sum = 0;
		for (int i = 0; i < xm; ++ i)
			sum += (1 << i), ans = (ans + dp[j][sum]) % mod;
	}
	cout << ans << endl;

	return 0;
}