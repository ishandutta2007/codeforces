# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 11 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m, dp[xn][1 << xn], ans = inf, res;
string s[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < n; ++ i)
		cin >> s[i];
	for (int i = 0; i < m; ++ i){
		res = 0;
		for (int j = 0; j < n; ++ j)
			if (s[j][i] == '1')
				res += 1 << j;
		++ dp[0][res];
	}
	for (int b = 0; b < n; ++ b)
		for (int i = n; i > 0; -- i)
			for (int mask = 0; mask < 1 << n; ++ mask)
				dp[i][mask] += dp[i - 1][mask ^ (1 << b)];
	for (int mask = 0; mask < 1 << n; ++ mask){
		res = 0;
		for (int i = 0; i <= n; ++ i)
			res += min(i, n - i) * dp[i][mask];
		ans = min(ans, res);
	}
	cout << ans << endl;
	
	return 0;
}