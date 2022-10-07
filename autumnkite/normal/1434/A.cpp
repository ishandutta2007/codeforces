#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

int n;
int a[6], b[100000];

int solve(int mn) {
	std::vector<int> pos;
	for (int i = 0; i < 6; ++i) {
		int p = std::lower_bound(b, b + n, a[i] + mn) - b;
		pos.push_back(p);
	}
	pos.push_back(n);
	if (pos[0] != 0) {
		return INF;
	}
	int res = 0;
	for (int i = 0; i < 6; ++i) {
		res = std::max(res, b[pos[i + 1] - 1] - a[i]);
	}
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	for (int i = 0; i < 6; ++i) {
		std::cin >> a[i];
	}
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	std::sort(a, a + 6);
	std::sort(b, b + n);

	int ans = b[n - 1] - b[0];
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < n; ++j) {
			int mn = b[j] - a[i];
			int mx = solve(mn);
			if (mx < INF) {
				ans = std::min(ans, mx - mn);
			}
		}
	}
	std::cout << ans << std::endl;
}