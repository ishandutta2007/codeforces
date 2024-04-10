#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int w[110][110], n, m, Q[110], head ,tail;
int D[110][110][27], Deg[110];
void Do(int x, int y) {
	int i, j;
	for (i = 1; i <= 26; i++) {
		for (j = 1; j <= n; j++) {
			if (w[x][j] < i)continue;
			if (!D[y][j][w[x][j]])D[x][y][i] = 1;
		}
	}
}
int main() {
	int i, j, a, b, k;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		char pp[2];
		scanf("%d%d%s", &a, &b, pp);
		Deg[b]++;
		w[a][b] = pp[0] - 'a' + 1;
	}
	for (i = 1; i <= n; i++)if (!Deg[i])Q[++tail] = i;
	while (head < tail) {
		int x = Q[++head];
		for (i = 1; i <= n; i++) {
			if (w[x][i]) {
				Deg[i]--;
				if (!Deg[i])Q[++tail] = i;
			}
		}
	}
	for (i = tail; i >= 1; i--) {
		for (j = tail; j > i; j--) {
			Do(Q[i], Q[j]);
		}
		for (j = tail; j > i; j--) {
			Do(Q[j], Q[i]);
		}
		Do(Q[i], Q[i]);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (D[i][j][1])printf("A");
			else printf("B");
		}
		printf("\n");
	}
}