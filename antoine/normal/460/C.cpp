#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

bool f(int * a, int n, int m, int w, int h) {
	std::unordered_map<int, int> inc;
	for (int i = 0; i < n; ++i) {
		h += inc[i];
		if (a[i] >= h)
			continue;
		int diff = h - a[i];
		if (diff > m)
			return false;
		m -= diff;
		inc[i + w] = diff;
		h -= diff;
	}
	return true;
}

int a[100000];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, w;
	std::cin >> n >> m >> w;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int lo = 0;
	int hi = a[0] + m;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2; // (lo, hi]
		if (f(a, n, m, w, mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	std::cout << lo;
	return 0;
}