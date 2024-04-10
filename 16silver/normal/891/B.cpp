#include <cstdio>
#include <vector>
#include <algorithm>

int a[22], b[22], c[22];

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &a[i]);
	for (i = 0; i < N; i++) {
		c[i] = 0;
		for (j = 0; j < N; j++) {
			if (a[i] > a[j]) c[i]++;
		}
		b[c[i]] = a[i];
	}
	for (i = 0; i < N; i++) {
		if (c[i] == 0) printf("%d ", b[N - 1]);
		else printf("%d ", b[c[i] - 1]);
	}
}