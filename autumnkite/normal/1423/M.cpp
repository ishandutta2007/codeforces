#include <bits/stdc++.h>

int query(int x, int y) {
	static std::map<std::pair<int, int>, int> mp;
	std::pair<int, int> tmp(x, y);
	if (mp.count(tmp)) {
		return mp[tmp];
	}
	std::cout << "? " << x + 1 << " " << y + 1 << std::endl;
	int res;
	std::cin >> res;
	return mp[tmp] = res;
}

std::vector<int> reduce(std::vector<int> X, std::vector<int> Y) {
	std::list<int> c(Y.begin(), Y.end());
	auto x = X.begin();
	auto y = c.begin();
	while (c.size() > X.size()) {
		if (query(*x, *y) > query(*x, *std::next(y))) {
			y = c.erase(y);
			if (y != c.begin()) {
				--x, --y;
			}
		} else if (*x == X.back()) {
			c.erase(std::next(y));
		} else {
			++x, ++y;
		}
	}
	return std::vector<int>(c.begin(), c.end());
}

void SMAWK(std::vector<int> X, std::vector<int> Y, std::vector<int> &ans) {
	Y = reduce(X, Y);
	if ((int)X.size() == 1) {
		ans[X[0]] = Y[0];
		return;
	}
	std::vector<int> r;
	for (int i = 0; i < (int)X.size(); i += 2) {
		r.push_back(X[i]);
	}
	SMAWK(r, Y, ans);
	int p = 0;
	for (int i = 1; i < (int)X.size(); i += 2) {
		while (Y[p] < ans[X[i - 1]]) {
			++p;
		}
		int l = p, r;
		if (i + 1 == (int)X.size()) {
			r = (int)Y.size() - 1;
		} else {
			while (Y[p] < ans[X[i + 1]]) {
				++p;
			}
			r = p;
		}
		ans[X[i]] = Y[l];
		for (int j = l + 1; j <= r; ++j) {
			if (query(X[i], Y[j]) < query(X[i], ans[X[i]])) {
				ans[X[i]] = Y[j];
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> X(n), Y(m);
	for (int i = 0; i < n; ++i) {
		X[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		Y[i] = i;
	}
	std::vector<int> ans(n);
	SMAWK(X, Y, ans);
	int mn = query(0, ans[0]);
	for (int i = 1; i < n; ++i) {
		mn = std::min(mn, query(i, ans[i]));
	}
	std::cout << "! " << mn << std::endl;
}