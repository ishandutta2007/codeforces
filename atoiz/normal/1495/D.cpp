/*input
2 1
1 2

8 9
1 2
1 3
1 4
2 7
3 5
3 6
4 8
2 3
3 4

*/

#include <stdio.h>
#include <string.h>

#define P 998244353
#define MAXN 403
#define MAXM 603
int N, M, D[MAXN][MAXN], ans[MAXN][MAXN], E[MAXM][2];

int path[MAXN], cnt[MAXN];
int calc_two(int a, int b) {
	int d = D[a][b];
	memset(path, 0, sizeof(path[0]) * (N + 1));
	memset(cnt, 0, sizeof(cnt[0]) * (N + 1));
	for (int u = 1; u <= N; ++u) {
		if (D[a][u] + D[u][b] == d) {
			if (path[D[a][u]]) return 0;
			path[D[a][u]] = u;
		}
	}

	for (int i = 0; i < M; ++i) {
		int u = E[i][0], v = E[i][1];
		if (D[a][u] + 1 == D[a][v] && D[b][u] + 1 == D[b][v]) ++cnt[v];
		if (D[a][v] + 1 == D[a][u] && D[b][v] + 1 == D[b][u]) ++cnt[u];
	}

	long long p = 1;
	for (int u = 1; u <= N; ++u) {
		if (path[D[a][u]] != u) {
			p = (p * cnt[u]) % P;
		}
	}
	return (int) p;
}

int calc_one(int a) {
	memset(cnt, 0, sizeof(cnt[0]) * (N + 1));
	for (int i = 0; i < M; ++i) {
		int u = E[i][0], v = E[i][1];
		if (D[a][u] + 1 == D[a][v]) ++cnt[v];
		if (D[a][v] + 1 == D[a][u]) ++cnt[u];
	}

	long long p = 1;
	for (int u = 1; u <= N; ++u) {
		if (u != a) {
			p = (p * cnt[u]) % P;
		}
	}
	return (int) p;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			D[i][j] = N + 2;
		}
		D[i][i] = 0;
	}

	for (int i = 0; i < M; ++i){
		scanf("%d %d", &E[i][0], &E[i][1]);
		D[E[i][0]][E[i][1]] = D[E[i][1]][E[i][0]] = 1;
	}

	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				int d = D[i][k] + D[k][j];
				D[i][j] = (D[i][j] < d) ? D[i][j] : d;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i < j) {
				printf("%d ", ans[i][j] = calc_two(i, j));
			} else if (i > j) {
				printf("%d ", ans[j][i]);
			} else {
				printf("%d ", calc_one(i));
			}
		}
		puts("");
	}
}