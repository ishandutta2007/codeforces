#include<bits/stdc++.h>
using namespace std;
const int N=505,inf=1e9+7;
int f[25][N][N];
int x[N][N];
int y[N][N];
int n,m,K;
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	if (K%2==1)
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				printf("-1%c",j==m?'\n':' ');
		return 0;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<m;++j)
			scanf("%d",&y[i][j]);
	K/=2;
	for (int i=1;i<n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&x[i][j]);
	for (int k=1;k<=K;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
			{
				f[k][i][j]=inf;
				if (i>1)
					f[k][i][j]=min(f[k][i][j],f[k-1][i-1][j]+x[i-1][j]);
				if (i<n)
					f[k][i][j]=min(f[k][i][j],f[k-1][i+1][j]+x[i][j]);
				if (j>1)
					f[k][i][j]=min(f[k][i][j],f[k-1][i][j-1]+y[i][j-1]);
				if (j<m)
					f[k][i][j]=min(f[k][i][j],f[k-1][i][j+1]+y[i][j]);
			}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			printf("%d%c",f[K][i][j]*2,j==m?'\n':' ');
	return 0;
}