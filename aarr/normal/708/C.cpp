#include <iostream>
#include <vector>
using namespace std;


const int N = 400 * 1000 + 5;
int n;
int rt;

vector <int> adj[N];
int sz[N], g[N];
bool mark[N], ans[N];

void dfs1(int v) {
	mark[v] = true;
	sz[v] = 1;
	bool b = true;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs1(u);
			sz[v] += sz[u];
			if (sz[u] * 2 > n) {
				b = false;
			}	
		}
	}
	if (2 * (n - sz[v]) > n) {
		b = false;
	}
	if (b) {
		rt = v;
	}
}
void dfs2(int v, int o) {
	mark[v] = true;
	g[v] = o;
	sz[v] = 1;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs2(u, o);
			sz[v] += sz[u];
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1);
	fill(sz, sz + n + 1, 0);
	fill(mark, mark + n + 1, false);
//	cout << "75 " << rt << endl;
	mark[rt] = true;
	int max1 = 0, max2 = 0;
	for (auto u : adj[rt]) {
		dfs2(u, u);
		if (sz[u] > sz[max2]) {
			max2 = u;
		}
		if (sz[u] > sz[max1]) {
			max2 = max1;
			max1 = u;
		}
	}
//	cout << "72 " << max1 << " " << max2 << endl;
	for (int i = 1; i <= n; i++) {
		if (i == rt) {
			ans[i] = true;
		}
		else {
			int k = max1;
			if (g[i] == k) {
				k = max2;
			}
			if ((n - sz[i] - sz[k]) * 2 <= n || (n - sz[g[i]]) * 2 <= n) {
				ans[i] = true;
			}
		}
	} 
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}