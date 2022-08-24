#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int i, n = 4, a, b, c, d, K;
	scanf("%d", &K);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a = min(a, b);
		c = min(c, d);
		if (K >= a + c) {
			printf("%d %d %d\n", i + 1, a, K - a);
			return 0;
		}
	}
	puts("-1");
}