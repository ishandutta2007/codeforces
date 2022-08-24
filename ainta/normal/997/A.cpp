#include<cstdio>
#include<algorithm>
using namespace std;
int n, c[2];
char p[301000];
long long x, y, res = 1e18;
int main() {
	int i, j;
	scanf("%d%lld%lld", &n, &x, &y);
	scanf("%s", p + 1);
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n&&p[j] == p[i]; j++);
		c[p[i]-'0']++;
		i = j - 1;
	}
	if (c[0] == 0) {
		puts("0");
		return 0;
	}
	for (i = 1; i <= c[0]; i++) {
		res = min(res, y*i + (c[0] - i)*x);
	}
	printf("%lld\n", res);
}