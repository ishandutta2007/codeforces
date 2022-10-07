#include <bits/stdc++.h>

const int N = 105;

int n;
int l[N], r[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= 2 * n; ++i) {
		int x;
		std::cin >> x;
		if (l[x]) {
			r[x] = i;
		} else {
			l[x] = i;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (l[i] < l[j]) {
				if (l[j] < r[i]) {
					if (r[i] < r[j]) {
						++ans;
					} else {
						ans += 2;
					}
				}
			}
		}
	}
	std::cout << ans << "\n";
}