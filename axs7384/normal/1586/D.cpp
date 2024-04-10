#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[10000];
int main()
{
	scanf("%d",&n);
	//check n
	printf("? ");
	for (int i=1;i<n;++i)
		printf("1 ");
	puts("2");
	fflush(stdout);
	scanf("%d",&x);
	if (x==0)
	{
		a[n]=n;
	}
	else
	{
		for (int i=n-2;i>=1;--i)
		{
			printf("? ");
			for (int j=1;j<n;++j)
				printf("1 ");
			printf("%d\n",n-i+1);
			fflush(stdout);
			scanf("%d",&x);
			if (x==0)
			{
				a[n]=i+1;
				break;
			}
		}
		if (!a[n])
			a[n]=1;
	}
	for (int i=1;i<=n;++i)
		if (i!=a[n])
		{
			printf("? ");
			for (int j=1;j<n;++j)
				printf("%d ",n+1-i);
			printf("%d\n",n+1-a[n]);
			fflush(stdout);
			scanf("%d",&x);
			if (x)
				a[x]=i;
		}
	printf("! ");
	for (int i=1;i<=n;++i)
		printf("%d ",a[i]);
	fflush(stdout);
	return 0;
}