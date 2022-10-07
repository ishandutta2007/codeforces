#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	
	std::vector<int> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
	}
	if (sum[n] != 0) {
		std::cout << 0 << "\n";
		std::cout << 1 << " " << 1 << "\n";
		return 0;
	}

	std::vector<int> pre(n + 1), suf(n + 1), prec(n + 1), sufc(n + 1);
	prec[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pre[i] = std::min(pre[i - 1], sum[i]);
		prec[i] = (pre[i - 1] == pre[i]) * prec[i - 1] + (i < n && sum[i] == pre[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = std::min(suf[i + 1], sum[i]);
		sufc[i] = (suf[i + 1] == suf[i]) * sufc[i + 1] + (sum[i] == suf[i]);
	}

	int ans = prec[n];
	int ansi = 0, ansj = 0;
	for (int i = 0, j = n; i + 1 < n; ++i) {
		while (j > 0 && suf[j - 1] >= pre[i]) {
			--j;
		}
		if (i + 1 < j && s[i] == ')' && s[j - 1] == '(' && suf[i + 1] + 2 >= pre[i]) {
			int t = prec[i] + (suf[j] == pre[i]) * sufc[j] + (suf[i + 1] + 2 == pre[i]) * sufc[i + 1];
			if (t > ans) {
				ans = t;
				ansi = i, ansj = j - 1;
			}
		}
	}
	for (int i = 1, j = 0, c = 0; i < n; ++i) {
		j = std::max(j, i - 1);
		while (j + 1 < n && sum[j + 1] >= pre[n] + 2) {
			++j;
			c += sum[j] == pre[n] + 2;
		}
		if (i <= j) {
			if (s[i - 1] == '(' && s[j] == ')') {
				int t = (pre[i - 1] == pre[n]) * prec[i - 1] + (suf[j + 1] == pre[n]) * sufc[j + 1] + c;
				if (t > ans) {
					ans = t;
					ansi = i - 1, ansj = j;
				}
			}
			c -= sum[i] == pre[n] + 2;
		}
	}
	for (int i = 1, j = 0, c = 0; i < n; ++i) {
		j = std::max(j, i - 1);
		while (j + 1 < n && sum[j + 1] >= pre[n] + 1) {
			++j;
			c += sum[j] == pre[n] + 1;
		}
		if (i <= j) {
			if (s[i - 1] == '(' && s[j] == ')') {
				int t = c;
				if (t > ans) {
					ans = t;
					ansi = i - 1, ansj = j;
				}
			}
			c -= sum[i] == pre[n] + 1;
		}
	}
	std::cout << ans << "\n";
	std::cout << ansi + 1 << " " << ansj + 1 << "\n";
}