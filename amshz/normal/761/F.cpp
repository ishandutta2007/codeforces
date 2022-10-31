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
 
const int xn = 1e3 + 10;
const int xm = 3e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, m, k, part[27][xn][xn], ans = INF;
string s[xn];
char c[xm];
ppp a[xm];

ll get(ppp x, int id){
	ll res = part[id][x.B.A][x.B.B];
	res -= part[id][x.B.A][x.A.B - 1];
	res -= part[id][x.A.A - 1][x.B.B];
	res += part[id][x.A.A - 1][x.A.B - 1];
	return res;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> s[i], s[i] = '.' + s[i];
	for (int i = 0; i < k; ++ i){
		cin >> a[i].A.A >> a[i].A.B;
		cin >> a[i].B.A >> a[i].B.B >> c[i];
		++ part[c[i] - 'a'][a[i].A.A][a[i].A.B];
		-- part[c[i] - 'a'][a[i].A.A][a[i].B.B + 1];
		-- part[c[i] - 'a'][a[i].B.A + 1][a[i].A.B];
		++ part[c[i] - 'a'][a[i].B.A + 1][a[i].B.B + 1];
	}
	for (int p = 0; p < 26; ++ p){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j)
				part[p][i][j] += part[p][i][j - 1];
			for (int j = 1; j <= m; ++ j)
				part[p][i][j] += part[p][i - 1][j];
		}
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			int res = k;
			for (int p = 0; p < 26; ++ p)
				res -= part[p][i][j];
			part[s[i][j] - 'a'][i][j] += res;
			for (int p = 0; p < 26; ++ p)
				part[26][i][j] += abs(s[i][j] - 'a' - p) * part[p][i][j];
		}
	}
	for (int p = 0; p < 27; ++ p){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j)
				part[p][i][j] += part[p][i][j - 1];
			for (int j = 1; j <= m; ++ j)
				part[p][i][j] += part[p][i - 1][j];
		}
	}
	for (int i = 0; i < k; ++ i){
		ll res = get({{1, 1}, {n, m}}, 26);
		res -= get(a[i], 26);
		for (int p = 0; p < 26; ++ p)
			res += abs(c[i] - 'a' - p) * get(a[i], p);
		ans = min(ans, res);
	}
	cout << ans << endl;
	
	return 0;
}