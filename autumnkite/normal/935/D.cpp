#include <bits/stdc++.h>

const int N = 100005, P = 1000000007;

int n, m, a[N], b[N];

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> b[i];
	}
	
	int invm = qpow(m, P - 2);
	int ans = 0;
	int now = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] && b[i]) {
			if (a[i] == b[i]) {
				continue;
			} else {
				if (a[i] > b[i]) {
					ans = (ans + now) % P;
				}
				break;
			}
		}
		if (!a[i] && !b[i]) {
			ans = (ans + 1ll * m * (m - 1) / 2 % P * invm % P * invm % P * now) % P;
			now = 1ll * now * invm % P;
			continue;
		}
		if (!a[i]) {
			ans = (ans + 1ll * (m - b[i]) * invm % P * now) % P;
			now = 1ll * now * invm % P;
		} else {
			ans = (ans + 1ll * (a[i] - 1) * invm % P * now) % P;
			now = 1ll * now * invm % P;
		}
	}
	std::cout << ans << "\n";
}