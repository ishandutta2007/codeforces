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

//const ll md = 1e9 + 7;//998244353;
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll Md[3] = {998244353, 1000000007, 1000000009};
const int TM = 3;
const ll Base = 109661199601;

int qq, x, res, ans, a, b;
char c;
unordered_map <int, int> cnt[33];

int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> c >> x;
    	if (c != '?'){
    		res = x;
    		if (c == '+') ++ cnt[0][x];
    		else -- cnt[0][x];
    		for (int i = 0; i < 32; ++ i){
    			if ((x & (1 << i))) res -= 1 << i;
    			if (c == '+') ++ cnt[i + 1][res];
    			else -- cnt[i + 1][res];
			}
		}
		else{
			ans = res = 0;
			for (int i = 31; i >= 0; -- i){
				a = 1 << i, b = 0;
				if ((x & (1 << i))) swap(a, b);
				if (cnt[i][res + a]) res += a, ans += 1 << i;
				else res += b;
			}
			ans = max(ans, x);
			cout << ans << endl;
		}
	}
	
	
    return 0;
    
}