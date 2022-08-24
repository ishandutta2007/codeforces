#include<cstdio>
#include<algorithm>
using namespace std;
struct point {
	int a, b, c;
}w[110];
int n, K, D[110][20100], BS = 10000;
int main() {
	int i, j;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) scanf("%d", &w[i].a);
	for (i = 1; i <= n; i++) scanf("%d", &w[i].b);
	for(i=1;i<=n;i++){
		w[i].c = w[i].a - w[i].b*K;
	}
	for (i = 0; i <= n; i++)for (j = 0; j < 20100; j++)D[i][j] = -1e9;
	D[0][BS] = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j < 20100; j++) {
			if (D[i][j] < 0)continue;
			D[i + 1][j] = max(D[i + 1][j], D[i][j]);
			int t = j + w[i + 1].c;
			if (t < 0 || t>2 * BS)continue;
			D[i + 1][t] = max(D[i + 1][t], D[i][j] + w[i + 1].a);
		}
	}
	if (D[n][BS] == 0)puts("-1");
	else printf("%d\n", D[n][BS]);
}