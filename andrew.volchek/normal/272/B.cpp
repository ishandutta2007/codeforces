#include <stdio.h>

long long d[35];

int main()
{
	long n;
	scanf("%ld",&n);

	for(long i=0;i<n;i++)
	{
		long a;
		scanf("%ld",&a);

		int c=0;
		while(a)
		{
			if(a&1)
				c++;
			a >>= 1;
		}

		d[c]++;
	}

	long long ans = 0;

	for(int i=0;i<35;i++)
	{
		ans += d[i]*(d[i]-1)/2;
	}

	printf("%I64d",ans);

	return 0;
}