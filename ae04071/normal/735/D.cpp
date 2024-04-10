#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	if (n == 2) printf("1\n");
	else if (n == 3) printf("1\n");
	else {
		long long p = 2;
		bool flag = true, tflag = true;;
		for (; p <= 100000ll; p++) {
			if (p * p > n) break;
			if (n % p == 0) {
				flag = false;
			}
			if ((n - 2) % p == 0) {
				tflag = false;
			}
		}
		if (flag) printf("1\n");
		else {
			if (n % 2 == 0) printf("2\n");
			else if (tflag) printf("2\n");
			else printf("3\n");
		}
	}

	return 0;
}