#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&k);
		if (k==1)
		{
			puts("YES");
			for (int i=1;i<=n;++i)
				printf("%d\n",i);
		}
		else
		{
			if (n%2==0)
			{
				puts("YES");
				int cnt=1;
				for (int i=1;i<=n/2;++i)
					for (int j=1;j<=k;++j)
					{
						printf("%d%c",cnt,(j==k?'\n':' '));
						cnt+=2;
					}
				cnt=2;
				for (int i=1;i<=n/2;++i)
					for (int j=1;j<=k;++j)
					{
						printf("%d%c",cnt,(j==k?'\n':' '));
						cnt+=2;
					}
			}
			else
			{
				puts("NO");
			}
		}
	}
	return 0;
}