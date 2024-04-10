#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	const int P = 998244353;
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		int n;
		cin >> n;
		vector<vector<int>> a(2 * n + 1, vector<int>(n + 1));
		for (int i = 1; i <= 2 * n; ++i) { 
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
			}
		}
		int done = 0;
		vector<bool> used(2 * n + 1, false);
		vector<vector<set<int>>> cnt(n + 1, vector<set<int>>(n + 1));
		for (int i = 1; i <= 2 * n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cnt[j][a[i][j]].insert(i);
			}
		}
		auto purge = [&](int i) {
			vector<int> bad;
			for (int j = 1; j <= n; ++j) {
				for (int x : cnt[j][a[i][j]]) {
					bad.push_back(x);
				}
			}
			sort(bad.begin(), bad.end());
			bad.resize(unique(bad.begin(), bad.end()) - bad.begin());
			for (int row : bad) {
				used[row] = true;
				for (int j = 1; j <= n; ++j) {
					cnt[j][a[row][j]].erase(row);
				}
			}
		};
		vector<int> ans;
		int ways = 1;
		while (ans.size() != n) {
			while (true) {
				bool ok = false;
				for (int j = 1; j <= n; ++j) {
					for (int v = 1; v <= n; ++v) {
						if (cnt[j][v].size() == 1) {
							int row = *cnt[j][v].begin();
							purge(row);
							ans.push_back(row);
							ok = true;
						}
					}
				}
				if (!ok) {
					break;
				}
			}
			for (int i = 1; i <= 2 * n; ++i) {
				if (!used[i]) {
					purge(i);
					ans.push_back(i);
					ways *= 2;
					if (ways >= P) {
						ways -= P;
					}
					break;
				}
			}		
		}
		cout << ways << '\n';
		for (int x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}