#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int w[maxn], d[maxn], h[maxn];
int leaf1[maxn], leaf2[maxn], leaf3[maxn];
vector<int> g[maxn];

void DFS(int v, int par = -1){
	for (auto u : g[v]){
		if (u != par)
			DFS(u, v);
	}
	if (leaf3[v] == v){
		if (leaf1[par] == leaf1[v])
			leaf3[v] = leaf2[par];
		else
			leaf3[v] = leaf1[par];
	}
}

void dfs(int v, int par = -1){
	leaf1[v] = v;
	leaf2[v] = v;
	leaf3[v] = v;
	if (g[v].size() == 1)
		return;
	int first = 1;
	for (auto u : g[v]){
		if (u != par){
			h[u] = h[v] + 1;
			dfs(u, v);
			if (first == 1){
				leaf1[v] = leaf1[u];
				first = 2;
			}
			else if (first == 2){
				leaf2[v] = leaf1[u];
				first = 3;
			}
			else
				leaf3[v] = leaf1[u];
		}
	}
}

pair<int, int> e[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u >> w[i];
		e[i] = {v, u};
		g[v].push_back(u);
		g[u].push_back(v);
		d[v] ++, d[u] ++;
	}
	if (n == 2){
		cout << "YES\n";
		cout << 1 << '\n';
		cout << 1 << " " << 2 << " " << w[0] << '\n';
		return 0;
	}
	int root = 1;
	for (int i = 1; i <= n; i++){
		if (d[i] == 2)
			return cout << "NO\n", 0;
		if (d[i] > 1)
			root = i;
	}
	dfs(root);
	DFS(root);
	vector<pair<pair<int, int>, int> > op;
	for (int i = 0; i < n - 1; i++){
		int v = e[i].first, u = e[i].second;
		if (h[v] < h[u])
			swap(v, u);
		if (d[v] > 1)
			op.push_back({{leaf1[v], leaf2[v]}, -w[i] / 2});
		int fi = leaf1[u], se = leaf2[u];
		if (fi == leaf1[v])
			fi = leaf3[u];
		if (se == leaf1[v])
			se = leaf3[u];
		op.push_back({{fi, se}, -w[i] / 2});
		op.push_back({{fi, leaf1[v]}, w[i] / 2});
		op.push_back({{se, leaf2[v]}, w[i] / 2});
	}
	cout << "YES\n";
	cout << op.size() << '\n';
	for (auto it : op)
		cout << it.first.first << " " << it.first.second << " " << it.second << '\n';
}