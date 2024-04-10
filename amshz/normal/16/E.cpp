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
const int xn = 2e1 + 10;
const int xm = 1e6 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 
int n;
ld dp[xm], a[xn][xn], P;

 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < n; ++ j) cin >> a[i][j];
		
	dp[(1 << n) - 1] = 1;
	for (int mask = (1 << n) - 1; mask > 0; -- mask){
		int ted = __builtin_popcount(mask);
		if (ted < 2) continue;
		P = ld(1) / ld(ted * (ted - 1) / 2);
		for(int i = 0; i < n; ++ i){
			if (!(mask & (1 << i))) continue;
			for (int j = 0; j < i; ++ j){
				if (!(mask & (1 << j))) continue;
				dp[mask - (1 << j)] += dp[mask] * a[i][j] * P;
				dp[mask - (1 << i)] += dp[mask] * a[j][i] * P;
			}
		}
	}
	cout << fixed << setprecision(10);
	for (int i = 0; i < n; ++ i) cout << dp[1 << i] << sep;
	cout << endl;
	
	return 0;
}