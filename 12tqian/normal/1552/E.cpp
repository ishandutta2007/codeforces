#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> c(n * k);
	vector<vector<int>> locs(n);
	for (int i = 0; i < n * k; ++i) {
		cin >> c[i];
		--c[i];
		locs[c[i]].push_back(i);
	}
	vector<array<int, 3>> ivals;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k - 1; ++j) {
			ivals.push_back({locs[i][j], locs[i][j + 1], i});
		}
	}
	sort(ivals.begin(), ivals.end(), [&](auto x, auto y) { return x[1] < y[1]; });
	vector<bool> done(n);
	vector<array<int, 2>> ans(n);
	for (auto [l, r, x] : ivals) {
		if (done[x]) {
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (done[i]) {
				if (l < ans[i][1]) {
					++cnt;
				}
			}
		}
		if (cnt < (n + k - 2) / (k - 1)) {
			done[x] = true;
			ans[x] = {l, r};
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i][0] + 1 << ' ' << ans[i][1] + 1 << '\n';
	}
	return 0;
}