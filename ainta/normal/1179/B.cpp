#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n / 2; i++) {
		for (j = 1; j <= m; j++) {
			printf("%d %d\n", i, j);
			printf("%d %d\n", n-i+1, m+1-j);
		}
	}
	if (n % 2 == 1) {
		for (j = 1; j <= m / 2; j++) {
			printf("%d %d\n", (n + 1) / 2, j);
			printf("%d %d\n", (n + 1) / 2, m+1-j);
		}
		if (m % 2 == 1)printf("%d %d\n", (n + 1) / 2, (m + 1) / 2);
	}
}