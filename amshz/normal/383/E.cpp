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
 
const ll md = 998244353;
const int xn = 24;
const int xm = 20;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 

int n, ans, dp[1 << xn], m;
string a;

int main(){
	InTheNameOfGod;
	
	cin >> n;
	m = n;
	while (m --) cin >> a, ++ dp[(1 << (a[0] - 'a')) | (1 << (a[1] - 'a')) | (1 << (a[2] - 'a'))];
	for (int i = 0; i < 24; ++ i)
		for (int mask = 0; mask < (1 << 24); ++ mask)
			if ((mask & (1 << i)))		dp[mask] += dp[mask - (1 << i)];
	for (int mask = 0; mask < (1 << 24); ++ mask) ans = ans ^ ((n - dp[mask]) * (n - dp[mask]));
	cout << ans << endl;
	return 0;
}