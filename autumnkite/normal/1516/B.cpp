#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum ^= a[i];
	}
	int pre = 0;
	for (int i = 0; i < n; ++i) {
		pre ^= a[i];
		int suf = 0;
		for (int j = n - 1; j > i; --j) {
			suf ^= a[j];
			if ((pre == suf && pre == sum) || (j == i + 1 && pre == suf)) {
				std::cout << "YES\n";
				return;
			}
		}
	}
	std::cout << "NO\n";
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