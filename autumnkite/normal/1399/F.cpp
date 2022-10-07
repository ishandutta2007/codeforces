#include <bits/stdc++.h>

struct segment {
	int l, r;
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<segment> a(n);
	std::vector<int> L(2 * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].l >> a[i].r;
		++a[i].r;
		L[i] = a[i].l;
		L[i + n] = a[i].r;
	}
	std::sort(L.begin(), L.end());
	L.erase(std::unique(L.begin(), L.end()), L.end());
	std::vector<std::vector<int>> p(L.size() + 1);
	for (int i = 0; i < n; ++i) {
		a[i].l = std::lower_bound(L.begin(), L.end(), a[i].l) - L.begin();
		a[i].r = std::lower_bound(L.begin(), L.end(), a[i].r) - L.begin();
		p[a[i].r].push_back(a[i].l);
	}

	std::vector<std::vector<int>> f(L.size() + 1, std::vector<int>(L.size() + 1));
	for (int l = (int)L.size() - 1; l >= 0; --l) {
		for (int r = l + 1; r <= (int)L.size(); ++r) {
			f[l][r] = std::max(f[l + 1][r], f[l][r - 1]);
			bool flag = false;
			for (int k : p[r]) {
				if (k > l) {
					f[l][r] = std::max(f[l][r], f[l][k] + f[k][r]);
				} else if (k == l) {
					flag = true;
				}
			}
			f[l][r] += flag;
		}
	}
	std::cout << f[0][L.size()] << "\n";
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