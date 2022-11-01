#include <iostream>
#include <vector>
using namespace std;

const int N = 105;
int cnt;
bool ans = true;

int part[N];
vector <pair <int, int> > adj[N];


void dfs(int v) {
	if (part[v] == 3) {
		cnt++;
	}
	for (auto p : adj[v]) {
		int u = p.first, b = p.second;
		if (!part[u]) {
			part[u] = part[v] ^ b;
			dfs(u);
		}
		else if(part[u] != part[v] ^ b) {
			ans = false;
			return;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		b ^= 1;
		adj[u].push_back({v, b});
		adj[v].push_back({u, b});
	}
	for (int i = 1; i <= n; i++) {
		if (!part[i]) {
			part[i] = 2;
			dfs(i);
		}
	}
	if (!ans) {
		cout << "Impossible";
	}
	else { 
		cout << cnt << endl;
		for (int i = 1; i <= n; i++) {
			if (part[i] == 3) {
				cout << i << " ";
			}
		}
	}
	return 0;
}