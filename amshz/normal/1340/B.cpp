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
typedef pair <int, int>                    pii;
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
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, k, adj[xn][10], dp[xn][xn], par[xn][xn];
string a[xn], s[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011",  "1101111", "1010010", "1111111", "1111011"}, ans;

int fn1(string x, string y){
	int ted = 0;
	for (int i = 0; i < 7; ++ i){
		if (x[i] == y[i]) continue;
		if (x[i] == '1') return -1 + 7;
		++ ted;
	}
	return ted + 7;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = n; i >= 1; -- i) cin >> a[i];
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++ i) for (int j = 0; j < 10; ++ j) adj[i][j] = fn1(a[i], s[j]) - 7;
	for (int i = 1; i <= k; ++ i) dp[0][i] = -1;
	dp[0][1] = -1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j <= k; ++ j){
			for (int l = 0; l < 10; ++ l){
				if (adj[i][l] == -1) continue;
				if (adj[i][l] > j || dp[i - 1][j - adj[i][l]] == -1) continue;
				dp[i][j] = l;
				par[i][j] = j - adj[i][l];
			}
		}
	}
	int x = n, y = k;
	if (dp[n][k] == -1) Kill(-1);
	while (x){
		ans += char('0' + dp[x][y]);
		y = par[x][y];
		-- x;
	}
	cout << ans << endl;
	return 0;
}