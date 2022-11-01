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

ll n, m, d, a[xn], ans, res, ted, ind, ptr, g, part[2][xn];
vector <int> vec[2];
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> d >> m;
    for (int i = 1; i <= n; ++ i){
    	cin >> a[i];
    	ted += (a[i] <= m);
	}
    sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i){
		if (a[i] > m) vec[1].push_back(a[i]);
		else vec[0].push_back(a[i]);
	}
	reverse(all(vec[0]));
	reverse(all(vec[1]));
	for (int i = 0; i < SZ(vec[0]); ++ i){
		part[0][i] = vec[0][i];
		if (i) part[0][i] += part[0][i - 1];
	}
	for (int i = 0; i < SZ(vec[1]); ++ i){
		part[1][i] = vec[1][i];
		if (i) part[1][i] += part[1][i - 1];
	}
	for (int i = 0; i <= SZ(vec[0]); ++ i){
		g = (n - i + d) / (d + 1);
		ll f = i;
		if (g > SZ(vec[1])){
			f += g - SZ(vec[1]);
			g = SZ(vec[1]);
		}
		res = 0;
		if (f) res += part[0][f - 1];
		if (g) res += part[1][g - 1];
		ans = max(ans, res);
	}
	cout << ans << endl;
	
    return 0;
}