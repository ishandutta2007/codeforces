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
const int xn = 5e2 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
int jaam(ll a, ll b){return (a + b) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, m, adj[xn][xn], ans, index[xn][xn];
string num[xn];
vector <int> dp[xn][xn];
vector <pii> vec[xm];

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> num[i], num[i] = '#' + num[i];
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			index[i][j] = SZ(vec[i + j]), vec[i + j].push_back({i, j});
	if (num[1][1] != num[n][m]) Kill(0);
	dp[1][1].push_back(1);
	for (int i = 3; i <= n + m; ++ i){
		if (n + m + 2 - i < i) break;
		for (pii x : vec[i]){
			dp[x.A][x.B].resize(SZ(vec[n + m + 2 - i]));
			for (int j = 0; j < SZ(vec[n + m + 2 - i]); ++ j){
				pii y = vec[n + m + 2 - i][j];
				if (num[x.A][x.B] != num[y.A][y.B]) continue;
				if (x.A > 1 && y.A < n) dp[x.A][x.B][j] = jaam(dp[x.A][x.B][j], dp[x.A - 1][x.B][index[y.A + 1][y.B]]);
				if (x.A > 1 && y.B < m) dp[x.A][x.B][j] = jaam(dp[x.A][x.B][j], dp[x.A - 1][x.B][index[y.A][y.B + 1]]);
				if (x.B > 1 && y.A < n) dp[x.A][x.B][j] = jaam(dp[x.A][x.B][j], dp[x.A][x.B - 1][index[y.A + 1][y.B]]);
				if (x.B > 1 && y.B < m) dp[x.A][x.B][j] = jaam(dp[x.A][x.B][j], dp[x.A][x.B - 1][index[y.A][y.B + 1]]);
				int d = (abs(x.A - y.A) + abs(x.B - y.B));
				if (d < 2) ans = jaam(ans, dp[x.A][x.B][j]);
			}
		}
		for (pii x : vec[i - 1]) dp[x.A][x.B].resize(0);
	}
	cout << ans << endl;
	
	return 0;
}