//khodaya khodet komak kon
//# pragma GCC optimize("O2")
//# pragma GCC optimize("Ofast")
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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, ans[52][52], dp[53][xn], knap[53][xn];
int fact[xn], ifact[xn], cnt[52], sum, res;
string s;

int C(int r, int n){
	if (r < 0 || n - r < 0)
		return 0;
	return 1LL * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}
int f(char c){
	if (c - 'A' < 26 && c - 'A' >= 0)
		return c - 'A';
	return c - 'a' + 26;
}

int main(){
	InTheNameOfGod;
	
	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1LL * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
	cin >> s >> q;
	for (char c : s)
		++ cnt[f(c)];
	n = SZ(s), s = '.' + s;
	knap[52][0] = 1;
	for (int i = 51; i >= 0; -- i){
		sum += cnt[i];
		for (int j = n / 2; j >= 0; -- j){
			knap[i][j] = 1LL * knap[i + 1][j] * C(cnt[i], sum - j) % mod;
			if (cnt[i] <= j && cnt[i])
				knap[i][j] = (knap[i][j] + 1LL * C(cnt[i], j) * knap[i + 1][j - cnt[i]] % mod) % mod;
		}
	}
	dp[0][0] = 1;
	for (int k = 0; k < 52; ++ k){
		sum = 0;
		for (int i = 1; i < 53; ++ i){
			sum += cnt[i - 1];
			for (int j = n / 2; j >= 0; -- j){
				dp[i][j] = 1LL * dp[i - 1][j] * C(cnt[i - 1], sum - j) % mod;
				if (i > k){
					res = 1LL * dp[i][j] * knap[i][n / 2 - j] % mod;
					res = 2LL * res * C(j, n / 2) % mod * C(sum - j, n / 2) % mod;
					ans[k][i - 1] = (ans[k][i - 1] + res) % mod;
				}
				if (cnt[i - 1] <= j && cnt[i - 1] && i - 1 != k)
					dp[i][j] = (dp[i][j] + 1LL * C(cnt[i - 1], j) * dp[i - 1][j - cnt[i - 1]] % mod) % mod;
			}
			if (i > k)
				ans[i - 1][k] = ans[k][i - 1];
		}
	}
	while (q --){
		int x, y;
		cin >> x >> y;
		cout << ans[f(s[x])][f(s[y])] << endl;
	}
	
	return 0;
}