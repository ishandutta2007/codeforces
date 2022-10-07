#include <bits/stdc++.h>

class basis {
	static const int LG = 20;

	std::vector<int> a, p;

public:
	basis() : a(LG), p(LG, -1) {}

	void insert(int x, int id) {
		for (int i = LG - 1; i >= 0; --i) {
			if (x >> i & 1) {
				if (id > p[i]) {
					std::swap(a[i], x);
					std::swap(p[i], id);
				}
				x ^= a[i];
			}
		}
	}

	int query(int l) {
		int x = 0;
		for (int i = LG - 1; i >= 0; --i) {
			if (p[i] >= l && !(x >> i & 1)) {
				x ^= a[i];
			}
		}
		return x;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<basis> a(n);
	basis B;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		B.insert(v, i);
		a[i] = B;
	}
	
	int q;
	std::cin >> q;
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		--l, --r;
		std::cout << a[r].query(l) << "\n";
	}
}