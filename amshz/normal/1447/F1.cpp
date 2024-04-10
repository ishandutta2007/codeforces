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
 
const int xn = 2e5 + 10;
const int xm = 1e2 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], part[xm][xn], ptr, ans;
int cnt[xm], last[xm][xn + xn], mx1, mx2;

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ++ cnt[a[i]];
	for (int j = 1; j <= 100; ++ j)
		for (int i = 1; i <= n; ++ i)
			part[j][i] = part[j][i - 1] + (a[i] == j);
	for (int i = 1; i <= 100; ++ i)
		if (cnt[i] > cnt[mx1])
			mx1 = i;
	for (int j = 1; j <= 100; ++ j){
		for (int i = 1; i <= n; ++ i){
			int x = part[mx1][i] - part[j][i];
			last[j][x + xn] = i;
		}
	}
	for (int j = 1; j <= 100; ++ j){
		if (j == mx1)
			continue;
		for (int i = 0; i < n; ++ i){
			int x = part[mx1][i] - part[j][i];
			ans = max(ans, last[j][x + xn] - i);
		}
	}
	cout << ans << endl;
	
	return 0;
}