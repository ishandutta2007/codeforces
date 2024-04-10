#include <bits/stdc++.h>

int d, k;

void solve() {
	std::cin >> d >> k;
	for (int i = 1; i <= d; ++i) {
		if (2ll * i * i * k * k > 1ll * d * d) {
			if ((1ll * i * i + 1ll * (i - 1) * (i - 1)) * k * k > 1ll * d * d) {
				std::cout << "Utkarsh\n";
			} else {
				std::cout << "Ashish\n";
			}
			return;
		}
	}
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