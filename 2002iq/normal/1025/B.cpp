#include <iostream>
#include <stdlib.h>
using namespace std;
int n;
pair<int,int> arr[150005];
bool test(int x)
{
	for (int i=0;i<n;i++)
	{
		if (arr[i].first%x && arr[i].second%x)
		return 0;
	}
	return 1;
}
void go(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (test(i))
		{
			printf("%d",i);
			exit(0);
		}
		while (x%i==0)
		x/=i;
	}
	if (x>1 && test(x))
	{
		printf("%d\n",x);
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d%d",&arr[i].first,&arr[i].second);
	go(arr[0].first);
	go(arr[0].second);
	printf("-1");
}