#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> d(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) {
			++d[j];
		}
	}
	std::vector<int> f(n + 1);
	f[0] = 1;
	long long sum = 1;
	for (int i = 1; i <= n; ++i) {
		f[i] = (sum + d[i] - 1) % P;
		sum += f[i];
	}
	std::cout << f[n] << "\n";
}