#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	s += '0';
	std::reverse(s.begin(), s.end());

	std::vector<int> f(1 << (n + 1), 1);
	auto upd = [&](int i) {
		if (s[i] == '0') {
			f[i] = f[i << 1 | 1];
		} else if (s[i] == '1') {
			f[i] = f[i << 1];
		} else {
			f[i] = f[i << 1] + f[i << 1 | 1];
		}
	};
	for (int i = (1 << n) - 1; i >= 1; --i) {
		upd(i);
	}

	int q;
	std::cin >> q;
	while (q--) {
		int p;
		char c;
		std::cin >> p >> c;
		p = (1 << n) - p;
		s[p] = c;
		while (p != 0) {
			upd(p);
			p >>= 1;
		}
		std::cout << f[1] << "\n";
	}
}