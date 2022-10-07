#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::string a;
	std::cin >> a;
	int lst = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] != '?') {
			for (int j = i - 1; j > lst; --j) {
				if (a[j + 1] == 'B') {
					a[j] = 'R';
				} else {
					a[j] = 'B';
				}
			}
			lst = i;
		}
	}
	for (int i = lst + 1; i < n; ++i) {
		if (a[i - 1] == 'B') {
			a[i] = 'R';
		} else {
			a[i] = 'B';
		}
	}
	std::cout << a << "\n";
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