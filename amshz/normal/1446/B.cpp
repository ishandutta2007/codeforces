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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, ans, dp[xn][xn];
pii last[30][xn];
string s, t;

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> s >> t;
	s = '.' + s;
	t = '.' + t;
	for (int c = 0; c < 26; ++ c){
		for (int i = 1; i <= n; ++ i){
			last[c][i].A = last[c][i - 1].A;
			if (s[i] - 'a' == c)
				last[c][i].A = i;
		}
	}
	for (int c = 0; c < 26; ++ c){
		for (int i = 1; i <= m; ++ i){
			last[c][i].B = last[c][i - 1].B;
			if (t[i] - 'a' == c)
				last[c][i].B = i;
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - 2);
			int x = last[s[i] - 'a'][j].B;
			dp[i][j] = max(dp[i][j], dp[i][x] - j + x);
			x = last[t[j] - 'a'][i].A;
			dp[i][j] = max(dp[i][j], dp[x][j] - i + x);
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1] + 2;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}