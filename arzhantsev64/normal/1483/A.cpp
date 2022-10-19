#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n);
	vector<vector<int>> choice(m);
	vector<int> ans(m, -1);
	vector<int> k(m);

	for (int i = 0; i < m; ++i) {
		cin >> k[i];
		choice[i].resize(k[i]);
		for (int j = 0; j < k[i]; ++j) {
			cin >> choice[i][j];
			choice[i][j]--;
		}
		if (k[i] == 1) {
			ans[i] = choice[i][0];
			cnt[choice[i][0]]++;
		}
	}

	for (int i = 0; i < m; ++i) {
		if (k[i] == 1)
			continue;

		int num_min = -1;
		int minn = 1e9;
		for (int j : choice[i]) {
			if (cnt[j] < minn) {
				minn = cnt[j];
				num_min = j;
			}
		}
		ans[i] = num_min;
		cnt[num_min]++;
	}

	int max_pos = (m - 1) / 2 + 1;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > max_pos) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES\n";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}