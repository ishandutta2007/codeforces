#include <stdio.h>
#include <algorithm>

int n, arr[100000];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);

	std::sort(arr, arr+n);
	for(int i=0;i<n-2;i++) {
		int a=arr[i]+arr[i+1];
		int b=arr[i+2];
		if(a>b) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;

	return 0;
}