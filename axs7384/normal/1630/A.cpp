#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		if (n==4&&k==3)
		{
			puts("-1");
			continue;
		}
		if (k==0)
		{
			for (int i=0;i<n/2;++i)
				printf("%d %d\n",i,n-1-i);
			continue;
		}
		if (k==n-1)
		{
			puts("1 3");
			printf("%d %d\n",n-1,n-2);
			printf("%d %d\n",0,n-4);
			printf("%d %d\n",2,n-3);
			for (int i=4;i<n/2;++i)
				printf("%d %d\n",i,n-1-i);
			continue;
		}
		printf("%d %d\n",k,n-1);
		printf("%d %d\n",0,n-1-k);
		for (int i=1;i<n/2;++i)
			if (i!=k&&i!=n-1-k)
				printf("%d %d\n",i,n-1-i);
	}
	return 0;
}

// 0    1   2   3
// n-1 n-2 n-3 n-4