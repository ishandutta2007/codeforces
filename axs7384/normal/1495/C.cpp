#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int n,m,t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%s",a[i]+1);
		for (int i=1;i<=n;i+=3)
		{
			for (int j=1;j<=m;++j)
				a[i][j]='X';
			if (i==n||i==n-1)
				continue;
			if (i==n-2)
			{
				for (int j=1;j<=m;++j)
					if (a[n][j]=='X')
						a[n-1][j]='X';
			}
			else
			{
				int p=1;
				for (int j=1;j<=m;++j)
					if (a[i+1][j]=='X'||a[i+2][j]=='X')
						p=j;
				a[i+1][p]=a[i+2][p]='X';
			}
		}
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=m;++j)
				putchar(a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}