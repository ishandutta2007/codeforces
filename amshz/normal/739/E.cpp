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
typedef pair <ld , int>                                  pii;
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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ld INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, a, b, qq = 60;
ld p[xn], u[xn];
pii dp[xn][xn];

pii calc(ld t){
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j <= i; ++ j){
			dp[i][j] = {0, 0};
			dp[i][j] = max(dp[i][j], {dp[i - 1][j].A + u[i] + t, dp[i - 1][j].B - 1});
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (!j)
				continue;
			dp[i][j] = max(dp[i][j], {dp[i - 1][j - 1].A + p[i], dp[i - 1][j - 1].B});
			dp[i][j] = max(dp[i][j], {dp[i - 1][j - 1].A + p[i] + u[i] - p[i] * u[i] + t, dp[i - 1][j - 1].B - 1});
		}
	}
	return dp[n][a];
}

int main(){
	InTheNameOfGod;

	cin >> n >> a >> b;
	for (int i = 0; i <= n; ++ i)
		for (int j = 0; j <= n; ++ j)
			if (i || j)
				dp[i][j] = {- INF, inf};
	for (int i = 1; i <= n; ++ i)
		cin >> p[i];
	for (int i = 1; i <= n; ++ i)
		cin >> u[i];
	ld l = - inf, r = inf;
	while (qq --){
		ld mid = (l + r) / 2;
		if (b < - calc(mid).B)
			r = mid;
		else
			l = mid;
	}
	cout << calc(l).A - l * b << endl;

	return 0;
}