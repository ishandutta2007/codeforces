#include <bits/stdc++.h>
using std::min;
typedef long long LL;
const int N = 100005;
int T, n, c[N];
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
		int minx = 1 << 30, miny = 1 << 30; LL sumx = 0, sumy = 0, sum = 1LL << 60;
		for (int i = 1; i <= n; i++) {
			if (i & 1) {
				sumx += c[i];
				minx = min(minx, c[i]);
			} else {
				sumy += c[i];
				miny = min(miny, c[i]);
			}
			if (i >= 2) sum = min(sum, sumx + sumy + 1LL * (n - (i + 1) / 2) * minx + 1LL * (n - i / 2) * miny);
		}
		printf("%lld\n", sum);
	}
	return 0;
}