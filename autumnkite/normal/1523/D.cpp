#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, p;
	std::cin >> n >> m >> p;
	std::vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		std::string t;
		std::cin >> t;
		for (int j = 0; j < m; ++j) {
			a[i] |= 1ll * (t[j] - '0') << j;
		}
	}

	std::vector<int> bitcnt(1 << p);
	for (int S = 1; S < (1 << p); ++S) {
		bitcnt[S] = bitcnt[S >> 1] + (S & 1);
	}

	std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
	long long ans = 0;
	int ans_cnt = 0;
	for (int _ = 1; _ <= 45; ++_) {
		int k = rnd() % n;
		std::vector<int> x;
		for (int i = 0; i < m; ++i) {
			if (a[k] >> i & 1) {
				x.push_back(i);
			}
		}
		int t = x.size();
		std::vector<int> cnt(1 << t);
		for (int i = 0; i < n; ++i) {
			int v = 0;
			for (int j = 0; j < t; ++j) {
				v |= (a[i] >> x[j] & 1) << j;
			}
			++cnt[v];
		}
		for (int i = 0; i < t; ++i) {
			for (int S = 0; S < (1 << t); ++S) {
				if (S >> i & 1) {
					cnt[S ^ (1 << i)] += cnt[S];
				}
			}
		}
		for (int S = 0; S < (1 << t); ++S) {
			if (cnt[S] >= (n + 1) / 2) {
				if (bitcnt[S] > ans_cnt) {
					ans = 0;
					for (int i = 0; i < t; ++i) {
						ans |= 1ll * (S >> i & 1) << x[i];
					}
					ans_cnt = bitcnt[S];
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		std::cout << (ans >> i & 1);
	}
	std::cout << "\n";
}