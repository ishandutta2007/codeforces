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
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int n, a[xn], ans, f[xn], fact[xn];
int cnt[xn], ifact[xn];
bool p[xn];
vector <int> vec;

int C(int r, int n){
	if (r < 0 || n - r < 0)
		return 0;
	return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	InTheNameOfGod;
 
 	fact[0] = 1;
 	for (int i = 1; i < xn; ++ i)
 		fact[i] = 1ll * fact[i - 1] * i % mod;
 	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
 	for (int i = xn - 2; i >= 0; -- i)
 		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i], ++ cnt[a[i]];
	f[1] = (1 - power(2, n - 1, mod) + mod) % mod;
	for (int i = 2; i <= n; ++ i){
		f[i] = (f[i - 1] + C(i - 3, n - 2)) % mod;
		f[i] = (f[i] + 2ll * C(i - 2, n - 2) % mod) % mod;
		f[i] = (f[i] + C(i - 1, n - 2)) % mod;
	}
	for (int i = 2; i < xn; ++ i){
		if (p[i])
			continue;
		vec.clear();
		for (int j = i; j < xn; j += i){
			p[j] = true;
			int x = j, y = 0;
			while (x % i == 0)
				x /= i, ++ y;
			for (int k = 0; k < cnt[j]; ++ k)
				vec.push_back(y);
		}
		sort(all(vec));
		int x = n - SZ(vec);
		for (int i = 0; i < SZ(vec); ++ i)
			ans = (ans + 1ll * vec[i] * f[x + i + 1] % mod) % mod;
	}
	cout << ans << endl;
 
	return 0;
}