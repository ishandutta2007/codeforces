#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a,b;
void solve (int x,int y)
{
	for (int u=1;u<=n;u++)
	{
		if (x>0)
		{
			int l=u,r=u+a-1;
			for (int i=1;i<a;i++)
				printf("%d ",l+i);
			printf("%d ",l);
			x--;u=r;
		}
		else
		{
			int l=u,r=u+b-1;
			for (int i=1;i<b;i++)
				printf("%d ",l+i);
			printf("%d ",l);
			u=r;
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int u=0;u<=n/a;u++)//a
	{
		if ((n-u*a)%b==0)
		{
			solve(u,(n-u*a)/b);
		return  0;
		}
	}
	printf("-1");
	return 0;
}