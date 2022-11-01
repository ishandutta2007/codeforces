#include <iostream>
#include <vector>
using namespace std;


const int N = 200 * 1000 + 5;
int c;

int part[N];
vector <int> adj[N];

void dfs(int v) {
	if (part[v] == 1) {
		c++;
	}
	for (auto u : adj[v]) {
		if (!part[u]) {
			part[u] = 3 - part[v];
			dfs(u);
		}
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	part[1] = 1;
	dfs(1);
	cout << min(c, n - c) - 1;	
	return 0;
}