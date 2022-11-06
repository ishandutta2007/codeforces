#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[1000];

int main()
{
	int n, a, t;
	long long nn, i;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	std::sort(arr, arr+n);

	t = arr[0];

	nn = 3500000000;
	a = 0;
	for(i = 0; i<nn; i++)
	{
		arr[0] += i;
	}

	printf("%d", t);
	for(i = 1; i<n; i++)
		printf(" %d", arr[i]);
	return 0;
}