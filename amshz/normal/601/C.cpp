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
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 1e2 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";
 
int n, m, num[xn], sum, flag, back;
ld dp[2][xm], part[2][xm];
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	if (m == 1) kill(1);
	for (int i = 1; i <= n; ++ i) cin >> num[i], sum += num[i];
	dp[0][0] = 1;
	for (int i = 0; i < sum; ++ i) part[0][i] = 1;
	for (int i = 1; i <= n; ++ i){
		flag = i % 2, back = 1 - flag;
		part[flag][0] = dp[flag][0] = 0;
		for (int j = 1; j < sum; ++ j){
			int l = max(0, j - m), r = j - 1;
			dp[flag][j] = part[back][r];
			if (l) dp[flag][j] -= part[back][l - 1];
			if (j - num[i] >= l && j - num[i] <= r) dp[flag][j] -= dp[back][j - num[i]];
			dp[flag][j] /= m - 1;
			part[flag][j] = part[flag][j - 1] + dp[flag][j];
		}
	}
	cout << fixed << setprecision(15) << part[n % 2][sum - 1] * (m - 1) + 1 << endl;
	
	return 0;
}