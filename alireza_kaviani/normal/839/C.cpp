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

int n;
double dp[MAXN];
vector<int> adj[MAXN];

void DFS(int v , int p = -1){
	int deg = 0;
	for(int u : adj[v]){
		if(u == p)	continue;
		DFS(u , v);
		dp[v] += dp[u];
		deg++;
	}
	if(deg == 0)	return;
	dp[v] /= deg;
	dp[v]++;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	printf("%.10f" , dp[1]);

    return 0;
}
/*

*/