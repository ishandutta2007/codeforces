#include<cstdio>
int n, C[201000], Dep[201000], m, par1[201000], BE[201000], ED[201000], par2[201000];
int main() {
	int i, j, ck = 0;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		scanf("%d", &C[i]);
		for (j = m + 1; j <= m + C[i]; j++) {
			Dep[j] = i;
			par1[j] = par2[j] = m;
		}
		BE[i] = m + 1, ED[i] = m + C[i];
		m += C[i];
	}
	for (i = 1; i <= n; i++) {
		if (C[i] >= 2 && C[i - 1] >= 2) {
			par2[ED[i]] = BE[i - 1];
			ck = 1;
		}
	}
	if (!ck) {
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	for (i = 1; i <= m; i++)printf("%d ", par1[i]); printf("\n");
	for (i = 1; i <= m; i++)printf("%d ", par2[i]); printf("\n");
}