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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int TM = 3;
const int base = 257;

int qq, n, k, x, y;
string s;
bool flag[xn][2], ans;

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n >> k >> s;
		s = '.' + s;
		x = y = 0;
		for (int i = 1; i <= k; ++ i){
			if (s[i] == '?') continue;
			if (s[i] == '0') ++ x;
			else ++ y;
		}
		for (int i = 0; i < k; ++ i) flag[i][0] = flag[i][1] = false;
		for (int i = 1; i <= n; ++ i) if (s[i] != '?') flag[i % k][s[i] - '0'] = 1;
		ans = true;
		for (int i = 1; i <= k; ++ i){
			if (flag[i % k][0] && flag[i % k][1]) ans = false;
			if (s[i] != '?') continue;
			if (flag[i % k][0]) ++ x;
			if (flag[i % k][1]) ++ y;
		}
		ans &= (max(x, y) <= k / 2);
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
 
    return 0;
}