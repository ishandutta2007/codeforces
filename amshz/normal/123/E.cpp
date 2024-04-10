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
 
const ll md = 1e9 + 7;//998244353;
const int xn = 1e5 + 10;
const int xm = 21;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
string abc = "abcdefghijklmnopqrstuvwxyz";


ll n, sz[xn], p[2][xn], sum[2], s[xn], ans;
vector <int> adj[xn];
bool Mark[xn];

void DFS(int v){
	Mark[v] = true;
	s[v] = p[0][v];
	sz[v] = 1;
	for (int u : adj[v]){
		if (Mark[u]) continue;
		DFS(u);
		sz[v] += sz[u];
		s[v] += s[u];
		ans += p[1][v] * sz[u] * s[u];
	}
	ans += p[1][v] * (sum[0] - s[v]) * (n - sz[v]);
}
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i){
		cin >> p[0][i] >> p[1][i];
		sum[0] += p[0][i];
		sum[1] += p[1][i];
	}
	DFS(1);
	cout << fixed << setprecision(15) << (ans * 1.0000) / (sum[0] * sum[1]) << endl;
	
	return 0;
}