#include <stdio.h>
#include <algorithm>

int arr[500000];

int main()
{
	int n, k, t, b, i;
	long long p, s = 0, c, tt, r1, r2;
	scanf("%d%d", &n, &k);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	if(n==1)
	{
		printf("0");
		return 0;
	}

	std::sort(arr, arr+n);
	for(i = 0; i<n; i++)
		s += arr[i];

	if(s%n==0)
		t = b = s/n;
	else
	{
		t = s/n;
		b = s/n+1;
	}

	r1 = arr[0];
	r2 = arr[n-1];
	c = 0;
	for(i = 0; arr[i]<t; i++)
	{
		p = std::min(arr[i+1], t);
		tt = (i+1)*(p-arr[i]);
		if(c+tt<=k)
		{
			c += tt;
			r1 = p;
		}
		else
		{
			r1 += (k-c)/(i+1);
			break;
		}
	}

	c = 0;
	for(i = n-1; arr[i]>b; i--)
	{
		p = std::max(arr[i-1], b);
		tt = (n-i)*(arr[i]-p);
		if(c+tt<=k)
		{
			c += tt;
			r2 = p;
		}
		else
		{
			r2 -= (k-c)/(n-i);
			break;
		}
	}

	printf("%I64d", r2-r1);
	return 0;
}