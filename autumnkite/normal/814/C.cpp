#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	std::vector<std::vector<int>> len(26, std::vector<int>(n + 1));
	for (int c = 0; c < 26; ++c) {
		for (int l = 1; l <= n; ++l) {
			len[c][l] = l;
			int now = 0;
			for (int i = 0; i < l; ++i) {
				now += s[i] == c + 'a';
			}
			for (int i = l; i <= n; ++i) {
				len[c][l] = std::min(len[c][l], l - now);
				now -= s[i - l] == c + 'a';
				if (i < n) {
					now += s[i] == c + 'a';
				}
			}
		}
	}

	int q;
	std::cin >> q;
	while (q--) {
		int m;
		char c;
		std::cin >> m >> c;
		int t = c - 'a';
		int p = std::upper_bound(len[t].begin(), len[t].end(), m) - len[t].begin() - 1;
		std::cout << p << "\n";
	}
}