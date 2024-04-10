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
 
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 30;
const int BASE = 257;

int qq, n, m, num[xn], mark[xn], ted, mn[2][xn], H[xn], root;
vector <int> adj[2][xn];
bool flag, dp[xn], flag2;

void DFS3(int v){
	mark[v] = 1;
	dp[v] &= (mn[0][v] < inf && H[mn[0][v]] < H[v]);
	dp[v] &= (mn[1][v] == inf || H[mn[1][v]] >= H[v]);
	if (mn[0][v] < inf && H[mn[0][v]] < H[v]) dp[v] &= (dp[mn[0][v]]);
	if (v == root) dp[v] = true;
	for (int u : adj[1][v]) if (!mark[u]) DFS3(u);
}
void DFS2(int v){
	mark[v] = 1;
	for (int u : adj[1][v]){
		if (mark[u]){
			if (mn[1][v] == inf || H[u] < H[mn[1][v]]) mn[1][v] = u;
			if (mn[1][v] < inf && (mn[0][v] == inf || H[mn[1][v]] < H[mn[0][v]])) swap(mn[0][v], mn[1][v]);
			continue;
		}
		H[u] = H[v] + 1;
		DFS2(u);
		if (mn[1][v] == inf || (mn[0][u] < inf && H[mn[0][u]] < H[mn[1][v]])) mn[1][v] = mn[0][u];
		if (mn[1][v] < inf && (mn[0][v] == inf || H[mn[1][v]] < H[mn[0][v]])) swap(mn[0][v], mn[1][v]);
		if (mn[1][v] == inf || (mn[1][u] < inf && H[mn[1][u]] < H[mn[1][v]])) mn[1][v] = mn[1][u];
		if (mn[1][v] < inf && (mn[0][v] == inf || H[mn[1][v]] < H[mn[0][v]])) swap(mn[0][v], mn[1][v]);
	}
}
void DFS(int v){
	mark[v] = 1;
	for (int u : adj[1][v]){
		flag |= mark[u] == 2;
		if (!mark[u]) DFS(u);
	}
	mark[v] = 2;
}

void solve(int v){
	root = v;
	for (int i = 1; i <= n; ++ i) mark[i] = 0;
	flag = false;
	DFS(v);
	for (int i = 1; i <= n; ++ i) flag |= !mark[i];
	if (flag) return;
	flag2 = true;
	H[v] = 0;
	for (int i = 1; i <= n; ++ i) mark[i] = 0, dp[i] = true, mn[0][i] = mn[1][i] = inf;
	DFS2(v);
	for (int i = 1; i <= n; ++ i) mark[i] = 0;
	DFS3(v);
}
 
int main(){
    InTheNameOfGod;
    srand(time(0));
    
    cin >> qq;
    while (qq --){
    	cin >> n >> m;
    	for (int i = 1; i <= n; ++ i) adj[0][i].clear(), adj[1][i].clear();
    	for (int i = 1; i <= m; ++ i){
    		int v, u;
    		cin >> v >> u;
    		adj[1][v].push_back(u);
    		adj[0][u].push_back(v);
		}
		for (int i = 0; i < n; ++ i) num[i] = i + 1;
		random_shuffle(num, num + n);
		flag2 = false;
		for (int i = 0; i < min(n, TM); ++ i){
			solve(num[i]);
			if (flag2) break;
		}
		ted = 0;
		for (int i = 1; i <= n; ++ i) ted += dp[i];
		if (!flag2 || ted < (n + 4) / 5){
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= n; ++ i) if (dp[i]) cout << i << sep;
		cout << endl;
	}
	
    return 0;
}