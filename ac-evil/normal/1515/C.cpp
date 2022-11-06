#include <bits/stdc++.h>
using std::priority_queue;
const int N = 100005;
int T, n, m, x, h[N], a[N];
struct Node {
	int x;
	bool operator < (const Node &o) const {
		return a[x] > a[o.x];
	}
};
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &x);
		for (int i = 1; i <= n; i++)
			scanf("%d", &h[i]);
		priority_queue<Node> Q;
		for (int i = 1; i <= m; i++)
			a[i] = 0, Q.push({i});
		puts("YES");
		for (int i = 1; i <= n; i++) {
			int u = Q.top().x; Q.pop();
			printf("%d ", u); a[u] += h[i];
			Q.push({u});
		}
		puts("");
	}
	return 0;
}