#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, w[510][510];
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1) {
		puts("0");
		return 0;
	}
	if (m == 1) {
		for (i = 1; i <= n; i++) {
			printf("%d\n", i + 1);
		}
		return 0;
	}
	for (i = 1; i <= n; i++) {
		int x = i + m;
		if (i == 1)x = 1;
		for (j = 2; j <= m + 1; j++) {
			printf("%d ", x*j / gcd(x, j));
		}
		puts("");

	}
}