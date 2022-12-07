#include <bits/stdc++.h>

using namespace std;

int t[200][2];

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d", &t[i][0], &t[i][1]);
	}
	for(int i=1; i<=n; ++i)
	{
		int zl=0;
		for(int j=1; j<=n; ++j)
		{
			if(abs(t[i][0]-t[j][0])+abs(t[i][1]-t[j][1])<=k)
			{
				++zl;
			}
		}
		if(zl==n)
		{
			printf("1\n");
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}