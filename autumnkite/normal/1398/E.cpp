#include <bits/stdc++.h>

int q;

int main() {
	scanf("%d", &q);
	std::set<int> a, b, S;
	long long ans = 0;
	auto it = S.begin();
	while (q--) {
		int tp, x;
		scanf("%d%d", &tp, &x);
		if (x < 0) {
			x = -x;
			ans -= x;
			if (tp == 0) {
				b.erase(x);
				if (it != S.end() && x >= *it) {
					ans -= x;
					--it;
					ans += *it;
				}
			} else {
				a.erase(x);
				if (it != S.end() && x >= *it) {
					ans -= x;
					if (*it == x) {
						++it;
					}
				} else {
					ans -= *it;
					++it;
				}
			}
			S.erase(x);
		} else {
			ans += x;
			S.insert(x);
			if (tp == 0) {
				b.insert(x);
				if (it != S.end() && x > *it) {
					ans -= *it;
					++it;
					ans += x;
				}
			} else {
				a.insert(x);
				if (it != S.end() && x > *it) {
					ans += x;
				} else {
					--it;
					ans += *it;
				}
			}
		}
		if (a.empty()) {
			printf("%lld\n", ans);
		} else if (b.empty()) {
			printf("%lld\n", ans - *a.begin());
		} else if (*a.begin() > *(--b.end())) {
			printf("%lld\n", ans - *a.begin() + *(--b.end()));
		} else {
			printf("%lld\n", ans);
		}
	}
}