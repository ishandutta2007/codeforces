#include <bits/stdc++.h>
typedef long long LL;
const int N = 100005;
int T, n, w[N], d[N];
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		LL ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]), ans += w[i], d[i] = 0;
		std::priority_queue<int> Q;
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			d[u]++, d[v]++;// Q.push(w[u]), Q.push(w[v]);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < d[i]; j++)
				Q.push(w[i]);
		for (int i = 1; i < n; i++) {
			printf("%lld ", ans);
			if (!Q.empty()) ans += Q.top(), Q.pop();
		}
		puts("");
	}
	return 0;
}