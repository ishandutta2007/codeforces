#include <bits/stdc++.h>

const long long INF = 1e18;

long long pw[18];
std::vector<long long> v;

void init() {
	pw[0] = 1;
	for (int i = 1; i < 18; ++i) {
		pw[i] = pw[i - 1] * 10;
	}
	for (int i = 0; i < 18; ++i) {
		for (int x = 1; x < 10; ++x) {
			v.push_back(x * pw[i]);
			for (int j = 0; j < i; ++j) {
				for (int y = 1; y < 10; ++y) {
					v.push_back(x * pw[i] + y * pw[j]);
					for (int k = 0; k < j; ++k) {
						for (int z = 1; z < 10; ++z) {
							v.push_back(x * pw[i] + y * pw[j] + z * pw[k]);
						}
					}
				}
			}
		}
	}
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
}

int solve(long long x) {
	return std::upper_bound(v.begin(), v.end(), x) - v.begin() + (x == INF);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();

	int T = 1;
	std::cin >> T;
	while (T--) {
		long long l, r;
		std::cin >> l >> r;
		std::cout << solve(r) - solve(l - 1) << "\n";
	}
}