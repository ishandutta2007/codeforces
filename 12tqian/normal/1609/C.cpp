#include <bits/stdc++.h>

using namespace std;

template <int N> struct LinearSieve {
	std::bitset<N> pri;
	std::vector<int> pr;
	
	LinearSieve() {
		pri.set();
		pri[0] = pri[1] = 0;
		for (int i = 2; i < N; ++i) {
			if (pri[i]) 
				pr.push_back(i);
			for (int j = 0; j < (int)pr.size() && i * pr[j] < N; ++j) {
				pri[i * pr[j]] = 0;
				if (i % pr[j] == 0) 
					break;
			}
		}
	}
};

const int N = 1e6 + 5;

LinearSieve<N> sieve;

void solve_case(int tc = 0) {
	int n, e;
	cin >> n >> e;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<array<int, 2>>> locs(e);
	for (int i = 0; i < n; ++i) {
		if (sieve.pri[a[i]]) {
			locs[i % e].push_back({1, i / e}); 
		} else if (a[i] == 1) {
			locs[i % e].push_back({0, i / e});
		}
	}
	long long ans = 0;
	for (auto v : locs) {
		int sz = (int)v.size();
		int i1 = 0;
		int i2 = 0;
		while (i1 != sz) {
			while (i2 < sz - 1 && v[i2][1] == v[i2 + 1][1] - 1) {
				++i2;
			}
			vector<int> use;
			for (int i = i1; i <= i2; ++i) {
				use.push_back(v[i][0]);
			}
			auto count = [](vector<int> v) {
				long long ans = 0;
				int sz = (int)v.size();
				int i1 = 0;
				int i2 = 0;
				vector<array<int, 2>> use;
				while (i1 != sz) {
					while (i2 < sz - 1 && v[i2] == v[i2 + 1]) {
						++i2;
					}
					use.push_back({i2 - i1 + 1, v[i1]});
					i1 = ++i2;
				}
				int len = (int)use.size();
				for (int i = 0; i < len; ++i) {
					if (use[i][1] == 0) {
						continue;
					}
					long long l = 1;
					long long r = 1;
					if (i) {
						l += use[i - 1][0];
					}
					if (i < len - 1) {
						r += use[i + 1][0];
					}
					if (use[i][0] == 1) {
						ans += l * r - 1;
					} else {
						ans += l + r - 2;
					}
				}
				return ans;
			};
			ans += count(use);
			i1 = ++i2;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}