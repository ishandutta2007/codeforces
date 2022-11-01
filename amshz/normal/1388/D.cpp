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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

ll n, a[xn], b[xn], part[xn], ans, dp[xn], sz[xn], num[xn], ord[xn];
vector <int> adj[xn], root, vec[2][xn];

void DFS2(int v){
	num[v] += part[v];
	ord[num[v]] = v;
	for (int u : adj[v]){
		part[u] += part[v];
		DFS2(u);
	}
}
void DFS(int v){
	for (int u : adj[v]) DFS(u);
	dp[v] = a[v];
	ans += a[v];
	sz[v] = 1;
	for (int u : adj[v]){
		if (dp[u] > 0) vec[0][v].push_back(u);
		else vec[1][v].push_back(u);
		if (dp[u] > 0){
			dp[v] += dp[u];
			ans += dp[u];
		}
		sz[v] += sz[u];
	}
	ll ptr = 0;
	for (int u : vec[0][v]){
		part[u] += ptr;
		ptr += sz[u];
	}
	num[v] = ptr ++;
	for (int u : vec[1][v]){
		part[u] += ptr;
		ptr += sz[u];
	}
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    for (int i = 1; i <= n; ++ i){
    	if (b[i] != - 1) adj[b[i]].push_back(i);
		else root.push_back(i);
	}
	for (int v : root) DFS(v);
	ll ptr = 0;
	for (int v : root){
		part[v] += ptr;
		ptr += sz[v];
	}
	for (int v : root) DFS2(v);
	cout << ans << endl;
	for (int i = 0; i < n; ++ i) cout << ord[i] << sep;
	cout << endl;
	
    return 0;
}