#include<cstdio>
#include<algorithm>
using namespace std;
long long Get(long long n, long long x, int ck) {
	if (n == 1)return 1;
	if (!ck) {
		if (x <= n && x % 2 == 1)return (x + 1) / 2;
		if (n % 2 == 0) return n / 2 + Get(n / 2, x / 2, 0);
		return (n + 1) / 2 + Get(n / 2, x / 2, 1);
	}
	if (x <= n && x % 2 == 0)return x / 2;
	if (n % 2 == 0)return n / 2 + Get(n / 2, (x+1) / 2, 1);
	return n / 2 + Get((n + 1) / 2, (x + 1) / 2, 0);
}
int main() {
	long long n;
	int Q;
	scanf("%lld", &n);
	scanf("%d", &Q);
	while (Q--) {
		long long x;
		scanf("%lld", &x);
		printf("%lld\n", Get(n, x, 0));
	}
}