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
 
const int xn = 3e2 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int qq, n, m, num[xn][xn], ted;
bool flag;

bool check(int i, int j){return (i >= 1 && j >= 1 && i <= n && j <= m);}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n >> m;
    	for (int i = 1; i <= n; ++ i) for (int j = 1; j <= m; ++ j) cin >> num[i][j];
    	flag = true;
    	for (int i = 1; i <= n; ++ i){
    		for (int j = 1; j <= m; ++ j){
    			ted = 0;
    			ted += check(i - 1, j);
    			ted += check(i + 1, j);
    			ted += check(i, j - 1);
    			ted += check(i, j + 1);
    			flag &= num[i][j] <= ted;
    			num[i][j] = ted;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
		if (!flag) continue;
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j) cout << num[i][j] << sep;
			cout << endl;
		}
	}
	
    return 0;
}