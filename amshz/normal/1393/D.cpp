# include <bits/stdc++.h>
 
///*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//*/
 
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
 
const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int SQ = 320;
const int sq = 500 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e14 + 10;
const int MOD = 1e9 + 7;
const int TM = 1e7;
const int BASE = 257;

int n, m, f[4][xn][xn];
ll ans;
string s[xn];

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 0; i < n; ++ i) cin >> s[i];
    for (int i = 0; i < n; ++ i)
    	for (int j = 0; j < m; ++ j)
    		for (int k = 0; k < 4; ++ k) f[k][i][j] = 1;
    for (int i = n - 1; i >= 0; -- i){
    	for (int j = m - 1; j >= 0; -- j){
    		if (i == n - 1 || j == m - 1) f[0][i][j] = 1;
    		else if (s[i][j] != s[i + 1][j] || s[i][j] != s[i][j + 1]) continue;
    		else f[0][i][j] = min(f[0][i + 1][j], f[0][i][j + 1]) + 1;
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			if (!i || !j) f[1][i][j] = 1;
			else if (s[i][j] != s[i - 1][j] || s[i][j] != s[i][j - 1]) continue;
			else f[1][i][j] = min(f[1][i - 1][j], f[1][i][j - 1]) + 1;
		}
	}
	for (int i = n - 1; i >= 0; -- i){
    	for (int j = 0; j < m; ++ j){
    		if (i == n - 1 || j == 0) f[2][i][j] = 1;
    		else if (s[i][j] != s[i + 1][j] || s[i][j] != s[i][j - 1]) continue;
    		else f[2][i][j] = min(f[2][i + 1][j], f[2][i][j - 1]) + 1;
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = m - 1; j >= 0; -- j){
			if (!i || j == m - 1) f[3][i][j] = 1;
			else if (s[i][j] != s[i - 1][j] || s[i][j] != s[i][j + 1]) continue;
			else f[3][i][j] = min(f[3][i - 1][j], f[3][i][j + 1]) + 1;
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			int x = inf;
			for (int k = 0; k < 4; ++ k){
				x = min(x, f[k][i][j]);
			}
			ans += x;
		}
	}
    cout << ans << endl;
    
    return 0;
}