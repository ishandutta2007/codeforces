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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, fact[xn], ifact[xn], part[2][xn], ted, ans, cnt[3][xn];
string S;

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
	cin >> S, n = SZ(S), S = '.' + S;
	for (char c : S)
		ted += c == '?';
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j < 3; ++ j)
			cnt[j][i] = cnt[j][i - 1];
		cnt[0][i] += (S[i] == '(');
		cnt[1][i] += (S[i] == ')');
		cnt[2][i] += (S[i] == '?');
	}
	part[0][0] = part[1][0] = 1;
	for (int i = 1; i < xn; ++ i){
		part[0][i] = (part[0][i - 1] + C(i, ted)) % mod;
		part[1][i] = (part[1][i - 1] + C(i, ted - 1)) % mod;
	}
	for (int i = 1; i <= n; ++ i){
		if (S[i] == '(')
			continue;
		int res = cnt[2][i - 1] + cnt[0][i - 1] - cnt[1][n] + cnt[1][i] - 1;
		if (res < 0)
			continue;
		if (S[i] == ')')
			ans = (ans + part[0][res]) % mod;
		else
			ans = (ans + part[1][res]) % mod;
	}
	cout << ans << endl;

	return 0;
}