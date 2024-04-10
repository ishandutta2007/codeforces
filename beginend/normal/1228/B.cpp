#include<bits/stdc++.h>

const int N=1005;
const int MOD=1000000007;

int n,m,a[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		for (int j=1;j<=x;j++) a[i][j]=1;
		a[i][x+1]=2;
	}
	int ans=1;
	for (int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		for (int j=1;j<=x;j++)
			if (a[j][i]==2) ans=0;
			else a[j][i]=1;
		if (a[x+1][i]==1) ans=0;
		else a[x+1][i]=2;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!a[i][j]) ans=ans*2%MOD;
	printf("%d\n",ans);
	return 0;
}