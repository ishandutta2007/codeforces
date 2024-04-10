# include <bits/stdc++.h>
 
using namespace std;
 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long                         ll;
typedef long double                       ld;
typedef pair <ll, ll>                     pii;
typedef pair <pii, int>                   ppi;
typedef pair <pii, pii>                   pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;//998244353;
const int xn = 5e5 + 10;
const int xm = 20;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 

int n, m, Root;
ll dp[xn][2];
vector <int> adj[xn], bach[xn];
bool Mark[xn], flag[xn];


void DFS(int v, int p = 0){
	Mark[v] = true;
	ll mx = 0, ind = -1;
	for (int u : adj[v]){
		if (u == p) continue;
		if (Mark[u]){
			flag[v] = true;
			continue;
		}
		DFS(u, v);
		if (flag[u]){
			dp[v][1] += dp[u][1];
			if (dp[u][0] - dp[u][1] > mx) mx = dp[u][0] - dp[u][1], ind = u;
		}
		else if (dp[u][0] > mx) mx = dp[u][0], ind = u;
		bach[v].push_back(u);
		flag[v] |= flag[u];
	}
	for (int u : bach[v]){
		if (ind == u) dp[v][0] += dp[u][0];
		else if (flag[u]) dp[v][0] += dp[u][1];
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> dp[i][0], dp[i][1] = dp[i][0];
	for (int i = 0; i < m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	cin >> Root;
	DFS(Root);
	cout << dp[Root][0] << endl;
	
	return 0;
}