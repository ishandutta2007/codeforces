#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		if (a+b+2>n||abs(a-b)>1)
		{
			puts("-1");
			continue;
		}
		if (a==b)
		{
			for (int i=1;i<=a+1;++i)
				printf("%d %d ",i,i+a+1);
			for (int i=2*a+3;i<=n;++i)
				printf("%d ",i);
		}
		if (a==b+1)
		{
			swap(a,b);
			printf("%d ",(n+1)-(a+b+2));
			for (int i=1;i<=b;++i)
				printf("%d %d ",n+1-i,n+1-(i+b));
			for (int i=a+b+3;i<=n;++i)
				printf("%d ",n+1-i);
			swap(a,b);
		}
		if (b==a+1)//xiao duo   daxiaodaxiao
		{
			printf("%d ",a+b+2);
			for (int i=1;i<=b;++i)
				printf("%d %d ",i,i+b);
			for (int i=a+b+3;i<=n;++i)
				printf("%d ",i);
		}
		puts("");
	}
}