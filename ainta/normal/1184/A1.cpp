#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	long long r, x, y;
	scanf("%lld", &r);
	for (x = 1; x < 2e6; x++) {
		long long t = r - x * x - x - 1;
		if (t > 0 && t % (2 * x) == 0) {
			printf("%lld %lld\n", x, t / (2 * x));
			return 0;
		}
	}
	puts("NO");
}