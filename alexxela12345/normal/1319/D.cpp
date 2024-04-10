#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<vector<int>> g1(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[b].push_back(a);
		g1[a].push_back(b);
	}
	int k;
	cin >> k;
	vector<int> path(k);
	for (int i = 0; i < k; i++) {
		cin >> path[i];
		path[i]--;
	}
	vector<int> dist(n, INT_MAX);
	dist[path.back()] = 0;
	deque<int> q;
	q.push_back(path.back());
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (int u : g[v]) {
			if (dist[u] == INT_MAX) {
				dist[u] = dist[v] + 1;
				q.push_back(u);
			}
		}
	}
	vector<int> cntOut(n);
	for (int i = 0; i < n; i++) {
		for (int j : g1[i]) {
			if (dist[i] == dist[j] + 1) {
				cntOut[i]++;
			}
		}
	}
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < k - 1; i++) {
		if (dist[path[i]] != dist[path[i + 1]] + 1) {
			cnt1++;
		} else if (cntOut[path[i]] >= 2) {
			cnt2++;
		}
	}
	cout << cnt1 << " " << cnt1 + cnt2 << endl;
	return 0;
}