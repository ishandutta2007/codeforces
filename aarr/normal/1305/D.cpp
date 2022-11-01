#include <bits/stdc++.h>
using namespace std;


const int N = 2005;
int x, y;

set <int> adj[N];
vector <int> vec;
int deg[N];
bool mark[N];
bool b[N];
bool c[N];

void dfs1(int v) {
	mark[v] = true;
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs1(u);
		}
	}
	vec.push_back(v);
}
void dfs2(int v) {
	mark[v] = true;
	if (v == x || v == y) {
		b[v] = true;
	//	deg[v]++;
	//	return;
	}
	for (auto u : adj[v]) {
		if (!mark[u]) {
			dfs2(u);
			if (b[u]) {
				b[v] = true;
				deg[u]++;
			}
		}
	}
}
int main() {
	int n, st = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
/*	for (int i = 0; i < n / 2; i++) {
		int w, a = n - i - 1;
		if (n % 2) {
			a--;
		}
		x = vec[i], y = vec[a];
		cout << "? " << x << " " << y << endl;
		cout.flush();
		cin >> w;
		c[w] = true;
		fill(mark, mark + n + 1, false);
		fill(b, b + n + 1, false);
		dfs2(w);
		
	}
	for (int i = 1; i <= n; i++) {
		cout << deg[i] << " ";
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			cout << "! " << i;
			return 0;
		}
	}*/
	for (int i = 0; i < n / 2; i++) {
		int u = 0, v = 0;
		for (int j = 1; j <= n; j++) {
			if (adj[j].size() == 1) {
				u = j;
			}
			for (int j = n; j > 0; j--) {
				if (adj[j].size() == 1) {
					v = j;
				}
			}
		}
		cout << "? " << u << " " << v << endl;
		cout.flush();
		int w;
		cin >> w;
		if (w == u || w == v) {
			cout << "! " << w;
			return 0;
		}
		int x = *adj[u].begin();
		adj[x].erase(u);
		adj[u].erase(x);
		int y = *adj[v].begin();
		adj[y].erase(v);
		adj[v].erase(y);
		mark[u] = true;
		mark[v] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			ans = i;
		}
	}
	cout << "! " << ans;
	return 0;
}