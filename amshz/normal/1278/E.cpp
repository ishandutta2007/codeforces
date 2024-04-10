# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 5e5 + 10;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, Root = 1, S = 1;
vector <int> adj[xn], ans[xn];
bool Mark[xn];

void DFS(int v){
	Mark[v] = true;
	for (int u : adj[v]){
		if (Mark[u]) continue;
		ans[u].push_back(S ++);
	}
	ans[v].push_back(S ++);
	reverse(adj[v].begin(), adj[v].end());
	for (int u : adj[v]){
		if (Mark[u]) continue;
		DFS(u);
	}
}

int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	ans[Root].push_back(S ++);
	DFS(Root);
	
	for (int v = 1; v <= n; v ++){
		for (int u : ans[v]) cout << u << sep;
		cout << endl;
	}
	
	return 0;
}