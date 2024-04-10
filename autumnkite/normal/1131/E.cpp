#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::function<int(int, char)> solve = [&](int k, char c) {
		if (k < 0) {
			return 0;
		}
		int len = a[k].size(), pre = 0, suf = 0;
		while (pre < len && a[k][pre] == c) {
			++pre;
		}
		while (suf < len && a[k][len - suf - 1] == c) {
			++suf;
		}
		if (pre == len) {
			int t = solve(k - 1, c);
			return (t + 1) * len + t;
		} else {
			bool flag = false;
			for (int i = 0; i < k; ++i) {
				for (char v : a[i]) {
					if (v == c) {
						flag = true;
					}
				}
			}
			int now = 0, res = 0;
			for (int i = 0; i < len; ++i) {
				if (a[k][i] == c) {
					++now;
					res = std::max(res, now);
				} else {
					now = 0;
				}
			}
			if (flag) {
				res = std::max(res, pre + suf + 1);
			}
			return res;
		}
	};

	int ans = 0;
	for (char c = 'a'; c <= 'z'; ++c) {
		ans = std::max(ans, solve(n - 1, c));
	}
	std::cout << ans << "\n";
}