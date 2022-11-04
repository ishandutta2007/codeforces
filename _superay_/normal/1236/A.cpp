#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int ans = 0;
		for (int i = 0; i <= a; i++) {
			if (b - 2 * i < 0) continue;
			int cur = 3 * i;
			int tb = b - 2 * i;
			tb = min(tb, c / 2);
			cur += 3 * tb;
			ans = max(ans, cur);
		}
		printf("%d\n", ans);
	}
	return 0;
}