#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, Q, P[201000], Next[201000], w[210000], NN[201000][19], V[201000], Res[201000];
int main() {
	int i, j, a, b;
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 0; i < n; i++) {
		scanf("%d", &P[i]);
	}
	for (i = 0; i < n; i++) {
		Next[P[i]] = P[(i + 1) % n];
	}
	for (i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (i = m; i >= 1; i--) {
		if (V[Next[w[i]]]) {
			NN[i][0] = V[Next[w[i]]];
		}
		V[w[i]] = i;
	}
	for (i = 0; i < 18; i++) {
		for (j = 1; j <= m; j++) {
			NN[j][i + 1] = NN[NN[j][i]][i];
		}
	}
	Res[m + 1] = m + 1;
	for (i = m; i >= 1; i--) {
		int b = n - 1;
		int x = i;
		for (j = 0; j <= 18; j++) {
			if ((b >> j) & 1) {
				x = NN[x][j];
			}
		}
		Res[i] = Res[i + 1];
		if (x) {
			Res[i] = min(Res[i], x);
		}
	}
	while (Q--) {
		scanf("%d%d", &a, &b);
		if (Res[a] <= b) {
			printf("1");
		}
		else printf("0");
	}
	puts("");
}