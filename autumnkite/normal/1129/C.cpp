#include <bits/stdc++.h>

std::vector<int> build_fail(std::string s) {
	int n = s.size();
	std::vector<int> fail(n + 1);
	fail[0] = -1;
	fail[1] = 0;
	for (int i = 1, j = 0; i < n; ++i) {
		while (j && s[i] != s[j]) {
			j = fail[j];
		}
		if (s[i] == s[j]) {
			++j;
		}
		fail[i + 1] = j;
	}
	return fail;
}

const int P = 1000000007;

std::vector<int> dp(std::string s) {
	auto check = [&](std::string t) {
		return t != "1100" && t != "1010" && t != "0111" && t != "1111";
	};
	int n = s.size();
	std::vector<int> f(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 4 && j <= i; ++j) {
			if (j != 4 || check(s.substr(i - j, j))) {
				f[i] = (f[i] + f[i - j]) % P;
			}
		}
	}
	return f;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::string s;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		std::cin >> c;
		s += c;
		std::string t(s);
		std::reverse(t.begin(), t.end());
		std::vector<int> fail(build_fail(t));
		std::vector<int> f(dp(t));
		int mx = *std::max_element(fail.begin(), fail.end());
		ans = (ans + std::accumulate(f.begin() + mx + 1, f.end(), 0ll)) % P;
		std::cout << ans << "\n";
	}
}