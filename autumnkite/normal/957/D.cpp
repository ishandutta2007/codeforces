#include <bits/stdc++.h>

const int N = 100005;

int n, a[N], s[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	a[n + 1] = s[n + 1] = 0;
	
	for (int i = n; i; --i) {
		s[i] = std::max(s[i + 1] - 1, a[i] + 1);
	}

	long long ans = 0;
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		s[i] = std::max(s[i - 1], s[i]);
		ans += s[i] - a[i] - 1;
	}
	std::cout << ans << "\n";
}