#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	--n;
	std::vector<long long> a(n + 1);
	for (int i = 0; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::vector<long long> b(n);
	for (int i = 0; i < n; ++i) {
		b[i] = llabs(a[i + 1] - a[i]);
	}
	std::vector<long long> sta1, sta2;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		sta2.push_back(sta2.empty() ? b[i] : std::__gcd(sta2.back(), b[i]));
		while (!sta1.empty() && std::__gcd(sta1.back(), sta2.back()) == 1) {
			sta1.pop_back();
		}
		if (sta1.empty() && sta2.back() == 1) {
			for (int j = i; j > i - (int)sta2.size(); --j) {
				sta1.push_back(sta1.empty() ? b[j] : std::__gcd(sta1.back(), b[j]));
			}
			sta2.clear();
			while (!sta1.empty() && sta1.back() == 1) {
				sta1.pop_back();
			}
		}
		ans = std::max(ans, (int)sta1.size() + (int)sta2.size());
	}
	std::cout << ans + 1 << "\n";
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