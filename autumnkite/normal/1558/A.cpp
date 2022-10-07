#include <bits/stdc++.h>

void solve() {
	int a, b;
	std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
	int d = (a + b) & 1 ? 1 : 2;
	std::vector<int> p;
	for (int i = (b - a) / 2; i <= a + b - (b - a) / 2; i += d) {
		p.push_back(i);
	}
	std::cout << p.size() << "\n";
	for (int x : p) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}