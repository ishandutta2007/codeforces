//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e5 + 10;
const int xm = 60;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, cnt[xn], qq, ans, res, a[xn];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		for (int i = 0; i < xm; ++ i)
			cnt[i] = 0;
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			for (ll bit = 0; bit < xm; ++ bit)
				if ((a[i] & (1LL << bit)))
					++ cnt[bit];
		}
		for (int i = 1; i <= n; ++ i){
			res = 0;
			for (ll bit = 0; bit < xm; ++ bit){
				if ((a[i] & (1LL << bit)))
					res = (res + (1LL << bit) % mod * n % mod) % mod;
				else
					res = (res + (1LL << bit) % mod * cnt[bit] % mod) % mod;
			}
			for (ll bit = 0; bit < xm; ++ bit)
				if ((a[i] & (1LL << bit)))
					ans = (ans + (1LL << bit) % mod * res % mod * cnt[bit] % mod) % mod;
		}
		cout << ans << endl;
	}
			
	return 0;
}