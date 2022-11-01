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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod[3] = {1000000007, 1000000009, 998244353};
const ll MOD = 1111118111111;
const int base = 2;

ll n, m, a[3][xn], pw[3][xn], cnt, ans;
pii E[xn];
vector <int> adj[xn];
vector <pip> compress;
bool flag;

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		E[i] = {v, u};
	}
	for (int i = 0; i < 3; ++ i)
		pw[i][0] = 1;
	for (int j = 0; j < 3; ++ j)
		for (int i = 1; i < xn; ++ i)
			pw[j][i] = pw[j][i - 1] * ll(base) % mod[j];
	for (int v = 1; v <= n; ++ v)
		for (int i = 0; i < 3; ++ i)
			for (int u : adj[v])
				a[i][v] = (a[i][v] + pw[i][u]) % mod[i];
	for (int i = 1; i <= n; ++ i)
		compress.push_back({a[0][i], {a[1][i], a[2][i]}});
	sort(all(compress));
	for (int i = 0; i < SZ(compress); ++ i){
		if (i && compress[i] != compress[i - 1])
			ans += cnt * (cnt - 1) / 2, cnt = 0;
		++ cnt;
	}
	ans += cnt * (cnt - 1) / 2;
	for (int i = 0; i < m; ++ i){
		int v = E[i].A, u = E[i].B;
		flag = true;
		for (int j = 0; j < 3; ++ j){
			a[j][v] = (a[j][v] - pw[j][u] + mod[j]) % mod[j];
			a[j][u] = (a[j][u] - pw[j][v] + mod[j]) % mod[j];
			flag &= a[j][v] == a[j][u];
			a[j][v] = (a[j][v] + pw[j][u] + mod[j]) % mod[j];
			a[j][u] = (a[j][u] + pw[j][v] + mod[j]) % mod[j];
		}
		ans += flag;
	}
	cout << ans << endl;
	
	return 0;
}