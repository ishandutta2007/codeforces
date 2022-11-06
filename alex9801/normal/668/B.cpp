#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[1000001];
int n;

int val(int x)
{
	return (x%n+n)%n;
}

int main()
{
	int q, c = 0, p = 0, t, x, i;
	scanf("%d%d", &n, &q);

	for(i = 0; i<q; i++)
	{
		scanf("%d", &t);
		if(t==1)
		{
			scanf("%d", &x);
			p = val(p+x);
		}
		else
		{
			if((p+c)%2==0)
				c++;
			else
				c--;

			c = val(c);
		}
	}

	for(i = 0; i<n; i++)
	{
		if(i%2==0)
			arr[val(i+c)] = i;
		else
			arr[val(i-c)] = i;
	}

	for(i = 0; i<n; i++)
		printf("%d ", arr[val(i-p)]+1);
	return 0;
}