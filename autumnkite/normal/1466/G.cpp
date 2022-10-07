#include <bits/stdc++.h>

const int P = 1000000007;

std::vector<int> KMP(std::string s) {
	int n = s.size();
	std::vector<int> fail(n + 1);
	fail[0] = -1;
	fail[1] = 0;
	for (int i = 1, j = 0; i < n; ++i) {
		while (j && s[j] != s[i]) {
			j = fail[j];
		}
		if (s[j] == s[i]) {
			++j;
		}
		fail[i + 1] = j;
	}
	return fail;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::string s0, t;
	std::cin >> s0;
	std::cin >> t;

	std::vector<int> pw(n + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = 2 * pw[i - 1] % P;
	}
	std::vector<std::vector<int>> sum(n + 1, std::vector<int>(26));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j) {
			sum[i + 1][j] = 2 * sum[i][j] % P;
		}
		++sum[i + 1][t[i] - 'a'];
	}

	while (q--) {
		int k;
		std::string w;
		std::cin >> k >> w;
		std::string s(s0);
		int p = 0;
		while (p < k && s.size() < w.size()) {
			s += t[p] + s;
			++p;
		}
		std::vector<int> pre_fail = KMP(w + '#' + s);
		std::vector<bool> pre(w.size() + 1);
		for (int i = pre_fail.back(); i != -1; i = pre_fail[i]) {
			pre[i] = true;
		}
		std::vector<int> suf_fail = KMP(s + '#' + w);
		std::vector<bool> suf(w.size() + 1);
		for (int i = suf_fail.back(); i != -1; i = suf_fail[i]) {
			suf[(int)w.size() - i] = true;
		}
		int ans = 0;
		for (int i = 0; i < (int)w.size(); ++i) {
			if (pre[i] && suf[i + 1]) {
				ans = (ans + sum[k][w[i] - 'a'] + 1ll * (P - pw[k - p]) * sum[p][w[i] - 'a']) % P;
			}
		}
		for (int x : pre_fail) {
			if (x == (int)w.size()) {
				ans = (ans + pw[k - p]) % P;
			}
		}
		std::cout << ans << "\n";
	}
}