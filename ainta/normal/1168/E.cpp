#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int C[1<<12], A[1<<12], B[1<<12], LA[1<<12], LB[1<<12];
int main() {
	int i, s = 0;
	scanf("%d", &n);
	n = (1 << n);
	for (i = 0; i < n; i++) {
		scanf("%d", &C[i]);
		s ^= C[i];
	}
	if (s) {
		puts("Fou");
		return 0;
	}
	puts("Shi");
	for (i = 0; i < n; i++) {
		A[i] = B[i] = i;
		LA[i] = LB[i] = i;
	}
	for (i = 0; i < n; i++) {
		int u = i;
		while (1) {
			if ((A[u] ^ B[u]) == C[u])break;
			int v = LA[C[u] ^ B[u]];
			swap(A[v], A[u]);
			swap(LA[A[v]], LA[A[u]]);
			if (v > i) break;
			swap(B[v], B[i + 1]);
			swap(LB[B[v]], LB[B[i + 1]]);
			u = v;
		}
	}
	for (i = 0; i < n; i++) printf("%d ", A[i]);
	puts("");
	for (i = 0; i < n; i++) printf("%d ", B[i]);
}