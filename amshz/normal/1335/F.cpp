# include <bits/stdc++.h>
 
using namespace std;
 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long          ll;
typedef long double        ld;
typedef pair <int, int>    pii;
typedef pair <pii, int>    ppi;
typedef pair <pii, pii>    pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e6 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";
 
int qq, n, m, Root, dist[xn], ted;
string c[xn], num[xn];
vector <int> adj[2][xn];
bool Mark[xn], oke[xn], vis[xn], mark[xn];
queue <int> q;
 
void DFS(int v){
	Mark[v] = true;
	for (int u : adj[0][v]){
		if (Mark[u]){
			Root = u;
			continue;
		}
		DFS(u);
	}
}
void DFS2(int v){
	mark[v] = true;
	ted ++;
	for (int u : adj[0][v]) if (!mark[u]) DFS2(u);	
}
 
void BFS(int v){
	dist[v] = 0;
	while (q.size()) q.pop();
	q.push(v);
	while (q.size()){
		int V = q.front();
		if (oke[V]) vis[dist[V] % ted] = true;
		q.pop();
		for (int u : adj[1][V]){
			if (dist[u] != -1) continue;
			dist[u] = dist[V] + 1;
			q.push(u);
		}
	}
}
 
void Solve(){
	cin >> n >> m;
	for (int i = 0; i < n * m; ++ i) dist[i] = -1, vis[i] = false;
	for (int i = 0; i < n * m; ++ i){
		Mark[i] = oke[i] = mark[i] = false, adj[0][i].clear(), adj[1][i].clear(), dist[i] = -1;
	}
	for (int i = 0; i < n; ++ i) cin >> c[i];
	for (int i = 0; i < n; ++ i) cin >> num[i];
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			if (c[i][j] == '0') oke[i * m + j] = true;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < m; ++ j){
			int v, u;
			v = i * m + j;
			if (num[i][j] == 'U') u = (i - 1) * m + j;
			else if (num[i][j] == 'D') u = (i + 1) * m + j;
			else if (num[i][j] == 'L') u = i * m + j - 1;
			else u = i * m + j + 1;
			adj[0][v].push_back(u);
			adj[1][u].push_back(v);
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n * m; ++ i){
		if (dist[i] != -1) continue;
		DFS(i);
		ted = 0;
		DFS2(Root);
		for (int j = 0; j < ted; ++ j) vis[j] = false;
		BFS(Root);
		ans1 += ted;
		for (int j = 0; j < ted; ++ j) ans2 += vis[j];
	}
	cout << ans1 << sep << ans2 << endl;
	for (int i = 0; i < n; ++ i) c[i] = num[i] = "";
}
 
int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --) Solve();
	
	return 0;
}