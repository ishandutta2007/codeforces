#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	s += s;
	n *= 2;
	std::vector<int> z(n);
	z[0] = n;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		z[i] = std::max(0, std::min(r - i, z[i - l]));
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i, r = i + z[i];
		}
	}
	for (int i = 1; i < n; ++i) {
		if (i + z[i] < n && s[i + z[i]] > s[z[i]]) {
			s.resize(i);
			break;
		}
	}
	while ((int)s.size() < m) {
		s += s;
	}
	s.resize(m);
	std::cout << s << "\n";
}