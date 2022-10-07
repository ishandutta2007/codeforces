#include <bits/stdc++.h>

std::mt19937 rnd(time(0));

int query(int x, int y) {
	std::cout << "? " << x + 1 << " " << y + 1 << std::endl;
	int res;
	std::cin >> res;
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	auto calc = [&](int x) {
		std::set<int> S;
		S.insert(x);
		int res = -1;
		for (int i = 0; i < 15 && i < n - 1; ++i) {
			int y;
			do {
				y = rnd() % n;
			} while (S.count(y));
			if (i == 0) {
				res = query(x, y);
			} else {
				res &= query(x, y);
			}
			S.insert(y);
		}
		return res;
	};

	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	std::shuffle(p.begin(), p.end(), rnd);

	std::vector<int> ans(n, -1);
	int x = p[0];
	ans[x] = calc(x);
	for (int i = 1; i < n && ans[x]; ++i) {
		if (query(p[i], x) == ans[x]) {
			x = p[i];
			ans[x] = calc(x);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == -1) {
			ans[i] = query(x, i);
		}
	}
	std::cout << "!";
	for (int x : ans) {
		std::cout << " " << x;
	}
	std::cout << "\n";
}