#include<cstdio>
#include<algorithm>
using namespace std;
int n, A[1010], B[1010], p1, p2, w[1010];
int main() {
	int i, j;
	scanf("%d%d%d", &n, &p1, &p2);
	for (i = 1; i <= n; i++)scanf("%d", &A[i]);
	for (i = 1; i <= n; i++)scanf("%d", &B[i]);
	long long s = 0;
	for (i = 1; i <= n; i++) {
		w[i] = abs(A[i] - B[i]);
		s += w[i];
	}
	if (s < p1 + p2) {
		printf("%lld\n", (p1 + p2 + s) % 2);
		return 0;
	}
	for (i = 1; i <= p1 + p2; i++) {
		int M = -1, pv = -1;
		for (j = 1; j <= n; j++) {
			if (M < w[j])M = w[j], pv = j;
		}
		w[pv]--;
	}
	s = 0;
	for (i = 1; i <= n; i++)s += 1ll * w[i] * w[i];
	printf("%lld\n", s);
}