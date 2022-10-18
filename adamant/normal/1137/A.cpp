#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> g1[n], g2[m];
	for(int i = 0; i < n; i++) {
		vector<int> cur;
		for(int j = 0; j < m; j++) {
			cur.push_back(a[i][j]);
		}
		sort(all(cur));
		cur.erase(unique(all(cur)), end(cur));
		g1[i] = cur;
	}
	for(int j = 0; j < m; j++) {
		vector<int> cur;
		for(int i = 0; i < n; i++) {
			cur.push_back(a[i][j]);
		}
		sort(all(cur));
		cur.erase(unique(all(cur)), end(cur));
		g2[j] = cur;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int idx1 = lower_bound(all(g1[i]), a[i][j]) - begin(g1[i]);
			int idx2 = lower_bound(all(g2[j]), a[i][j]) - begin(g2[j]);
			cout << max(idx1, idx2) + max(g1[i].size() - idx1, g2[j].size() - idx2) << " \n"[j + 1 == m];
		}
	}
	return 0;
}