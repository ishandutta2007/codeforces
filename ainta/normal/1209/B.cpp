#include<cstdio>
#include<algorithm>

using namespace std;
int n, res;
int A[110], B[110], w[110];
char p[110];
int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 1; i <= n; i++) {
		w[i] = p[i - 1] - '0';
	}
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	for (i = 0; i < 100000; i++) {
		int s = 0;
		for (j = 1; j <= n; j++)if (w[j])s++;
		res = max(res, s);
		for (j = 1; j <= n; j++) {
			if ((i + 1) % A[j] == B[j] % A[j] && i+1 >= B[j]) {
				w[j] ^= 1;
			}
		}
	}
	printf("%d\n", res);
}