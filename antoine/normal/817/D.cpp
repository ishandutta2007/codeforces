#include <iostream>
#include <algorithm>
#include <cstring>

int a[1000000];
long long c[1000000];
int aux[1000000];

long long cS(int i, int j) {
	if (i > j)
		return 0;
	return i == 0 ? c[j] : (c[j] - c[i-1]);
}

long long f(int lo, int hi) {
	if (lo == hi)
		return a[lo];
	int mid = (lo + hi) >> 1;
	long long ans = f(lo, mid) + f(mid + 1, hi);

	aux[mid] = a[mid];
	for (int i = mid - 1; i >= lo; --i)
		aux[i] = std::max(aux[i + 1], a[i]);

	aux[mid + 1] = a[mid + 1];
	for (int i = mid + 2; i <= hi; ++i)
		aux[i] = std::max(aux[i - 1], a[i]);

	c[lo] = aux[lo];
	for (int i = lo + 1; i <= hi; ++i)
		c[i] = c[i - 1] + aux[i];

	int j = hi;
	for (int i = lo; i <= mid; ++i) {
		while (j >= mid + 1 && aux[j] > aux[i])
			--j;
		ans += (long long)(j - (mid + 1) + 1) * aux[i] + cS(j + 1, hi);
	}

	//std::cout << "F: " << lo << ' ' << hi << "  : " << ans << '\n';
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	c[0] = a[0];
	for (int i = 1; i < n; ++i)
		c[i] = a[i] + c[i - 1];

	long long ans = f(0, n - 1);
	for (int i = 0; i < n; ++i)
		a[i] = -a[i];
	//std::cout << "Pre; " << ans << '\n';
	std::cout << ans + f(0, n-1);
	return 0;
}