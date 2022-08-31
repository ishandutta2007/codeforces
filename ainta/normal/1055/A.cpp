#include<cstdio>
int A[1010], B[1010], x, ck;
int main() {
	int i, n;
	scanf("%d%d", &n, &x);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 1; i <= n; i++)scanf("%d", &B[i]);
	if (A[1]) {
		if (A[x]) {
			puts("YES");
			return 0;
		}
		else {
			for (i = x + 1; i <= n; i++)if (A[i] && B[i] && B[x]) {
				puts("YES");
				return 0;
			} 
		}
	}
	puts("NO");
}