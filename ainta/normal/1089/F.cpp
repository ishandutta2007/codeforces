#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 2; i*i <= n; i++) {
		if (n%i == 0 && gcd(i,n/i) == 1) {
			puts("YES");
			puts("2");
			for (j = 1;; j++) {
				int t = (n - 1 - j*(n / i));
				if (t % i == 0) {
					printf("%d %d\n", j, i);
					printf("%d %d\n", t / i, n / i);
					break;
				}
			}
			return 0;
		}
	}
	puts("NO");
}