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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod[3] = {998244353, 1000000007, 1000696969};
const ll base = 10;

int n;
string s, ans;
ll part[3][xn], pw[3][xn], inv[3][xn], Inv[3];

ll get(int l, int r, int id){ return (part[id][l] - part[id][r + 1] + mod[id]) % mod[id] * inv[id][n - r] % mod[id];}

void check(int x, int y, int z){
	if (x < 1 || y < 1 || z < 1 || SZ(ans))
		return;
	if (x > 1 && s[1] == '0')
		return;
	if (y > 1 && s[x + 1] == '0')
		return;
	if (z > 1 && s[x + y + 1] == '0')
		return;
	for (int i = 0; i < 3; ++ i)
		if ((get(1, x, i) + get(x + 1, x + y, i)) % mod[i] != get(x + y + 1, n, i))
			return;
	for (int i = 1; i <= x; ++ i)
		ans += s[i];
	ans += '+';
	for (int i = x + 1; i <= x + y; ++ i)
		ans += s[i];
	ans += '=';
	for (int i = x + y + 1; i <= n; ++ i)
		ans += s[i];
}

int main(){
	InTheNameOfGod;
	
	cin >> s;
	n = SZ(s);
	s = '.' + s;
	for (int j = 0; j < 3; ++ j){
		pw[j][0] = inv[j][0] = 1;
		Inv[j] = power(base, mod[j] - 2, mod[j]);
		for (int i = 1; i <= n; ++ i){
			pw[j][i] = pw[j][i - 1] * base % mod[j];
			inv[j][i] = inv[j][i - 1] * Inv[j] % mod[j];
		}
	}
	for (int j = 0; j < 3; ++ j)
		for (int i = n; i >= 1; -- i)
			part[j][i] = (part[j][i + 1] + ll(s[i] - '0') * pw[j][n - i]) % mod[j];
	for (int i = 1; i <= n - 2; ++ i){
		check(i, n - i - i, i);
		check(i - 1, n - i - i + 1, i);
		check(n - i - i, i, i);
		check(n - i - i + 1, i - 1, i);
	}
	cout << ans << endl;
	
	return 0;
}