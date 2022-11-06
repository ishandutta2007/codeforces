#include <bits/stdc++.h>
typedef long long LL;
const int N = 100005;
using std::min; using std::max;
int T, x, y;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		LL ans = 0;
		for (int i = 1; i <= (int)sqrt(x); i++) {
			ans += max(0, min(y + 1, x / i) - i - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

// q (b + 1) = a (q < b)