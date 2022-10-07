#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	
	std::vector<int> l(n), r(n);
	l[0] = 0;
	for (int i = 1; i < n; ++i) {
		l[i] = s[i - 1] == s[i] ? l[i - 1] : i;
	}
	r[n - 1] = n;
	for (int i = n - 1; i >= 1; --i) {
		r[i - 1] = s[i - 1] == s[i] ? r[i] : i;
	}

	if (n == k || l[n - k - 1] == 0 || r[k] == n) {
		std::cout << "tokitsukaze\n";
		return 0;
	}
	for (int i = 1; i < n - k; ++i) {
		if (s[i - 1] == s[i + k] && l[i - 1] == 0 && r[i + k] == n) {
			std::cout << "tokitsukaze\n";
			return 0;
		}
	}
	bool flag = 2 * k >= n;
	for (int i = 1; i < n - k && flag; ++i) {
		if (l[i - 1] != 0 || r[i + k] != n) {
			flag = false;
		}
	}
	if (flag) {
		std::cout << "quailty\n";
	} else {
		std::cout << "once again\n";
	}
}