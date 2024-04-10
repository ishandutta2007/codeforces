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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, pw[xn], ans, p[xn];
vector <pii> dp[xn];

int main(){
	InTheNameOfGod;

	cin >> n >> k;
	for (int i = n + n; i >= 1; -- i){
		for (int j = 1; j * i < n + n; ++ j){
			p[i * j] = j - 1;
			dp[i].push_back({i * j, max(0, min(j - 1, (n - 1) / i) - max(1, j - (n - 1) / i) + 1)});
		}
		for (int j = i + i; j < n + n; j += i)
			for (pii k : dp[j])
				dp[i][p[k.A]].B -= k.B;
	}
	pw[0] = 1;
	for (int i = 1; i < xn; ++ i)
		pw[i] = 1LL * pw[i - 1] * k % mod;
	for (int i = 1; i < n; ++ i)
		for (pii j : dp[i])
			ans = (ans + 1LL * pw[max(i, j.A - n)] * j.B % mod) % mod;
	cout << 1LL * ans * power(pw[n], mod - 2, mod) % mod << endl;
	
	return 0;
}