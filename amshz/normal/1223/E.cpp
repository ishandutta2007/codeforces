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
 

ll qq, n, k, dp[xn][2];
vector <pii> adj[xn];
vector <pii> bach[xn];
bool Mark[xn];

void DFS(int v){
	Mark[v] = true;
	for (pii u : adj[v]){
		if (Mark[u.A]) continue;
		DFS(u.A);
		bach[v].push_back({dp[u.A][1] + u.B - dp[u.A][0], dp[u.A][0]});
	}
	sort(all(bach[v]));
	reverse(all(bach[v]));
	dp[v][0] = dp[v][1] = 0;
	for (int i = 0; i < SZ(bach[v]); ++ i){
		if (bach[v][i].A > 0 && i < k) dp[v][0] += bach[v][i].A + bach[v][i].B;
		else dp[v][0] += bach[v][i].B;
		if (bach[v][i].A > 0 && i < k - 1) dp[v][1] += bach[v][i].A + bach[v][i].B;
		else dp[v][1] += bach[v][i].B;
	}
}

void Solve(){
	cin >> n >> k;
	for (int i = 0; i <= n; ++ i) adj[i].clear(), Mark[i] = false, bach[i].clear();
	for (int i = 0; i < n - 1; ++ i){
		ll v, u, w;
		cin >> v >> u >> w;
		adj[v].push_back({u, w});
		adj[u].push_back({v, w});
	}
	DFS(1);
	cout << dp[1][0] << endl;
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --) Solve();
	
	return 0;
}