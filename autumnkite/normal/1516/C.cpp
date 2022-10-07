#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		flag &= !(a[i] & 1);
	}
	while (flag) {
		for (int i = 0; i < n; ++i) {
			a[i] /= 2;
			flag &= !(a[i] & 1);
		}
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
	}
	if (sum & 1) {
		std::cout << 0 << "\n";
		return 0;
	}

	std::bitset<100001> f;
	f[0] = 1;
	for (int i = 0; i < n; ++i) {
		f |= f << a[i];
	}
	if (f[sum / 2]) {
		std::cout << 1 << "\n";
		for (int i = 0; i < n; ++i) {
			if (a[i] & 1) {
				std::cout << i + 1 << "\n";
				return 0;
			}
		}
	} else {
		std::cout << 0 << "\n";
	}
}