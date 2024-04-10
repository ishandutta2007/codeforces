#include <stdio.h>

int Min(int a, int b, int c)
{
	if (a < b) {
		return(a < c) ? a : c;
	}
	else {
		return(b < c) ? b : c;
	}
}

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	long long sum = 0;
	int cnt = Min(a, c, d);
	sum += 256ll * cnt;
	a -= cnt;

	cnt = (a < b) ? a : b;
	sum += 32ll * cnt;
	printf("%lld\n", sum);
	
	
	return 0;
}