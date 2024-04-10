#include <bits/stdc++.h>

void solve() {
	std::string s;
	std::cin >> s;
	int ans = 10;
	for (int v = 0; v < 2; ++v) {
		int now = 0;
		for (int i = 0; i < 10; ++i) {
			if (now + 10 - i < 0 || now - 10 + i > 0) {
				ans = std::min(ans, i);
				break;
			}
			int t = s[i] == '?' ? v : (s[i] - '0') ^ (i & 1);
			if (t) {
				++now;
			} else {
				--now;
			}
		}
	}
	std::cout << ans << "\n";
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