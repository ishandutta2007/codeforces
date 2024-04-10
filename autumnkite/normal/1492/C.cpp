#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::string s, t;
	std::cin >> n >> m;
	std::cin >> s;
	std::cin >> t;
	std::vector<int> pre(n + 1), suf(n + 1);
	for (int i = 0; i < n; ++i) {
		pre[i + 1] = pre[i] + (pre[i] < m && s[i] == t[pre[i]]);
	}
	suf[n] = m;
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = suf[i + 1] - (suf[i + 1] > 0 && s[i] == t[suf[i + 1] - 1]);
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		if (suf[i] == m) {
			break;
		}
		int p = std::lower_bound(pre.begin(), pre.end(), std::max(suf[i], 1)) - pre.begin();
		ans = std::max(ans, i - p + 1);
	}
	std::cout << ans << "\n";
}