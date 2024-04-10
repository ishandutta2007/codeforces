#include <stdio.h>

int arr1[100];
int arr2[100];

int main()
{
	long long a, b, p = 0, q = 0, r = 0, x = 0, y = 0, c1 = 0, c2 = 0;
	scanf("%I64d%I64d", &a, &b);
	while(a)
	{
		arr1[p++] = a%2;
		if(a%2==0)
		{
			c1++;
			x = p;
		}
		a /= 2;
	}
	while(b)
	{
		arr2[q++] = b%2;
		if(b%2==0)
		{
			c2++;
			y = q;
		}
		b /= 2;
	}
	r += x;
	r -= y;
	if(c2==1)
		r++;
	r += q*(q-1)/2;
	r -= p*(p-1)/2;
	printf("%I64d", r);
	return 0;
}