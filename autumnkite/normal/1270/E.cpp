#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i] >> b[i];
	}
	int mna = *std::min_element(a.begin(), a.end());
	for (int &v : a) {
		v -= mna;
	}
	int mnb = *std::min_element(b.begin(), b.end());
	for (int &v : b) {
		v -= mnb;
	}

	for (int i = 0; i < n; ++i) {
		c[i] = a[i] + b[i];
	}

	auto solve = [&](std::vector<int> a, std::vector<int> &ans) {
		bool flag = true;
		for (int v : a) {
			flag &= (v & 1) == (a[0] & 1);
		}
		if (!flag) {
			for (int i = 0; i < (int)a.size(); ++i) {
				if (a[i] & 1) {
					ans.push_back(i);
				}
			}
			return true;
		}
		return false;
	};
	
	std::vector<int> ans;
	while (!solve(c, ans) && !solve(a, ans) && !solve(b, ans)) {
		for (int i = 0; i < n; ++i) {
			a[i] >>= 1, b[i] >>= 1;
			c[i] = a[i] + b[i];
		}
	}
	std::cout << ans.size() << "\n";
	for (int x : ans) {
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";
}