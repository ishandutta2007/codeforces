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
 
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int n, k, ans, num[xn], z, qq, part[xn], ps[xn];
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n >> k >> z;
    	++ k;
    	for (int i = 1; i <= n; ++ i) cin >> num[i];
    	ans = 0;
    	for (int i = 1; i <= n; ++ i) ps[i] = ps[i - 1] + num[i];
    	for (int i = 2; i <= n; ++ i) part[i] = max(part[i - 1], num[i] + num[i - 1]);
    	for (int j = 0; j <= z; ++ j){
    		if (k - j - j >= 2) ans = max(ans, ps[k - j - j] + part[k - j - j] * j);
			if (j && k - j - j + 1 >= 2) ans = max(ans, ps[k - j - j + 1] + part[k - j - j + 1] * (j - 1) + num[k - j - j]);    
		}
		cout << ans << endl;
	}
	
    return 0;
}