#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 

#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, x, y;
	std::cin >> n >> x >> y;
	std::bitset<200001> a, s;
	for (int i = 0; i <= n; ++i) {
		int v;
		std::cin >> v;
		a.set(v);
	}
	for (int i = 0; i <= x; ++i) {
		if (a[i]) {
			s |= a >> i;
		}
	}
	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int L;
		std::cin >> L;
		L /= 2;
		int ans = -1;
		for (int d = 1; d * d <= L; ++d) {
			if (L % d == 0) {
				if (d > y && d - y <= x && s[d - y]) {
					ans = std::max(ans, d);
				}
				int t = L / d;
				if (t > d && t > y && t - y <= x && s[t - y]) {
					ans = std::max(ans, t);
				}
			}
		}
		std::cout << (ans == -1 ? -1 : 2 * ans) << " ";
	}
	std::cout << "\n";
}