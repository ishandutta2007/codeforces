#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , dp[MAXN][2];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
	int mx = 0;
	for(int u : adj[v]){
		if(u == p)	continue;
		DFS(u , v);
		dp[v][0] += max(dp[u][0] , dp[u][1]);
		mx = max(mx , dp[u][0] + 1 - max(dp[u][0] , dp[u][1]));
	}
	dp[v][1] = dp[v][0] + mx;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		for(int i = 0 ; i <= n + 5 ; i++){
			dp[i][0] = dp[i][1] = 0;
			adj[i].clear();
		}
		for(int i = 1 ; i < n ; i++){
			int v , u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		DFS(1);
		cout << min(n - 2 * dp[1][0] , n + 1 - 2 * dp[1][1]) << endl;
	}

    return 0;
}
/*

*/