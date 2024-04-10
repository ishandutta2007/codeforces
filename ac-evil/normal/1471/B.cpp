#include <bits/stdc++.h>
using std::pair; using std::make_pair; using std::queue;
typedef long long LL;
const int N = 100005;
int T, n, x, a[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &x);
		LL ans = 0;
		queue<pair<int, LL> > Q;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), Q.push(make_pair(a[i], 1));
		int ok = 1;
		while (!Q.empty()) {
			pair<int, LL> u = Q.front(); Q.pop();
			ans += u.first * u.second;
			if (ok) {
				if (u.first % x) ok = 0;
				else Q.push(make_pair(u.first / x, x * u.second));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}