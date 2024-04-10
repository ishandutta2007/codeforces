#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=1000003;

int n,m;
int ans[N];
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1 1\n");
		return 0;
	}
	if(n==2)
	{
		printf("1 1 2 2\n");
		return 0;
	}
	int l1=1,r1=n,l2=n+1,r2=n*2-1;
	ans[l1]=1;
	ans[r1]=1;
	ans[l2]=2;
	ans[r2]=2;
	for(int i=3;i<n;++i)
	{
		if((r1-l1)>(r2-l2))
		{
			++l1;
			--r1;
			ans[l1]=i;
			ans[r1]=i;
		}
		else
		{
			++l2;
			--r2;
			ans[l2]=i;
			ans[r2]=i;
		}
	}
	for(int i=1;i<=n*2;++i)
	{
		if(!ans[i])
		{
			printf("%d ",n);
			continue;
		}
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}