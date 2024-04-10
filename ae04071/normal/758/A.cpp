#include <stdio.h>

int n;
int arr[100];

int main()
{
	scanf("%d",&n);
	int max=0;
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		if(max<arr[i]) max=arr[i];
	}

	int sum=0;
	for(int i=0;i<n;i++)
		sum+=max-arr[i];

	printf("%d\n",sum);

	return 0;
}