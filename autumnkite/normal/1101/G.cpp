#include <bits/stdc++.h>

class linear_basis {
	const int LG = 30;

	std::vector<int> a;

public:
	linear_basis() : a(LG) {}

	void insert(int x) {
		for (int i = LG - 1; i >= 0; --i) {
			if (x >> i & 1) {
				if (!a[i]) {
					a[i] = x;
					return;
				}
				x ^= a[i];
			}
		}
	}

	int size() {
		int s = 0;
		for (int i = 0; i < LG; ++i) {
			s += a[i] > 0;
		}
		return s;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	linear_basis B;
	int s = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		B.insert(v);
		s ^= v;
	}
	if (s == 0) {
		std::cout << -1 << "\n";
	} else {
		std::cout << B.size() << "\n";
	}
}