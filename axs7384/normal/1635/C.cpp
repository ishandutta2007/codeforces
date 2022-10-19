#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[200005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if (a[n-1]>a[n])
		{
			puts("-1");
		}
		else
		{
			if (a[n]>=0)
			{
				printf("%d\n",n-2);
				for (int i=1;i<=n-2;++i)
					printf("%d %d %d\n",i,n-1,n);
			}
			else
			{
				puts(is_sorted(a+1,a+1+n)?"0":"-1");
			}
		}
	}
	return 0;
}