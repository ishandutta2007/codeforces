#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;
	std::vector<int> cnt(26);
	for (char c : s) {
		++cnt[c - 'a'];
	}
	std::vector<int> p;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] & 1) {
			p.push_back(i);
		}
	}
	int B = p.size() / 2;
	for (int i = 0; i < B; ++i) {
		++cnt[p[i]];
		--cnt[p[(int)p.size() - i - 1]];
	}
	std::string ans;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < cnt[i] / 2; ++j) {
			ans += i + 'a';
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] & 1) {
			ans += i + 'a';
		}
	}
	for (int i = 25; i >= 0; --i) {
		for (int j = 0; j < cnt[i] / 2; ++j) {
			ans += i + 'a';
		}
	}
	std::cout << ans << "\n";
}