#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(n - 1);
	std::vector<std::vector<int>> pos(n);
	for (int i = 0; i < n - 1; ++i) {
		int k;
		std::cin >> k;
		a[i].resize(k);
		for (int &x : a[i]) {
			std::cin >> x;
			--x;
			pos[x].push_back(i);
		}
	}

	for (int k = 0; k < n; ++k) {
		std::vector<bool> vis(n - 1);
		std::vector<int> cnt(n);
		std::vector<int> ans(n);
		std::vector<int> id(n);
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			cnt[i] = pos[i].size();
		}
		++cnt[k];
		for (int i = n - 1; i > 0; --i) {
			int x = std::find(cnt.begin(), cnt.end(), 1) - cnt.begin();
			if (x == n || x == k || std::find(cnt.begin() + x + 1, cnt.end(), 1) != cnt.end()) {
				flag = false;
				break;
			}
			ans[i] = x;
			for (int p : pos[x]) {
				if (!vis[p]) {
					id[i] = p;
					vis[p] = true;
					for (int v : a[p]) {
						--cnt[v];
					}
					break;
				}
			}
		}
		ans[0] = k;
		for (int i = 1; i < n && flag; ++i) {
			std::vector<int> tmp(ans.begin() + i - (int)a[id[i]].size() + 1, ans.begin() + i + 1);
			std::sort(tmp.begin(), tmp.end());
			flag &= tmp == a[id[i]];
		}
		if (flag) {
			for (int x : ans) {
				std::cout << x + 1 << " ";
			}
			std::cout << "\n";
			return;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}