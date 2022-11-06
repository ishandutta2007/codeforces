#include <stdio.h>

int arr[100];

int main()
{
	int mn=2100000000,a,t,n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
	{
		t=0;
		for(j=0;j<arr[i];j++)
		{
			scanf("%d",&a);
			t+=5*a+15;
		}
		mn=t<mn?t:mn;
	}
	printf("%d",mn);
	return 0;
}