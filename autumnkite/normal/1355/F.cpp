#include <bits/stdc++.h>

const int N = 630;
const int LIMX = 1000000000;
const long long LIMQ = 1ll * LIMX * LIMX;

std::vector<int> prime;

void init() {
	static bool vis[N + 1];
	for (int i = 2; i <= N; ++i) {
		if (!vis[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= N; j += i) {
				vis[j] = true;
			}
		}
	}
}

long long query(long long x) {
	std::cout << "? " << x << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void solve() {
	long long Q = 1;
	std::vector<int> now;
	std::vector<int> pf;
	for (int i = 0; i <= (int)prime.size(); ++i) {
		if (i == (int)prime.size() || Q > LIMQ / prime[i]) {
			int t = query(Q);
			for (int p : now) {
				if (t % p == 0) {
					pf.push_back(p);
				}
			}
			now.clear();
			Q = 1;
		}
		if (i < (int)prime.size()) {
			Q *= prime[i];
			now.push_back(prime[i]);
		}
	}

	int ans = 1;
	auto calc = [&](int x) {
		int res = 1;
		while (res <= LIMX / x) {
			res *= x;
		}
		return res;
	};
	for (int i = 0; i < (int)pf.size(); i += 2) {
		int r = std::min(i + 2, (int)pf.size());
		long long s = 1;
		for (int j = i; j < r; ++j) {
			s *= calc(pf[j]);
		}
		int t = query(s);
		for (int j = i; j < r; ++j) {
			int c = 0;
			while (t % pf[j] == 0) {
				t /= pf[j];
				++c;
			}
			ans *= c + 1;
		}
	}
	std::cout << "! " << std::max(8, 2 * ans) << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}