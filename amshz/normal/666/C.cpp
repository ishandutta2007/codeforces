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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 450;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int q, m, n, fact[xn], ifact[xn], inv, dp[sq][xn], ptr, col[xn];
string s;

int C(int r, int n){
	if (r < 0 || n - r < 0)
		return 0;
	return ll(fact[n]) * ll(ifact[r]) % mod * ll(ifact[n - r]) % mod;
}
void solve(){
	col[m] = ptr ++;	
	for (int i = 1; i < xn; ++ i)
		dp[col[m]][i] = (ll(dp[col[m]][i - 1]) * ll(inv) + ll(C(m - 1, i - 1))) % mod;
}

int main(){
	InTheNameOfGod;
	
	inv = 26LL * ll(power(25, mod - 2, mod)) % mod;
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < xn; ++ i){
		fact[i] = ll(fact[i - 1]) * ll(i) % mod;
		ifact[i] = power(fact[i], mod - 2, mod);
	}
	cin >> q >> s;
	m = SZ(s), solve();
	while (q --){
		int t;
		cin >> t;
		if (t == 1){
			cin >> s;
			m = SZ(s);
			if (col[m])
				continue;
			solve();
		}
		else{
			cin >> n;
			cout << ll(dp[col[m]][n]) * ll(power(25, n - m, mod)) % mod << endl;
		}
	}
			
	return 0;
}