/**
 *    author:  Atreus
 *    created: 14.01.2019 23:06:10     
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 4e5 + 10;
const int maxm = 4e5 + 10;

vector <pair <int, int> > g[maxn];
pair <int, int> e[maxm];
bool visited[maxn], cut[maxm], check[maxm];
int h[maxn];

void getdir(int v){
	visited[v] = 1;
	for (auto u : g[v]){
		if (!visited[u.first]){
			h[u.first] = h[v] + 1;
			getdir(u.first);
		}
	}
}

int up[maxn], sz[maxn];

int dfs(int v, int edge = -1){
	visited[v] = 1;
	up[v] = h[v];
	sz[v] = 1;
	for (auto u : g[v]){
		if (!visited[u.first]){
			h[u.first] = h[v] + 1;
			sz[v] += dfs(u.first, u.second);
			up[v] = min(up[v], up[u.first]);
		}
		else if (h[u.first] < h[v] - 1){
			up[v] = min(up[v], h[u.first]);
		}
	}
	if (edge != -1 and up[v] == h[v]){
		cut[edge] = 1;
		return 0;
	}
	return sz[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		e[i] = {v, u};
		g[v].push_back({u, i});
		g[u].push_back({v, i});
	}
	dfs(1);
	int idx = -1;
	for (int v = 1; v <= n; v++)
		if (idx == -1 or sz[idx] < sz[v])
			idx = v;
	memset(visited, 0, sizeof visited);
	memset(h, 0, sizeof h);
	getdir(idx);
	cout << sz[idx] << endl;
	for (int i = 0; i < m; i++){
		if (h[e[i].first] > h[e[i].second])
			swap(e[i].first, e[i].second);
		if (!cut[i] and h[e[i].first] + 1 == h[e[i].second])
			cout << e[i].first << " " << e[i].second << '\n';
		else
			cout << e[i].second << " " << e[i].first << '\n';
	}
}