#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <map>

int b[1000001];
int _a[200000];
int a[200000];
int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> _a[i];
	std::sort(_a, _a + n);
	a[0] = _a[0];
	int idx = 1;
	for (int i = 1; i < n; ++i)
		if (_a[i] != _a[i - 1])
			a[idx++] = _a[i];
	n = idx;


	for (int i = 0; i + 1 < n; ++i)
		for (int j = a[i] + 1; j <= a[i + 1]; ++j)
			b[j] = a[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = a[i] << 1; j <= a[n - 1]; j += a[i])
			ans = std::max(ans, b[j] % a[i]);
		ans = std::max(ans, a[n-1] % a[i]);
	}
	std::cout << ans;
	return 0;
}