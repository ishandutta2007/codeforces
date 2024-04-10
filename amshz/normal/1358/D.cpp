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
typedef pair <ld, ld>                                  pll;
 
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
const int xn = 4e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, x, num[xn], ans, part[xn], ps[xn], res;

int main(){
    InTheNameOfGod;
    
    cin >> n >> x;
    for (int i = 0; i < n; ++ i)	cin >> num[i];
    for (int i = n; i < n + n; ++ i)	num[i] = num[i - n];
    part[0] = num[0];
    for (int i = 1; i < n + n; ++ i)	part[i] = part[i - 1] + num[i];
    ps[0] = (num[0] * (num[0] + 1)) / 2;
    for (int i = 1; i < n + n; ++ i)	ps[i] = ps[i - 1] + (num[i] * (num[i] + 1)) / 2;
    for (int i = 0; i < n; ++ i){
    	ll L = 0, R = n, mid;
    	while (R - L > 1){
    		mid = (L + R) / 2;
    		if (part[i + mid] - part[i] <= x - 1) L = mid;
    		else R = mid;
		}
		res = ps[i + L] - ps[i] + num[i];
		ll y = x - 1 - (part[i + L] - part[i]);
		y = y * (y + 1) / 2;
		res += y;
		ans = max(ans, res);
	}
	for (int i = n; i < n + n; ++ i){
		ll L = 0, R = n + 1, mid;
		while (R - L > 1){
			mid = (L + R) / 2;
			if (part[i] - part[i - mid] <= x) L = mid;
			else R = mid;
		}
		res = ps[i] - ps[i - L];
		ll y = x - (part[i] - part[i - L]);
		y = num[i - L] - y;
		y = y * (y + 1) / 2;
		y = (num[i - L] + 1) * num[i - L] / 2 - y;
		res += y;
		ans = max(ans, res);
	}
	cout << ans << endl;
    
    return 0;
}