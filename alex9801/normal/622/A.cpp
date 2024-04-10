#include <stdio.h>

int main()
{
	long long n, s = 0, g = 15000000, x;
	scanf("%I64d", &n);

	while(s<g)
	{
		x = (s+g+1)/2;
		if(x*(x+1)/2 < n)
			s = x;
		else
			g = x-1;
	}

	printf("%I64d", n - s*(s+1)/2);
	return 0;
}