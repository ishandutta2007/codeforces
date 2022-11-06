
//http://codeforces.com/problemset/problem/600/B

#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	static int a[200000];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::sort(a, a + n);
	for (; m > 0; --m) {
		static int q;
		std::cin >> q;
		int lo = 0;
		int hi = n;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (a[mid] > q)
				hi = mid;
			else
				lo = mid + 1;
		}
		std::cout << lo << ' ';
	}
	return 0;
}