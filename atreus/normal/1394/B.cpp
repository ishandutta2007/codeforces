#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 1e9;

vector<pair<int,int>> g[maxn], deg[maxn];

bool cant[10][10][10][10];
int p[10];
ll answer = 0;

void bt(int now, int k){
	if (now == k+1){
		bool good = 1;
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				if (cant[i][p[i]][j][p[j]])
					good = 0;
		answer += good;
		return;
	}
	for (int i = 1; i <= now; i++){
		p[now] = i;
		bt(now+1, k);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		g[v].push_back({w,u});
	}
	for (int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());
		int k = g[i].size();
		for (int j = 0; j < k; j++){
			int u = g[i][j].second;
			deg[u].push_back({k, j+1});
		}
	}
	for (int u = 1; u <= n; u++){
		sort(deg[u].begin(), deg[u].end());
		for (int j = 1; j < deg[u].size(); j++){
			if (deg[u][j] == deg[u][j-1]){
				int k = deg[u][j].first, x = deg[u][j].second;
				cant[k][x][k][x] = 1;
			}
		}
		deg[u].resize(unique(deg[u].begin(),deg[u].end())-deg[u].begin());
		for (int j = 1; j < deg[u].size(); j++){
			for (int z = 0; z < j; z++){
				int k = deg[u][j].first, x = deg[u][j].second;
				int K = deg[u][z].first, X = deg[u][z].second;
				cant[k][x][K][X] = 1;
			}
		}
	}
	bt(1, k);
	cout << answer << endl;
}