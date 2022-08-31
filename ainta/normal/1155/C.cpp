#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
long long w[301000], G, x;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	G = w[2] - w[1];
	for (i = 3; i <= n; i++)G = gcd(G, w[i] - w[i - 1]);
	for (i = 1; i <= m; i++) {
		scanf("%lld", &x);
		if (G%x == 0) {
			puts("YES");
			printf("%lld %d\n", w[1], i);
			return 0;
		}
	}
	puts("NO");
}