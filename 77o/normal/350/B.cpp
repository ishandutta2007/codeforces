#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> type(n);
	for (int& i : type) {
		cin >> i;
	}
	vector<vector<int>> g(n);
	vector<int> deg(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a) {
			g[i].push_back(a - 1);
			deg[a - 1]++;
		}
	}
	vector<int> dist(n, 1e9);
	vector<int> way(n, -1);
	for (int i = 0; i < n; i++) {
		if (type[i]) {
			dist[i] = 0;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (int u : g[v]) {
					if (deg[u] > 1) {
						continue;
					}
					if (dist[v] + 1 < dist[u]) {
						dist[u] = dist[v] + 1;
						way[u] = v;
						q.push(u);
					}
				}
			}
		}
	}
	int ans = -1;
	int ind;
	for (int i = 0; i < n; i++) {
		if (dist[i] != 1e9 && dist[i] > ans) {
			ans = dist[i];
			ind = i;
		}
	}
	cout << ans + 1 << endl;
	while (ind >= 0) {
		cout << ind + 1 << ' ';
		ind = way[ind];
	}
	cout << endl;
	return 0;
}