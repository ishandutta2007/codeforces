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

const int xn = 2e3 + 10;
const int xm = 1e3;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, k, dp[xn][xn], res;
string S, ans;

int main(){
	InTheNameOfGod;

	cin >> n >> k >> S, S = '.' + S;
	for (int i = 0; i < xn; ++ i)
		dp[0][i] = - 1;
	dp[0][xm] = 0;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < xn; ++ j){
			dp[i][j] = - 1;
			if (i < n && abs(j - xm) == k)
				continue;
			if ((S[i] == 'D' || S[i] == '?') && dp[i - 1][j] != - 1)
				dp[i][j] = 0;
			if ((S[i] == 'W' || S[i] == '?') && j && dp[i - 1][j - 1] != - 1)
				dp[i][j] = 1;
			if ((S[i] == 'L' || S[i] == '?') && j + 1 < xn && dp[i - 1][j + 1] != - 1)
				dp[i][j] = 2;
		}
	}
	if (dp[n][xm + k] == - 1 && dp[n][xm - k] == - 1)
		kill("NO");
	if (dp[n][xm + k] == - 1)
		k = xm - k;
	else
		k = xm + k;
	res = n;
	while (res){
		if (dp[res][k] == 0)
			ans = 'D' + ans;
		else if (dp[res][k] == 1)
			ans = 'W' + ans, -- k;
		else
			ans = 'L' + ans, ++ k;
		-- res;
	}
	cout << ans << endl;

	return 0;
}