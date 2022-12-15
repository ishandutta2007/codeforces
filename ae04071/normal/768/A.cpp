#include <stdio.h>
#include <algorithm>

int n,arr[100000];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	std::sort(arr, arr+n);
	int cnt=0;
	for(int i=0;i<n;i++) {
		if(arr[i]!=arr[0] && arr[i]!=arr[n-1])
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}