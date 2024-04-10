#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	int x, y, num;
	bool operator<(const point &p)const {
		return y - x > p.y - p.x;
	}
}w[301000], ori[301000];
int n, m;
long long R[301000], SX[301000], SY[301000];
int main() {
	int i;
	scanf("%d%d", &n,&m);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].x, &w[i].y);
		w[i].num = i;
		ori[i] = w[i];
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++) {
		SX[i] = SX[i - 1] + w[i].x;
		SY[i] = SY[i - 1] + w[i].y;
	}
	for (i = 1; i <= n; i++) {
		R[w[i].num] += 1ll * w[i].x * (n - i) + 1ll * w[i].y * (i - 1) + SX[i - 1] + SY[n] - SY[i];
	}
	int a, b;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		long long t = min(ori[a].x + ori[b].y, ori[a].y + ori[b].x);
		R[a] -= t;
		R[b] -= t;
	}
	for (i = 1; i <= n; i++)printf("%lld ", R[i]);
}