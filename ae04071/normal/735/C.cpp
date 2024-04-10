#include <stdio.h>

int main()
{
	long long n;
	scanf("%lld", &n);
	
	int cnt = 1;
	long long prev = 1, now = 2;
	while (n >= now + prev) {
		cnt++;
		long long temp =prev;
		prev = now;
		now = now + temp;
		if (now < 0) break;
	}

	printf("%d\n", cnt);

	return 0;
}