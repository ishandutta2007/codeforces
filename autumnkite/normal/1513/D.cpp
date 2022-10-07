#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::map<int, std::vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mp[a[i]].push_back(i);
	}

	long long ans = 0;
	DSU D(n);
	for (const auto &v : mp) {
		if (v.first >= m) {
			break;
		}
		int r = 0;
		for (int p : v.second) {
			if (p < r) {
				continue;
			}
			int l = p;
			while (l >= 0 && a[l] % a[p] == 0) {
				ans += D.merge(l, p) * a[p];
				--l;
			}
			r = p;
			while (r < n && a[r] % a[p] == 0) {
				ans += D.merge(r, p) * a[p];
				++r;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (D.find(i) == i) {
			ans += m;
		}
	}
	std::cout << ans - m << "\n";
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