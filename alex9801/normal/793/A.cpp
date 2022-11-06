#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int arr[100010];

int main()
{
	int n, k, a, i;
	long long r = 0;
	scanf("%d%d", &n, &k);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	a = arr[0];
	for(i = 1; i<n; i++)
		a = std::min(a, arr[i]);

	for(i = 0; i<n; i++)
	{
		if((arr[i] - a) % k != 0)
		{
			printf("-1");
			return 0;
		}
		r += (arr[i] - a) / k;
	}

	printf("%lld", r);
	return 0;
}