#include<cstdio>
int C1[160] = { 0, 1 }, C2[160] = { -1 }, T[160];
int n;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		for (j = 0; j <= 155; j++) T[j] = C2[j];
		int ck = 0;
		for (j = 1; j <= 155; j++) {
			T[j] += C1[j - 1];
			if (T[j] >= 2 || T[j] <= -2)ck = 1;
		}
		if (!ck) {
			for (j = 0; j <= 155; j++)C2[j] = C1[j];
			for (j = 0; j <= 155; j++)C1[j] = T[j];
			continue;
		}
		for (j = 0; j <= 155; j++) T[j] = C2[j];
		ck = 0;
		for (j = 1; j <= 155; j++) {
			T[j] -= C1[j - 1];
			if (T[j] >= 2 || T[j] <= -2)ck = 1;
		}
		if (!ck) {
			for (j = 0; j <= 155; j++)C2[j] = C1[j];
			for (j = 0; j <= 155; j++)C1[j] = T[j];
			continue;
		}
	}
	printf("%d\n", n);
	for (i = 0; i <= n; i++)printf("%d ", C1[i] * C1[n]);
	printf("\n");
	printf("%d\n", n-1);
	for (i = 0; i < n; i++)printf("%d ", C2[i] * C2[n-1]);
	printf("\n");
}