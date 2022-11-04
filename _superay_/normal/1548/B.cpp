#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
long long a[N], b[N];
pair<long long, int> c[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for (int i = 1; i < n; i++) b[i] = abs(a[i] - a[i + 1]);
		int ans = 0, tp = 0;
		for (int i = 1; i < n; i++) {
			c[++tp] = make_pair(b[i], i);
			for (int j = tp - 1; j >= 1; j--) c[j].first = __gcd(c[j + 1].first, c[j].first);
			int nt = 0;
			for (int j = 1; j <= tp; j++) {
				if (!nt || c[nt].first != c[j].first) c[++nt] = c[j];
			}
			tp = nt;
			int fir = (c[1].first == 1ll ? 2 : 1);
			if (fir <= tp) ans = max(ans, i - c[fir].second + 1);
		}
		ans++;
		printf("%d\n", ans);
	}
	return 0;
}