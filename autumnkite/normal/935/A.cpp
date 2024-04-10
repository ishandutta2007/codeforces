#include <bits/stdc++.h>

int n;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		if ((n - i) % i == 0) {
			++ans;
		}
	}
	std::cout << ans << "\n";
}