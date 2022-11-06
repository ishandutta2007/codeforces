#include <bits/stdc++.h>
using std::min;
int T, a, b;
int main() {
	scanf("%d", &T);
	while (T--) {
		int ans = 100;
		scanf("%d%d", &a, &b);
		for (int i = 0; i <= 50; i++) {
			int _a = a, _b = b + i, tot = 0;
			if (_b == 1) continue;
			while (_a) tot++, _a /= _b;
			ans = min(ans, i + tot);
		}
		printf("%d\n", ans);
	}
	return 0;
}