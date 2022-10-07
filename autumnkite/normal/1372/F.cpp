#include <bits/stdc++.h>

std::pair<int, int> query(int l, int r) {
	std::cout << "? " << l + 1 << " " << r << std::endl;
	int x, f;
	std::cin >> x >> f;
	return std::make_pair(x, f);
}

void solve(std::vector<int> &a, int l, int r) {
	if (l == r) {
		return;
	}
	auto [x, f] = query(l, r);
	if (r - f < l + f) {
		for (int i = r - f; i < l + f; ++i) {
			a[i] = x;
		}
		solve(a, l, r - f);
		solve(a, l + f, r);
	} else {
		int mid = (l + r + 1) >> 1;
		solve(a, l, mid);
		solve(a, mid, r);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	solve(a, 0, n);
	std::cout << "! ";
	for (int x : a) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
// https://codeforces.com/blog/entry/79974?#comment-660196