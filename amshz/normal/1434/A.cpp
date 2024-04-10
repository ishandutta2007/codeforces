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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, m = 6, a[xn], b[xn], ans = inf;

int main(){
	InTheNameOfGod;
	
	for (int i = 1; i <= 6; ++ i) 
		cin >> a[i];
	sort(a + 1, a + 6 + 1);
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> b[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= 6; ++ i){
		for (int j = 1; j <= n; ++ j){
			int val = b[j] - a[i], mx = 0, last = n + 1;
			for (int k = 6; k >= 1; -- k){
				int l = 0, r = last, mid;
				while (r - l > 1){
					mid = l + r >> 1;
					if (b[mid] - a[k] >= val) r = mid;
					else l = mid;
				}
				mx = max(mx, b[last - 1] - a[k]);
				last = r;
			}
			if (last > 1) continue;
			ans = min(ans, mx - val);
		}
	}
	cout << ans << endl;
	
	return 0;
}