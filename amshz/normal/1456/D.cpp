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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const ll inf = 1e18 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, dp[3][xn];
pll a[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A >> a[i].B;
	dp[1][0] = dp[2][0] = inf;
	for (int i = 1; i <= n; ++ i){
		dp[0][i] = inf;
		if (dp[0][i - 1] + abs(a[i - 1].B - a[i].B) <= a[i].A)
			dp[0][i] = a[i].A;
		if (dp[2][i - 1] + abs(a[i - 1].B - a[i].B) <= a[i].A)
			dp[0][i] = a[i].A;
		if (i > 1 && dp[1][i - 1] + abs(a[i - 2].B - a[i].B) <= a[i].A)
			dp[0][i] = a[i].A;
		dp[2][i] = max(dp[2][i - 1] + abs(a[i - 1].B - a[i].B), a[i - 1].A);
		dp[2][i] = min(dp[2][i], max(dp[1][i - 1] + abs(a[i - 2].B - a[i].B), a[i - 1].A));
		dp[2][i] = min(dp[2][i], dp[0][i - 1] + abs(a[i - 1].B - a[i].B));
		if (dp[2][i] > a[i].A)
			dp[2][i] = inf;
		dp[1][i] = inf;
		bool flag = true;
		for (int j = i - 2; j >= 0; -- j){
			if (j + 1 < i - 1)
				flag &= abs(a[j + 2].B - a[j + 1].B) <= abs(a[j + 2].A - a[j + 1].A);
			if (!flag)
				break;
			ll x = inf;
			x = min(x, dp[0][j] + abs(a[j].B - a[i].B));
			if (j)
				x = min(x, max(dp[1][j] + abs(a[j - 1].B - a[i].B), a[j].A));
			x = min(x, max(dp[2][j] + abs(a[j].B - a[i].B), a[j].A));
			if (x > a[i].A)
				continue;
			if (x + abs(a[i].B - a[j + 1].B) > a[j + 1].A)
				continue;
			dp[1][i] = a[i - 1].A;
		}
	}
	if (min(dp[0][n], min(dp[1][n], dp[2][n])) < inf)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
			
	return 0;
}