#include <bits/stdc++.h>

int n, q;
char a[105];

bool check(int l, int r) {
	for (int i = 1; i <= l - 1; ++i) {
		if (a[i] == a[l]) {
			return true;
		}
	}
	for (int i = r + 1; i <= n; ++i) {
		if (a[i] == a[r]) {
			return true;
		}
	}
	return false;
}

void solve() {
	std::cin >> n >> q;
	std::cin >> (a + 1);
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		std::cout << (check(l, r) ? "YES\n" : "NO\n");
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}