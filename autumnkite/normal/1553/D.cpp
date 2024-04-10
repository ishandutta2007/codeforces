#include <bits/stdc++.h>

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	std::reverse(s.begin(), s.end());
	std::reverse(t.begin(), t.end());
	int now = 0;
	int p = 0;
	for (auto c : t) {
		while (p < (int)s.size() && ((p & 1) != now || s[p] != c)) {
			++p;
		}
		if (p < (int)s.size()) {
			++p;
			now ^= 1;
		} else {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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