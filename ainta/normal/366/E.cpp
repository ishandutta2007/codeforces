#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, Mn[10][2], Mx[10][2], K, L, res;
int main() {
	int i, j, a, b;
	scanf("%d%d%d%d", &n, &m,&K,&L);
	for (i = 1; i <= K; i++) {
		Mx[i][0] = Mx[i][1] = -1e9;
		Mn[i][0] = Mn[i][1] = 1e9;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &a);
			Mn[a][0] = min(Mn[a][0], i + j);
			Mx[a][0] = max(Mx[a][0], i + j);
			Mn[a][1] = min(Mn[a][1], i - j);
			Mx[a][1] = max(Mx[a][1], i - j);
		}
	}
	for (i = 1; i <= L; i++) {
		scanf("%d", &a);
		if (i > 1) {
			res = max(res, max(max(Mx[b][1] - Mn[a][1], Mx[b][0] - Mn[a][0]), max(Mx[a][1] - Mn[b][1], Mx[a][0] - Mn[b][0])));
		}
		b = a;
	}
	printf("%d\n", res);
}