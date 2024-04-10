#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, M = -1;
int main() {
	int i, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (a > M + 1) {
			printf("%d\n", i);
			return 0;
		}
		M = max(M, a);
	}
	printf("-1\n");
}