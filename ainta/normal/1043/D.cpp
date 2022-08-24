#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int n, m, w[101000][20];
int Loc[101000][20];
long long res;
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &w[j][i]);
			Loc[w[j][i]][i] = j;
		}
	}
	int pv = 1;
	for (i = 1; i <= n; i++) {
		if (pv < i)pv = i;
		while (pv+1<=n) {
			int a = w[pv][1], b = w[pv + 1][1];
			for (j = 1; j <= m; j++)if (Loc[a][j] + 1 != Loc[b][j])break;
			if (j != m + 1)break;
			pv++;
		}
		res += pv - i + 1;
	}
	printf("%lld\n", res);
}