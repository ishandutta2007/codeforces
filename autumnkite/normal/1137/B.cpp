#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s, t;
	std::cin >> s >> t;
	int n = s.size(), m = t.size();

	std::vector<int> fail(m + 1);
	fail[1] = 0;
	for (int i = 1, j = 0; i < m; ++i) {
		while (j && t[j] != t[i]) {
			j = fail[j];
		}
		if (t[j] == t[i]) {
			++j;
		}
		fail[i + 1] = j;
	}

	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			++c0;
		} else {
			++c1;
		}
	}
	int ct0 = 0, ct1 = 0;
	for (int i = 0; i < fail[m]; ++i) {
		if (t[i] == '0') {
			++ct0;
		} else {
			++ct1;
		}
	}

	auto finish = [&]() {
		for (int i = 0; i < c0; ++i) {
			std::cout << 0;
		}
		for (int i = 0; i < c1; ++i) {
			std::cout << 1;
		}
		std::cout << "\n";
	};
	
	if (c0 >= ct0 && c1 >= ct1) {
		for (int i = 0; i < fail[m]; ++i) {
			std::cout << t[i];
		}
		c0 -= ct0, c1 -= ct1;
		ct0 = 0, ct1 = 0;
		for (int i = fail[m]; i < m; ++i) {
			if (t[i] == '0') {
				++ct0;
			} else {
				++ct1;
			}
		}
		while (c0 >= ct0 && c1 >= ct1) {
			for (int i = fail[m]; i < m; ++i) {
				std::cout << t[i];
			}
			c0 -= ct0, c1 -= ct1;
		}
	}
	finish();
}