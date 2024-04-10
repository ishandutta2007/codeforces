#include <bits/stdc++.h>

const int P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> c[i];
	}
	std::vector<int> b(n);
	for (int i = 0; i < n - 1; ++i) {
		int v;
		std::cin >> v;
		b[i + 1] = b[i] + v;
	}

	const int B = 100000;
	std::vector<int> ans(2 * B + 1, -1);

	auto DP = [&](int x) -> int {
		if (ans[x + B] != -1) {
			return ans[x + B];
		}
		int sum = 0, lim = 0;
		bool all0 = true, flag = true;
		for (int i = 0; i < n; ++i) {
			sum += c[i], lim += x + b[i];
			all0 &= lim <= 0;
			flag &= lim <= sum;
		}
		if (all0 && ans[0] != -1) {
			return ans[x + B] = ans[0];
		}
		if (!flag) {
			return ans[x + B] = 0;
		}
		std::vector<int> f(sum + 1, 0);
		sum = 0, lim = 0;
		f[0] = 1;
		for (int i = 0; i < n; ++i) {
			sum += c[i], lim += x + b[i];
			int s = 0;
			for (int k = 0; k <= c[i]; ++k) {
				s = (s + f[sum - k]) % P;
			}
			for (int j = sum; j >= 0; --j) {
				int t = j < lim ? 0 : s;
				s = (s + P - f[j]) % P;
				if (j > c[i]) {
					s = (s + f[j - c[i] - 1]) % P;
				}
				f[j] = t;
			}
		}
		return ans[x + B] = std::accumulate(f.begin(), f.end(), 0ll) % P;
	};

	DP(-100000);

	int q;
	std::cin >> q;
	while (q--) {
		int x;
		std::cin >> x;
		std::cout << DP(x) << "\n";
	}
}