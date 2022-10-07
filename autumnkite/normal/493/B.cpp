#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a, b;
	bool last = false;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		if (v > 0) {
			a.push_back(v);
			last = false;
		} else {
			b.push_back(-v);
			last = true;
		}
	}
	long long suma = std::accumulate(a.begin(), a.end(), 0ll);
	long long sumb = std::accumulate(b.begin(), b.end(), 0ll);
	if (std::make_tuple(suma, a, !last) > std::make_tuple(sumb, b, last)) {
		std::cout << "first\n";
	} else {
		std::cout << "second\n";
	}
}