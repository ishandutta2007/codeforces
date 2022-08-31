#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	long long n, m;
	scanf("%lld%lld", &n, &m);
	if (n > m)swap(n, m);
	if (n == 1) {
		int t = (m - 1) % 6;
		if (t < 3) {
			printf("%lld\n", (m-1) / 6 * 6);
		}
		else {
			printf("%lld\n", (m-1) / 6 * 6 + (t-2) * 2);
		}
		return 0;
	}
	if (n == 2) {
		if (m == 2)printf("0\n");
		else if (m == 3 || m == 7)printf("%lld\n", n*m - 2);
		else printf("%lld\n", n*m);
	}
	else {
		printf("%lld\n", n*m / 2 * 2);
	}
}