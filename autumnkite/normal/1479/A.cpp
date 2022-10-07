#include <bits/stdc++.h>

int n;

bool query(int m) {
	int x, y;
	if (m >= 1) {
		std::cout << "? " << m << std::endl;
		std::cin >> x;
	} else {
		x = n + 1;
	}
	if (m + 1 <= n) {
		std::cout << "? " << m + 1 << std::endl;
		std::cin >> y;
	} else {
		y = n + 1;
	}
	return x < y;
}

void solve(int l, int r) {
	if (l == r) {
		std::cout << "! " << l << std::endl;
		return;
	}
	int mid = (l + r) >> 1;
	if (query(mid)) {
		solve(l, mid);
	} else {
		solve(mid + 1, r);
	}
}

int main() {
	std::cin >> n;
	solve(1, n);
}