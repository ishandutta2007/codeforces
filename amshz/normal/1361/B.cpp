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

const ll md = 1e9 + 9;
const int xn = 1e6 + 100;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

ll qq, n, p, k[xn], ind, ans, res, last;

int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n >> p;
    	for (int i = 0; i < n; ++ i) cin >> k[i];
    	if (p == 1){
    		cout << n % 2 << endl;
    		continue;
		}
    	sort(k, k + n);
    	reverse(k, k + n);
    	last = -1;
    	ans = 0, res = 0;
    	for (int i = 0; i < n; ++ i){
    		if (last != -1) ans = ans * power(p, last - k[i], MOD) % MOD;
    		if (last != -1) res = res * power(p, last - k[i], md) % md;
    		last = k[i];
    		if (ans == 0 && res == 0) ans = res = 1;
    		else ans = (ans - 1 + MOD) % MOD, res = (res - 1 + md) % md;
		}
		ans = ans * power(p, last, MOD) % MOD;
		cout << ans << endl;
	}
	
    return 0;
}