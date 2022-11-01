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
typedef pair <ld, ld>                                  pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

//const ll md = 1e9 + 7;//998244353;
const int xn = 1e2 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md = 1e9 + 7;
const int TM = 2;
const int Base = 257;


int n, m, dp[xn][xn][xn], last[xn][xn], sz, x, y, z, mx;
pair <pii, pii> par[xn][xn][xn];
string s1, s2, virus, ans;
vector <int> adj[xn];
bool flag[xn][xn];

int main(){
    InTheNameOfGod;
    
	cin >> s1 >> s2 >> virus;
	n = SZ(s1), m = SZ(s2), sz = SZ(virus);
	s1 = '.' + s1, s2 = '.' + s2, virus = '.' + virus;
	memset(flag, true, sizeof flag);
	for (int i = 1; i <= sz; ++ i)
		for (int j = 1; j <= i; ++ j)
			for (int k = 1; k <= j; ++ k) 
				flag[i][j] &= virus[k] == virus[k + i - j];
	for (int i = 1; i <= sz; ++ i)
		for (int j = 0; j < 26; ++ j)
			for (int k = 0; k <= min(sz - 1, i); ++ k)
				if (flag[i][k] && virus[k + 1] == j + 'A')
					last[j][i] = k + 1;
	last[virus[1] - 'A'][0] = 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			for (int k = 0; k < sz; ++ k){
				if (s1[i] == s2[j]){
					for (int l = max(0, k - 1); l < sz; ++ l){
						if ((!(i - 1) || !(j - 1)) && l)	continue;
						if (last[s1[i] - 'A'][l] != k) continue;
						if (dp[i - 1][j - 1][l] + 1 > dp[i][j][k]){
							dp[i][j][k] = dp[i - 1][j - 1][l] + 1;
							par[i][j][k] = {{i - 1, j - 1}, {l, 1}};
						}
					}
				}
				if (dp[i - 1][j][k] > dp[i][j][k]){
					dp[i][j][k] = dp[i - 1][j][k];
					par[i][j][k] = {{i - 1, j}, {k, 0}};
				}
				if (dp[i][j - 1][k] > dp[i][j][k]){
					dp[i][j][k] = dp[i][j - 1][k];
					par[i][j][k] = {{i, j - 1}, {k, 0}};
				}
			}
		}
	}
	for (int i = 1; i < sz; ++ i)
		if (dp[n][m][i] > dp[n][m][mx])
			mx = i;
	x = n, y = m, z = mx;
	if (!dp[n][m][mx]) kill(0);
	while (x || y){
		pair <pii, pii> p = par[x][y][z];
		if (p.B.B)	ans = s1[x] + ans;
		x = p.A.A, y = p.A.B, z = p.B.A;
	}
	cout << ans << endl;
    
    return 0;
}