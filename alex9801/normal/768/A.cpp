#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[100000];

int main()
{
	int n, r = 0, x, y, i;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	std::sort(arr, arr+n);

	x = arr[0];
	y = arr[n-1];

	for(i = 0; i<n; i++)
	{
		if(x<arr[i] && arr[i]<y)
			r++;
	}

	printf("%d", r);

	return 0;
}