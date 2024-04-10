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
typedef pair <ll , ll >                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 10007;//998244353;
const int xn = 50 + 10;
const int xm = 21;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";

int n, m, ted, cnt;
ll flag[2 << xm];
ld c[xm], ans;
string s[xn];
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i) cin >> s[i];
	m = SZ(s[0]);
	for (ll i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			if (i == j) continue;
			int mask = 0;
			for (int bit = 0; bit < m; ++ bit) if (s[i][bit] == s[j][bit]) mask += 1 << bit;
			flag[mask] |= ll(1LL << i);
		}
	}
	for (int bit = 0; bit < m; ++ bit)
		for (int mask = 0; mask < 1 << m; ++ mask)
			if (!(mask & (1 << bit))) 	flag[mask] |= flag[mask + (1 << bit)];
	for (int i = 0; i <= m; ++ i) c[i] = 1;
	for (int i = 0; i <= m; ++ i) for (ll j = 0; j < i; ++ j) c[i] *= ld(j + 1) / ld(m - j);
	for (int mask = 0; mask < 1 << m; ++ mask){
		ted = __builtin_popcount(mask);
		cnt = __builtin_popcountll(flag[mask]);
		ans += c[ted] * cnt;
	}
	cout << fixed << setprecision(15) << ans / n << endl;
	
	return 0;
}