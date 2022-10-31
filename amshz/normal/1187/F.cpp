// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, ans, sum, b[xn];
pii a[xn];

ll toole(pii a){ return a.B - a.A + 1;}
ll share(pii a, pii b){ return max(0, min(a.B, b.B) - max(a.A, b.A) + 1);}


int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].B;
	for (int i = 1; i <= n; ++ i){
		b[i] = share(a[i], a[i + 1]);
		b[i] = b[i] * power(toole(a[i]), mod - 2, mod) % mod;
		b[i] = b[i] * power(toole(a[i + 1]), mod - 2, mod) % mod;
		b[i] = (1 - b[i] + mod) % mod;
		ans = (ans + 1LL * b[i] * sum % mod) % mod;
		sum = (sum + b[i - 1]) % mod;
	}
	for (int i = 1; i < n; ++ i){
		ll res = share(a[i], a[i + 1]);
		res = res * power(toole(a[i]), mod - 2, mod) % mod;
		res = res * power(toole(a[i + 1]), mod - 2, mod) % mod;
		ans = (ans - res + mod) % mod;
		res = share(a[i + 1], a[i + 2]);
		res = res * power(toole(a[i + 1]), mod - 2, mod) % mod;
		res = res * power(toole(a[i + 2]), mod - 2, mod) % mod;
		ans = (ans - res + mod) % mod;
		res = min(a[i].B, min(a[i + 1].B, a[i + 2].B));
		res = max(0LL, res - max(a[i].A, max(a[i + 1].A, a[i + 2].A)) + 1);
		res = res * power(toole(a[i]), mod - 2, mod) % mod;
		res = res * power(toole(a[i + 1]), mod - 2, mod) % mod;
		res = res * power(toole(a[i + 2]), mod - 2, mod) % mod;
		ans = (ans + res + 1) % mod;
	}
	ans = ans * 2LL % mod;
	for (int i = 1; i <= n; ++ i)
		ans = (ans + b[i]) % mod;
	cout << ans << endl;
		
	return 0;
}