#include <bits/stdc++.h>

const int LG = 18;

class basis {
	const int B;

	std::vector<int> a;

public:
	basis(int x) : B(x), a(B) {}

	bool insert(int x) {
		for (int i = B - 1; i >= 0; --i) {
			if (x >> i & 1) {
				if (!a[i]) {
					a[i] = x;
					return true;
				}
				x ^= a[i];
			}
		}
		return false;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	for (int x = LG; x >= 0; --x) {
		basis B(x);
		std::vector<int> v;
		for (int i = 0; i < n; ++i) {
			if (a[i] < (1 << x)) {
				if (B.insert(a[i])) {
					v.push_back(a[i]);
				}
			}
		}
		if ((int)v.size() == x) {
			std::cout << x << "\n";
			for (int i = 0; i < (1 << x); ++i) {
				int S = i ^ (i >> 1);
				int res = 0;
				for (int j = 0; j < x; ++j) {
					if (S >> j & 1) {
						res ^= v[j];
					}
				}
				std::cout << res << " ";
			}
			std::cout << "\n";
			return 0;
		}
	}
}