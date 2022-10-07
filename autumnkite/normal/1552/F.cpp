#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<int> x(n), y(n), s(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i] >> s[i];
	}
	
	std::vector<int> f(n), sum(n + 1);
	for (int i = 0; i < n; ++i) {
		int p = std::lower_bound(x.begin(), x.end(), y[i]) - x.begin();
		f[i] = ((sum[i] + P - sum[p]) % P + x[i] - y[i]) % P;
		sum[i + 1] = (sum[i] + f[i]) % P;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i]) {
			ans = (ans + f[i]) % P;
		}
	}
	std::cout << (x.back() + 1 + ans) % P << "\n";
}