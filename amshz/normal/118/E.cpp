# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const ll MD = md * 100;
const int xn = 1e5+10;
const int xlg = 22;
const int SQ = 233;
const int sq = 1e5+10;
const ll inf = 1e18+10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
 
int n, m, H[xn], dp[xn], Root = 1;
vector <int> adj[xn];
vector <pii> Ans;
bool Mark[xn], Bridge[xn];
map <pii, int> mp;
 


void DFS(int v, int par = -1){
	Mark[v] = true;
	dp[v] = H[v];
	for (int i = 0; i < adj[v].size(); i ++){
		int u = adj[v][i];
		if (!mp[{v, u}]) continue;
		mp[{v, u}] --;
		mp[{u, v}] --;
		Ans.push_back({v, u});
		if (Mark[u]){
			dp[v] = min(dp[v], H[u]);
			continue;
		}
		H[u] = H[v] + 1;
		DFS(u, v);
		dp[v] = min(dp[v], dp[u]);
	}
	Bridge[v] = (dp[v] == H[v] && v != Root);
}
 

 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	int v, u;
	for (int i = 0; i < m; i ++){
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		mp[{v, u}] ++;
		mp[{u, v}] ++;
	}
	
	DFS(1);
	
	for (int i = 1; i <= n; i ++){
		if (Bridge[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < m; i ++) cout << Ans[i].F << sep << Ans[i].S << endl;
	
	return 0;
}