#include <bits/stdc++.h>

void solve() {
	int s[4];
	std::cin >> s[0] >> s[1] >> s[2] >> s[3];
	int t = std::min(std::max(s[0], s[1]), std::max(s[2], s[3]));
	std::sort(s, s + 4);
	std::cout << (t == s[2] ? "YES" : "NO") << "\n";
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