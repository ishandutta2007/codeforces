#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

struct Seq {
	std::vector<long long> val;
	int mx, cmx;

public:
	Seq(int n) : val(n, -INF), mx(0), cmx(1) {}

	void update(int x, long long v) {
		val[x] = std::max(val[x], v);
		if (x != mx) {
			if (val[x] > val[mx]) {
				cmx = mx;
				mx = x;
			} else if (val[x] > val[cmx]) {
				cmx = x;
			}
		}
	}

	long long query(int x) {
		if ((int)val.size() == 1) {
			return -INF;
		}
		if (x == mx) {
			return val[cmx];
		} else {
			return val[mx];
		}
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> c[i];
		--c[i];
	}
	std::vector<long long> w(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> w[i];
	}

	std::vector<long long> f(n);
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (c[i] == c[j]) {
				continue;
			}
			long long t = f[i] + abs(w[i] - w[j]);
			f[i] = std::max(f[i], f[j] + abs(w[i] - w[j]));
			f[j] = std::max(f[j], t);
		}
	}
	std::cout << *std::max_element(f.begin(), f.end()) << "\n";
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