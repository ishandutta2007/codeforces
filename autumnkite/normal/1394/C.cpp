#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), c(n);
	int len = 0;
	for (int i = 0; i < n; ++i) {
		std::string t;
		std::cin >> t;
		len = std::max(len, (int)t.size());
		for (char c : t) {
			if (c == 'B') {
				++a[i];
			} else {
				++b[i];
			}
		}
		c[i] = b[i] - a[i];
	}
	
	int la = *std::max_element(a.begin(), a.end());
	int ra = *std::min_element(a.begin(), a.end());
	int lb = *std::max_element(b.begin(), b.end());
	int rb = *std::min_element(b.begin(), b.end());
	int lc = *std::max_element(c.begin(), c.end());
	int rc = *std::min_element(c.begin(), c.end());

	auto check = [&](int m) {
		int La = std::max(0, la - m), Ra = ra + m;
		int Lb = std::max(0, lb - m), Rb = rb + m;
		int Lc = lc - m, Rc = rc + m;
		if (La > Ra || Lb > Rb || Lc > Rc || Lb - Ra > Rc || Rb - La < Lc) {
			return false;
		} else {
			return true;
		}
	};

	int l = 0, r = len, m = len;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			m = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << m << "\n";
	int La = std::max(0, la - m), Ra = ra + m;
	int Lb = std::max(0, lb - m), Rb = rb + m;
	int Lc = lc - m, Rc = rc + m;
	for (int x = La, y; x <= Ra; ++x) {
		y = x + Lc;
		if (Lb <= y && y <= Rb && x + y > 0) {
			std::cout << std::string(x, 'B') + std::string(y, 'N') << "\n";
			return 0;
		}
		y = x + Rc;
		if (Lb <= y && y <= Rb && x + y > 0) {
			std::cout << std::string(x, 'B') + std::string(y, 'N') << "\n";
			return 0;
		}
	}
}