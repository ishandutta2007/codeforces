#include <bits/stdc++.h>

using namespace std;

int t, n, m;
bitset <101> bt[101];

int main()
{
	scanf("%d", &t);
	for(int gh=0; gh<t; ++gh)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; ++i)
		{
			bt[i]^=bt[i];
		}
		for(int i=1; i<=n; ++i)
		{
			bt[i][1]=1;
		}
		for(int i=1; i<=m; ++i)
		{
			bt[1][i]=1;
		}
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=m; ++j)
			{
				if(bt[i][j])
				{
					printf("B");
				}
				else
				{
					printf("W");
				}
			}
			printf("\n");
		}
	}
	return 0;
}