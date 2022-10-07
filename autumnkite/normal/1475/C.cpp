#include <bits/stdc++.h>

const int N = 200005;

int na, nb, m;
int da[N], db[N];

void solve() {
	std::cin >> na >> nb >> m;
	for (int i = 1; i <= na; ++i) {
		da[i] = 0;
	}
	for (int i = 1; i <= nb; ++i) {
		db[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		std::cin >> x;
		++da[x];
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		std::cin >> x;
		++db[x];
	}
	long long ans = 1ll * m * (m - 1) / 2;
	for (int i = 1; i <= na; ++i) {
		ans -= 1ll * da[i] * (da[i] - 1) / 2;
	}
	for (int i = 1; i <= nb; ++i) {
		ans -= 1ll * db[i] * (db[i] - 1) / 2;
	}
	std::cout << ans << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}