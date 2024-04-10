#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		if (m*2-1>n)
		{
			puts("-1");
		}
		else
		{
			for (int i=1;i<=n;++i)
			{
				for (int j=1;j<=n;++j)
					putchar(i==j&&i<=m*2-1&&i%2==1?'R':'.');
				putchar('\n');
			}
		}
	}
	return 0;
}