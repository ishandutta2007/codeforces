#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	std::string s;
	std::cin >> s;
	int n = s.size();
	std::vector<std::vector<int>> pos(26);
	for (int i = 0; i < n; ++i) {
		pos[s[i] - 'a'].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		int mx = 0;
		for (int k = 0; k < n; ++k) {
			std::vector<int> vis(26);
			for (int p : pos[i]) {
				++vis[s[(p + k) % n] - 'a'];
			}
			int cnt = 0;
			for (int i = 0; i < 26; ++i) {
				cnt += vis[i] == 1;
			}
			mx = std::max(mx, cnt);
		}
		ans += mx;
	}
	std::cout << 1.0 * ans / n << "\n";
}