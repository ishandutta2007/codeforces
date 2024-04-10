#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	int L = 0;
	while (L < k && (1 << L) <= n - k + 1) {
		++L;
	}

	std::vector<bool> vis(1 << L);
	int now = 0;
	for (int i = 0; i <= n - L; ++i) {
		if (now + L >= k) {
			int x = 0;
			for (int j = 0; j < L; ++j) {
				x = x << 1 | (s[i + j] ^ '1');
			}
			vis[x] = true;
		}
		if (s[i] == '1') {
			++now;
		} else {
			now = 0;
		}
	}
	int ans = 0;
	while (ans < (1 << L) && vis[ans]) {
		++ans;
	}
	if (ans == (1 << L)) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		for (int i = 0; i < k - L; ++i) {
			std::cout << '0';
		}
		for (int i = L - 1; i >= 0; --i) {
			std::cout << (ans >> i & 1);
		}
		std::cout << "\n";
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