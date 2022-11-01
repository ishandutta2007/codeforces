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
# define rc                                              id << 1 | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 4e3 + 10;
const int xm = 1e7 + 10;
const int sq = 100;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e6;
const ll base = 4e3 + 10;

int n, a[xn];
unordered_map <int, int> dp[2][sq][xn];


int DFS(int l, int r, int f, int i){
	if (dp[f][i][l].count(r)) return dp[f][i][l][r];
	dp[f][i][l][r] = 0;
	if (l + r + i > n) return dp[f][i][l][r];
	if (f) dp[f][i][l][r] = DFS(l, r + i, !f, i) - a[n - r] + a[n - r - i];
	else dp[f][i][l][r] = DFS(l + i, r, !f, i) + a[l + i] - a[l];
	if (l + r + i == n) return dp[f][i][l][r];
	if (f) dp[f][i][l][r] = min(dp[f][i][l][r], DFS(l, r + i + 1, !f, i + 1)- a[n - r] + a[n - r - i - 1]);
	else dp[f][i][l][r] = max(dp[f][i][l][r], DFS(l + i + 1, r, !f, i + 1)+ a[l + i + 1] - a[l]);
	return dp[f][i][l][r];
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], a[i] += a[i - 1];
	cout << DFS(0, 0, 0, 1) << endl;
	
	return 0;
}