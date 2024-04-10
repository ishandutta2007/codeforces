#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
		{
			if (a[i]!=i||i==n)
			{
				for (int j=1;j<i;++j)
					printf("%d ",a[j]);
				int r=i;
				for (int j=i;j<=n;++j)
					if (a[j]==i)
						r=j;
				for (int j=r;j>=i;--j)
					printf("%d ",a[j]);
				for (int j=r+1;j<=n;++j)
					printf("%d ",a[j]);
				puts("");
				break;
			}
		}
	}
	return 0;
}