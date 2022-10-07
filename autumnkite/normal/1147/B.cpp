#include <bits/stdc++.h>

const int N = 100005, M = 200005;

int n, m;
std::vector<int> a[N / 2];

int k, s[M << 1], fail[M << 1];

int calc() {
	fail[1] = 0;
	int j = 0;
	for (int i = 2; i <= k; ++i) {
		while (j && s[j + 1] != s[i]) {
			j = fail[j];
		}
		j += s[j + 1] == s[i];
		fail[i] = j;
	}
	int len = k - fail[k];
	if (k % len == 0) {
		return len;
	} else {
		return k;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		--x, --y;
		int t = std::min((y + n - x) % n, (x + n - y) % n);
		a[t].push_back(x);
		a[t].push_back(y);
	}

	int g = 1;
	for (int i = 1; i <= n / 2; ++i) {
		if (!a[i].empty()) {
			std::sort(a[i].begin(), a[i].end());
			k = 0;
			for (int j = 0; j < (int)a[i].size(); ++j) {
				s[++k] = (a[i][(j + 1) % a[i].size()] + n - a[i][j]) % n;
			}
			int t = calc();
			int len = 0;
			for (int j = 1; j <= t; ++j) {
				len += s[j];
			}
			g = g / std::__gcd(g, len) * len;
		}
	}
	if (g == n) {
		std::cout << "No\n";
	} else {
		std::cout << "Yes\n";
	}
}