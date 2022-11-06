#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <queue>
#include <functional>

long long minLeft[100000];
long long minRight[100000];
long long maxLeft[100000];
long long maxRight[100000];
long long a[100000];

int n, p, q, r;

long long f(const std::array<long long, 3> &arr) {
	return arr[0] * p + arr[1] * q + arr[2] * r;
}

long long max(const std::vector<long long> &v) {
	long long res = v[0];
	for (int i = 1; i < v.size(); ++i)
		res = std::max(res, v[i]);
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> p >> q >> r;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	minLeft[0] = maxLeft[0] = a[0];
	minRight[n - 1] = maxRight[n - 1] = a[n - 1];

	for (int i = 1; i < n; ++i) {
		minLeft[i] = std::min(a[i], minLeft[i - 1]);
		maxLeft[i] = std::max(a[i], maxLeft[i - 1]);
	}

	for (int i = n - 2; i >= 0; --i) {
		minRight[i] = std::min(a[i], minRight[i + 1]);
		maxRight[i] = std::max(a[i], maxRight[i + 1]);
	}

	long long ans = f({ a[0], a[0], a[0] });
	for (int i = 0; i < n; ++i)
		ans = max({ ans,
			f({ minLeft[i], a[i], minRight[i] }),
			f({ maxLeft[i], a[i], minRight[i] }),
			f({ minLeft[i], a[i], maxRight[i] }),
			f({ maxLeft[i], a[i], maxRight[i] }),
	});
	std::cout << ans << '\n';
	return 0;
}