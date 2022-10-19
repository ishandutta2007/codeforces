#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			printf("%d ",i);
			for (int j=n;j;--j)
				if (i!=j)
					printf("%d ",j);
			puts("");
		}
	}
	return 0;
}