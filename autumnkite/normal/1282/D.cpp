#include <bits/stdc++.h>

int query(std::string s) {
	std::cout << s << std::endl;
	int res;
	std::cin >> res;
	if (res == 0) {
		exit(0);
	}
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n = query("a") + 1;
	int c;
	if (n > 300) {
		--n;
		c = query(std::string(n, 'a'));
	} else {
		c = query(std::string(n, 'a'));
		if (c == n) {
			--n, --c;
		}
	}
	std::string ans(n, 'a');
	int cb = 0;
	for (int i = 0; i < n - 1; ++i) {
		std::string tmp(n, 'a');
		tmp[i] = 'b';
		if (query(tmp) < c) {
			ans[i] = 'b';
			++cb;
		}
	}
	if (cb < c) {
		ans[n - 1] = 'b';
	}
	query(ans);
}