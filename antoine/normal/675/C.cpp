#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	int ans = n;
	std::unordered_map<long long, int> m;
	m.reserve(2 * n);
	long long s = 0;
	for (int i = 0; i < n; ++i) {
		static long long a;
		std::cin >> a;
		s += a;
		ans = std::min(ans, n - (++m[s]));
	}
	std::cout << ans;
	return 0;
}