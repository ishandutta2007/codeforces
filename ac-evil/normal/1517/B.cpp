#include <bits/stdc++.h>
using std::priority_queue;
typedef long long LL;
const int N = 105;
int T, n, m, a[N][N], b[N][N], c[N][N];
struct node1 {
	int x, y;
	bool operator < (const node1 &o) const { return a[x][y] > a[o.x][o.y]; }
};
struct node2 {
	int x, y;
	bool operator < (const node2 &o) const { return a[x][y] < a[o.x][o.y]; }
};
priority_queue<node1> Q;
priority_queue<node2> q[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			while (!q[i].empty()) q[i].pop();
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]), b[i][j] = 0, Q.push((node1){i, j}), q[i].push((node2){i, j});
		}
		int now = 0;
		while (!Q.empty()) {
			int x = Q.top().x, y = Q.top().y; Q.pop();
			if (b[x][y]) continue;
			now++; c[x][now] = a[x][y]; b[x][y] = 1;
			for (int i = 1; i <= n; i++) {
				if (i == x) continue;
				for (;;) {
					int _x = q[i].top().x, _y = q[i].top().y; q[i].pop();
					if (b[_x][_y]) continue;
					c[i][now] = a[_x][_y]; b[_x][_y] = 1;
					break;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				printf("%d%c", c[i][j], " \n"[j == m]);
	}
	return 0;
}