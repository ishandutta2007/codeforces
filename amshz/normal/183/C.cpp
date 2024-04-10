# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;


int n, m, ans;
vector <pii> adj[xn];
vector <int> vec[xn];
bool mark[xn];

void DFS(int v, int x){
	vec[v].pb(x);
	if (mark[v]) return;
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].F, y = adj[v][i].S;
		DFS(u, x+y);
	}
}

 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		adj[v].pb({u, 1});
		adj[u].pb({v, -1});
	}
	for (int i = 1; i <= n; i++){
		if (mark[i]) continue;
		DFS(i, 0);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < vec[i].size(); j++) ans = __gcd(ans, abs(vec[i][j] - vec[i][j-1]));
	}
	cout << (ans ? ans : n) << endl;
	
	
	return 0;
}