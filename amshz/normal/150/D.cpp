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

const int xn = 150 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], f[xn][xn][xn], dp[xn][xn];
string S;

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	cin >> S, S = '.' + S;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j < xn; ++ j)
			f[i][0][j] = - inf;
		for (int j = 0; j < xn; ++ j)
			f[i][1][j] = - inf;
		f[i][1][1] = 0;
		if (a[1] != - 1){
			f[i][1][0] = a[1];
			dp[i][1] = a[1];
		}
	}
	for (int t = 2; t <= n; ++ t){
		for (int l = 1; l + t - 1 <= n; ++ l){
			int r = l + t - 1;
			for (int i = 0; i < xn; ++ i)
				f[l][t][i] = - inf;
			if (S[l] == S[r])
				for (int i = 2; i <= t; ++ i)
					f[l][t][i] = f[l + 1][t - 2][i - 2];
			for (int j = 1; j < t; ++ j){
				for (int i = 0; i <= t; ++ i){
					f[l][t][i] = max(f[l][t][i], f[l][j][i] + f[l + j][t - j][0]);
					f[l][t][i] = max(f[l][t][i], f[l][j][0] + f[l + j][t - j][i]);
				}
				dp[l][t] = max(dp[l][t], dp[l][j] + dp[l + j][t - j]);
			}
			for (int i = 1; i <= t; ++ i)
				if (a[i] != - 1)
					f[l][t][0] = max(f[l][t][0], f[l][t][i] + a[i]);
			dp[l][t] = max(dp[l][t], f[l][t][0]);
		}
	}
	cout << dp[1][n] << endl;

	return 0;
}