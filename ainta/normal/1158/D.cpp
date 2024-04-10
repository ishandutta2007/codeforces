#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct point {
	long long x, y;
}w[2010];
long long ccw(point a, point b, point c) {
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}
int n, vis[2010];
char p[2010];
int main() {
	//freopen("input.txt", "r", stdin);
	int i, j;
	scanf("%d", &n);
	int pv = 1;
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld", &w[i].x, &w[i].y);
		if (w[pv].x > w[i].x || (w[pv].x == w[i].x && w[pv].y > w[i].y))pv = i;
	}
	scanf("%s", p);
	vis[pv] = 1;
	for (i = 0; i < n - 2; i++) {
		printf("%d ", pv);
		if (p[i] == 'L') {
			int t = -1;
			for (j = 1; j <= n; j++) {
				if (!vis[j] && (t == -1 || ccw(w[pv], w[t], w[j]) <= 0)) {
					t = j;
				}
			}
			vis[t] = 1;
			pv = t;
		}
		else {
			int t = -1;
			for (j = 1; j <= n; j++) {
				if (!vis[j] && (t == -1 || ccw(w[pv], w[t], w[j]) >= 0)) {
					t = j;
				}
			}
			vis[t] = 1;
			pv = t;
		}
	}
	printf("%d ", pv);
	for (i = 1; i <= n; i++)if (!vis[i])printf("%d\n", i);
}