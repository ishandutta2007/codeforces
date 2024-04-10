#include <bits/stdc++.h>

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n && j - i < m && s[j] == t[j - i]; ++j) {
			int k = j - 1, p = j - i + 1;
			while (k >= 0 && p < m && s[k] == t[p]) {
				--k, ++p;
			}
			if (p == m) {
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