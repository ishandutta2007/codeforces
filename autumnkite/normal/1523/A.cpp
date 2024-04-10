#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	std::vector<int> l(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			l[i] = 0;
		} else if (i > 0) {
			l[i] = l[i - 1] + 1;
		} else {
			l[i] = m + 1;
		}
	}
	std::vector<int> r(n);
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '1') {
			r[i] = 0;
		} else if (i + 1 < n) {
			r[i] = r[i + 1] + 1;
		} else {
			r[i] = m + 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0' && l[i] != r[i] && std::min(l[i], r[i]) <= m) {
			s[i] = '1';
		}
	}
	std::cout << s << "\n";
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