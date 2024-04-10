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
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";

string a, b;
ld n, ans, tot, part[2][26][xn];

int main(){
	InTheNameOfGod;
	
	cin >> n >> a >> b;
	for (ll i = 0; i < 26; ++ i){
		for (ll j = n - 1; j >= 0; -- j){
			part[1][i][j] = part[1][i][j + 1];
			if (a[j] - 'A' == i)	part[1][i][j] += n - j;
		}
	}
	for (ll i = 0; i < 26; ++ i){
		part[0][i][0] = (a[0] - 'A' == i);
		for (ll j = 1; j < n; ++ j){
			part[0][i][j] = part[0][i][j - 1];
			if (a[j] - 'A' == i)	part[0][i][j] += j + 1;
		}
	}
	for (ll i = 1; i <= n; ++ i)	tot += i * i;
	for (ll i = 0; i < n; ++ i){
		ans += part[0][b[i] - 'A'][i] * (n - i) / tot;
		ans += part[1][b[i] - 'A'][i + 1] * (i + 1) / tot;
	}
	cout << fixed << setprecision(15) << ans << endl;
	
	return 0;
}