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
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, fact[xn], ifact[xn], ans, a[xn];

ll C(ll r, ll n){
	if (r < 0 || r > n)
		return 0;
	return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n + n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + n + 1);
	for (int i = 1; i <= n + n; ++ i){
		if (i <= n)
			ans = (ans - a[i] + mod) % mod;
		else
			ans = (ans + a[i]) % mod;
	}
	fact[0] = ifact[0] = 1;
	for (ll i = 1; i < xn; ++ i){
		fact[i] = fact[i - 1] * i % mod;
		ifact[i] = power(fact[i], mod - 2, mod);
	}
	cout << C(n, n + n) * ans % mod;
			
	return 0;
}