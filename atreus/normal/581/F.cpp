#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 5000 + 10;

int n, dp[maxn][maxn], pd[maxn][maxn], sz[maxn];
vector<int> t[maxn];

void dfs(int v, int par = -1){
	if (t[v].size() == 1){
		dp[v][1] = 0;
		sz[v] = 1;
		return;
	}
	dp[v][0] = 0;
	for (auto u : t[v]){
		if (u == par)
			continue;
		dfs(u, v);
		for (int i = 0; i <= sz[v] + sz[u]; i++)
			pd[v][i] = n;
		for (int i = 0; i <= sz[v]; i++){
			for (int j = 0; j <= sz[u]; j++){
				pd[v][i + j] = min(pd[v][i + j], dp[v][i] + dp[u][j]);
				pd[v][i + sz[u] - j] = min(pd[v][i + sz[u] - j], dp[v][i] + dp[u][j] + 1);
			}
		}
		for (int i = 0; i <= sz[v] + sz[u]; i++)
			dp[v][i] = pd[v][i];
		sz[v] += sz[u];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	if (n == 2)
		return cout << 1 << endl, 0;
	int nonleaf;
	for (nonleaf = 1; nonleaf <= n; nonleaf++)
		if (t[nonleaf].size() > 1)
			break;
	memset(dp, 63, sizeof dp);
	dfs(nonleaf);
	cout << dp[nonleaf][sz[nonleaf] / 2] << endl;
}