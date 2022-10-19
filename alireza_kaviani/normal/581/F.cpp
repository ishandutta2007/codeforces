#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 5000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , root , sz[MAXN] , dp[MAXN][MAXN] , dp2[MAXN];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
	fill(dp[v] + 1 , dp[v] + MAXN , MOD);
	for(int u : adj[v]){
		if(u == p)	continue;
		DFS(u , v);
		fill(dp2 , dp2 + MAXN , MOD);
		for(int i = 0 ; i <= sz[v] ; i++){
			for(int j = 0 ; j <= sz[u] ; j++){
				dp2[i + j] = min(dp2[i + j] , dp[v][i] + dp[u][j]);
				dp2[i + sz[u] - j] = min(dp2[i + sz[u] - j] , dp[v][i] + dp[u][j] + 1);
			}
		}
		for(int i = 0 ; i < MAXN ; i++){
			dp[v][i] = dp2[i];
		}
		sz[v] += sz[u];
	}
	if(sz[v] == 0){
		swap(dp[v][0] , dp[v][1]);
	}
	sz[v] = max(sz[v] , 1);
	/*cout << v << endl;
	for(int i = 0 ; i <= n ; i++){
		cout << dp[v][i] << sep;
	}
	cout << endl;*/
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	if(n == 2)	return cout << 1 << endl , 0;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		if(SZ(adj[v]) > 1)	root = v;
		if(SZ(adj[u]) > 1)	root = u;
	}
	DFS(root);
	cout << dp[root][sz[root] / 2] << endl;

	return 0;
}
/*

*/