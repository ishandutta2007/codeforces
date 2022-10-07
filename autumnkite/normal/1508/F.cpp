#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n), l(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
		l[i] = i;
	}

	std::vector<int> pr1(n, -1), pr2(n, -1), nx1(n, -1), nx2(n, -1);

	int ans = 0;

	auto update = [&](int i, int j) {
		if (a[j] > a[i]) {
			if (pr1[i] == -1 || a[j] < a[pr1[i]]) {
				if (pr1[i] != -1) {
					ans -= nx2[pr1[i]] == i;
				}
				if (nx2[j] != -1) {
					ans -= pr1[nx2[j]] == j;
				}
				++ans;
				pr1[i] = j, nx2[j] = i;
			}
		} else {
			if (pr2[i] == -1 || a[j] > a[pr2[i]]) {
				if (pr2[i] != -1) {
					ans -= nx1[pr2[i]] == i;
				}
				if (nx1[j] != -1) {
					ans -= pr2[nx1[j]] == j;
				}
				++ans;
				pr2[i] = j, nx1[j] = i;
			}
		}
	};

	while (q--) {
		int L, R;
		std::cin >> L >> R;
		--L, --R;
		int qL = std::upper_bound(l.begin(), l.end(), L) - l.begin();
		for (int i = qL; i <= R; ++i) {
			while (l[i] > L) {
				update(i, --l[i]);
			}
		}
		std::cout << ans << "\n";
	}
}