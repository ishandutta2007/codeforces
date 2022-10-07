#include <bits/stdc++.h>

const int N = 60;

long long f[N + 1][N + 1];

void init() {
	for (int i = 0; i <= N; ++i) {
		f[0][i] = 1;
	}
	for (int i = 1; i <= N; ++i) {
		f[i][0] = f[i - 1][1];
		for (int j = 1; j <= N - i; ++j) {
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
		}
	}
}

bool query(long long x) {
	std::cout << "? " << x << std::endl;
	std::string res;
	std::cin >> res;
	assert(res != "Fired!");
	return res == "Lucky!";
}

long long solve(int i, int j, long long l, long long r) {
	if (i == 0) {
		return l;
	}
	long long m = std::min(l + (j == 0 ? 0 : f[i - 1][j - 1]), r - 1);
	if (!query(m)) {
		return solve(i - 1, j - 1, l, m);
	} else {
		return solve(i - 1, j + 1, m, r);
	}
}

void solve() {
	long long l = -1, r = -1;
	for (int i = 0; i <= 46; ++i) {
		if (!query(1ll << i)) {
			if (i == 0) {
				std::cout << "! " << 0 << std::endl;
				return;
			}
			l = 1ll << (i - 1);
			r = 1ll << i;
			break;
		}
	}
	if (l == -1) {
		l = 1ll << 46;
		r = 100000000000001ll;
	}
	int k = 0;
	while (f[k][1] < r - l) {
		++k;
	}
	for (int i = 0; i < 6; ++i) {
		query(l);
	}
	long long ans = solve(k, 1, l, r);
	std::cout << "! " << ans << std::endl;
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