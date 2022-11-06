#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>

int a[100];

bool program() {
	int n, k;
	std::cin >> n >> k;
	int twos, fours;
	twos = 2 * n;
	fours = n;

	for (int i = 0; i < k; ++i)
		std::cin >> a[i];

	// 4's
	for (int i = 0; i < k; ++i)
		while (a[i] >= 4 && fours >= 1) {
			a[i] -= 4;
			--fours;
		}

	// all grps < 4 or fours = 0

	twos += fours;
	int ones = fours;
	fours = 0;

	// all a's even
	for (int i = 0; i < k; ++i) {
		while (twos >= 1 && a[i] >= 2) {
			a[i] -= 2;
			--twos;
		}
		while (ones >= 1 && a[i] >= 1) {
			a[i]--;
			--ones;
		}
		if (a[i] > 0 && twos > 0) {
			--a[i];
			--twos;
		}
	}
	for (int i = 0; i < k; ++i)
		if (a[i] != 0)
			return false;
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << (program() ? "YES" : "NO") << '\n';
	return 0;
}