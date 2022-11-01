#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5;

vector <int> adj[N];
int part[N];
int cnt[3];
void dfs(int v) {
	for (auto u : adj[v]) {
		if (part[u] == part[v]) {
			cout << 0 << " " << 1 << endl;
			exit(0);
		}
		if (part[u] == 0) {
			part[u] = 3 - part[v];
			cnt[part[u]]++;
			dfs(u);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (m == 0) {
		long long w = 1ll * n * (n - 1) * (n - 2) / 6;
		cout << 3 << " " << w << endl;
		return 0;
	}
	bool b = true;
	for (int i = 1; i <= n; i++) {
//		w += 1ll * adj[i].size() * ((long long) adj[i].size() - 1) / 2;
//		cout << "73 " << i << " " << adj[i].size() << " " << w << endl;
		if (adj[i].size() > 1)
			b = false;
	}
	if (b) {
		cout << 2 << " " << 1ll * m * (n - 2) << endl;
	}
	else {
		long long w = 0;
		for (int i = 1; i <= n; i++) {
			if (!part[i]) {
				cnt[1] = 1;
				cnt[2] = 0;
				part[i] = 1;
				dfs(i);
				w += 1ll * cnt[1] * (cnt[1] - 1) / 2 + 1ll * cnt[2] * (cnt[2] - 1) / 2;
			}
		}
		cout << 1 << " " << w << endl;
	}
	return 0;
}