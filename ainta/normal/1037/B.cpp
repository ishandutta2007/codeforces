#include<cstdio>
#include<algorithm>
using namespace std;
int w[201000], M;
int main() {
	int n, i, s = 0;
	scanf("%d%d", &n,&M);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	sort(w + 1, w + n + 1);
	int pv = (n + 1) / 2;
	if (w[pv] == M) {
		puts("0");
		return 0;
	}
	long long res = 0;
	if (w[pv] < M) {
		for (i = pv; i <= n; i++) {
			res += max(M - w[i], 0);
		}
	}
	else {
		for (i = pv; i >= 1; i--) {
			res += max(w[i] - M, 0);
		}
	}
	printf("%lld\n", res);
}