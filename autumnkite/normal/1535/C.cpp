#include <bits/stdc++.h>

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	long long ans = 0;
	for (int k = 0; k < 3; ++k) {
		long long sum = 0;
		int len = 0;
		for (int i = 0; i < n; ++i) {
			bool ok = true;
			if (s[i] != '?') {
				ok = (s[i] ^ '0' ^ (i & 1)) == k;
			}
			if (!ok) {
				len = 0;
			} else {
				++len;
			}
			sum += len;
		}
		if (k < 2) {
			ans += sum;
		} else {
			ans -= sum;
		}
	}
	std::cout << ans << "\n";
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