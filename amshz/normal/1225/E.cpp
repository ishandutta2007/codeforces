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
const int xn = 2e3 + 10;
const int xm = 20;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 

int n, m, ps[xn][xn][2];
ll dp[xn][xn][2], part[xn][xn][2], ans;
string a[xn];


int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i], a[i] = '.' + a[i];
	if (n == 1 && m == 1) Kill(1);
	dp[1][1][0] = dp[1][1][1] = part[1][1][0] = part[1][1][1] = 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			ps[i][j][0] = ps[i][j - 1][0] + (a[i][j] == 'R');
			ps[i][j][1] = ps[i - 1][j][1] + (a[i][j] == 'R');
		}
	}
	for (int j = 2; j <= m; ++ j){
		int ted = ps[1][m][0] - ps[1][j][0];
		ted = m - j - ted;
		if (ps[1][j][0] <= ted) dp[1][j][0] = 1;
		part[1][j][0] = dp[1][j][0]; 
	}
	for (int i = 2; i <= n; ++ i){
		int ted = ps[n][1][1] - ps[i][1][1];
		ted = n - i - ted;
		if (ps[i][1][1] <= ted) dp[i][1][1] = 1;
		part[i][1][1] = dp[i][1][1];
	}
	for (int i = 2; i <= n; ++ i){
		for (int j = 2; j <= m; ++ j){
			int ted = ps[i][m][0] - ps[i][j][0];
			ted = m - j - ted;
			int L = 0, R = j + 1, Mid;
			while (R - L > 1){
				Mid = (L + R) / 2;
				if (ps[i][j][0] - ps[i][Mid][0] > ted) L = Mid;
				else R = Mid;
			}
			if (L < j) dp[i][j][0] = (part[i][j - 1][1] - part[i][L][1] + md) % md;
			ted = ps[n][j][1] - ps[i][j][1], ted = n - i - ted;
			L = 0, R = i + 1, Mid;
			while (R - L > 1){
				Mid = (L + R) / 2;
				if (ps[i][j][1] - ps[Mid][j][1] > ted) L = Mid;
				else R = Mid;
			}
			if (L < i) dp[i][j][1] = (part[i - 1][j][0] - part[L][j][0] + md) % md;
			part[i][j][0] = (part[i - 1][j][0] + dp[i][j][0] + md) % md;
			part[i][j][1] = (part[i][j - 1][1] + dp[i][j][1] + md) % md;
		}
	}
	ans = (dp[n][m][0] + dp[n][m][1] + md) % md;
	cout << ans << endl;
	
	return 0;
}