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
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, sum, x, y, cnt[2], ans = INF;
ll c[3][xn];
pll part[2][xn];
string s;

int main(){
	InTheNameOfGod;
	
	cin >> s >> x >> y;
	n = SZ(s), s = '.' + s;
	for (int i = 1; i <= n; ++ i){
		c[0][i] = c[0][i - 1];
		c[1][i] = c[1][i - 1];
		c[2][i] = c[2][i - 1];
		if (s[i] == '0')
			++ c[0][i];
		else if (s[i] == '1')
			++ c[1][i];
		else
			++ c[2][i];
		if (s[i] == '1')
			sum += cnt[0] * x, ++ cnt[1];
		else if (s[i] == '0')
			sum += cnt[1] * y, ++ cnt[0];
	}
	cnt[0] = cnt[1] = 0;
	for (int i = 1; i <= n; ++ i){
		part[0][i].A = part[0][i - 1].A;
		part[1][i].A = part[1][i - 1].A;
		if (s[i] == '?'){
			part[0][i].A += c[1][i] * y;
			part[0][i].A += (c[1][n] - c[1][i]) * x;
			part[1][i].A += c[0][i] * x;
			part[1][i].A += (c[0][n] - c[0][i]) * y;
		}
	}
	for (int i = n; i >= 1; -- i){
		part[0][i].B = part[0][i + 1].B;
		part[1][i].B = part[1][i + 1].B;
		if (s[i] == '?'){
			part[0][i].B += c[1][i] * y;
			part[0][i].B += (c[1][n] - c[1][i]) * x;
			part[1][i].B += c[0][i] * x;
			part[1][i].B += (c[0][n] - c[0][i]) * y;
		}
	}
	for (int i = 0; i <= n; ++ i){
		ans = min(ans, part[0][i].A + part[1][i + 1].B + c[2][i] * (c[2][n] - c[2][i]) * x);
		ans = min(ans, part[1][i].A + part[0][i + 1].B + c[2][i] * (c[2][n] - c[2][i]) * y);
	}
	cout << ans + sum << endl;
	
	return 0;
}