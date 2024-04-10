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

ll n, num[xn], ans = 1;
bool flag[xn];
vector <ll> P[xn], vec[xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> num[i];
	for (int i = 2; i <= 2e5; ++ i){
		if (flag[i]) continue;
		P[i].push_back(i);
		for (int j = i + i; j <= 2e5; j += i){
			P[j].push_back(i);
			flag[j] = true;
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int x : P[num[i]]){
			ll y = num[i], ted = 0, s = 1;
			while (y % x == 0) y /= x, ++ ted, s *= x;
			vec[x].push_back(s);
		}
	}
	for (int i = 2; i <= 2e5; ++ i){
		if (flag[i]) continue;
		Sort(vec[i]);
		if (SZ(vec[i]) == n) ans *= vec[i][1];
		if (SZ(vec[i]) == n - 1) ans *= vec[i][0];
	}
	cout << ans << endl;
	
	return 0;
}