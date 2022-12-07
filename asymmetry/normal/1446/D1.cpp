#include <bits/stdc++.h>

using namespace std;

int n, m, g, pg, s, odp;
int t[200001];
int zl[101];
int poz[400001];

int main()
{
	scanf("%d", &n);
	m=min(n, 100);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		++zl[t[i]];
	}
	for(int i=1; i<=m; ++i)
	{
		if(g<zl[i])
		{
			g=zl[i];
			pg=i;
		}
	}
	//~ printf("PG=%d\n", pg);
	for(int i=1; i<=m; ++i)
	{
		if(i==pg) continue;
		//~ printf("i=%d;\n", i);
		s=0;
		for(int j=0; j<=n<<1; ++j)
		{
			poz[j]=1e9;
		}
		poz[n]=0;
		for(int j=1; j<=n; ++j)
		{
			if(t[j]==pg)
			{
				++s;
			}
			if(t[j]==i)
			{
				--s;
			}
			//~ printf("%d ", s);
			odp=max(odp, j-poz[n+s]);
			poz[n+s]=min(poz[n+s], j);
		}
		//~ printf("\n");
	}
	printf("%d\n", odp);
	return 0;
}