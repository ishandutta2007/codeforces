#include <stdio.h>
#include <algorithm>

int arr[1010];

int main()
{
	int n, a, i;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		scanf("%d", &a);
		arr[a] = 1;
	}

	for(i = 1; i<=998; i++)
	{
		if(arr[i]&&arr[i+1]&&arr[i+2])
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}