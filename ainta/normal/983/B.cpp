#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[5010], D[5010][5010], G[5010][5010];
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		//w[i] = i;
	}
	for (i = 1; i <= n; i++)G[i][i] = D[i][i] = w[i];
	for (int L = 2; L <= n; L++) {
		int s = 0;
		int cnt = 0;
		int t = 0;
		for (i = 1; i <= n - L + 1; i++) {
			j = i + L - 1;
			t = 0;
			G[i][j] = G[i][j - 1] ^ G[i + 1][j];
			D[i][j] = max(max(D[i + 1][j], D[i][j - 1]), G[i][j]);
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int b, e;
		scanf("%d%d", &b, &e);
		printf("%d\n", D[b][e]);
	}
}