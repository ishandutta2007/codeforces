#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n, w[1010], V[1010][1010], vis[1010];

int main() {
	int i, j;
	scanf("%d", &n);
	int M = 0;
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		M = max(M, w[i]);
	}
	M++;
	for (i = 0; i < n; i++) {
		int Mx = 0, pv = 0;
		for (j = 1; j <= n; j++) {
			if (!vis[j] && Mx < w[j]) {
				Mx = w[j], pv = j;
			}
		}
		vis[pv] = 1;
		for (j = i; j < i + w[pv]; j++) {
			V[j%M][pv] = 1;
		}
	}
	printf("%d\n", M);
	for (i = 0; i < M; i++) {
		for (j = 1; j <= n; j++)printf("%d", V[i][j]);
		puts("");
	}
}