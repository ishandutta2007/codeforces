#include<cstdio>
#include<algorithm>
using namespace std;
int n, C[101000], Map[101000], cnt = 0, Cur[101000], w[101000], T[101000];
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &C[i]);
		C[i] = n - C[i];
		if (Map[C[i]] == 0) Cur[C[i]] = ++cnt;
		w[i] = Cur[C[i]];
		Map[C[i]] = (Map[C[i]] + 1) % C[i];
	}
	for (i = 1; i <= n; i++) {
		if (Map[i]) {
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	for (i = 1; i <= n; i++) {
		printf("%d ", w[i]);
	}
}