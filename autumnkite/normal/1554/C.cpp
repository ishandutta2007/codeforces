#include <bits/stdc++.h>

const int LG = 30;

void solve() {
	int n, m;
	std::cin >> n >> m;
	++m;
	int now = 0;
	for (int i = LG - 1; i >= 0; --i) {
		if (now + (1 << i) <= m && (((now ^ n) >> i) << i) + (1 << i) <= m) {
			now += 1 << i;
		}
	}
	std::cout << now << "\n";
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