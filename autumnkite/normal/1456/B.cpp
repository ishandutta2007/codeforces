#include <bits/stdc++.h>

const int N = 100005, INF = 0x3f3f3f3f;

int n;
int a[N];

int solve(int l, int r, int d) {
	if (l == r || d < 0) {
		return INF;
	}
	int cnt = 0;
	while (r - cnt >= l && a[r - cnt] >> d & 1) {
		++cnt;
	}
	if (cnt >= 3) {
		return 1;
	}
	if (cnt == 2) {
		if ((a[r] ^ a[r - 1]) < a[r - 2]) {
			return 1;
		} else {
			int t = solve(l, r - 2, d - 1);
			int now = a[r - 1];
			for (int i = 1; r - 1 - i >= l; ++i) {
				now ^= a[r - 1 - i];
				if (now > a[r]) {
					t = std::min(t, i);
					break;
				}
			}
			a[r - 1] ^= a[r];
			t = std::min(t, solve(l, r - 1, d - 1) + 1);
			a[r - 1] ^= a[r];
			return t;
		}
	}
	if (cnt == 1) {
		return solve(l, r - 1, d - 1);
	}
	return solve(l, r, d - 1);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	int ans = solve(1, n, 29);
	if (ans < INF) {
		std::cout << ans << "\n";
	} else {
		std::cout << -1 << "\n";
	}
}