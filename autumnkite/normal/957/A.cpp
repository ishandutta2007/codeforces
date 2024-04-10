#include <bits/stdc++.h>

int n;
char a[105];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	std::cin >> (a + 1);
	for (int i = 1; i < n; ++i) {
		if (a[i] != '?' && a[i + 1] != '?' && a[i] == a[i + 1]) {
			std::cout << "No\n";
			return 0;
		}
	}
	if (a[1] == '?' || a[n] == '?') {
		std::cout << "Yes\n";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] == '?' && a[i + 1] == '?') {
			std::cout << "Yes\n";
			return 0;
		}
	}
	for (int i = 2; i < n; ++i) {
		if (a[i] == '?' && a[i - 1] == a[i + 1]) {
			std::cout << "Yes\n";
			return 0;
		}
	}
	std::cout << "No\n";
}