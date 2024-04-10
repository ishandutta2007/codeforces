#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[102][102];
int cnt[102][102][102];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=n;++i)
		for(scanf("%d",&x);x--;)
		{
			scanf("%d%d",&y,&z);
			for(int j=y;j<=z;++j)++cnt[j][y][z];
		}
	for(int i=1;i<=m;++i)
	{
		for(int j=m;j;--j)for(int k=1;k<m;++k)cnt[i][j][k+1]+=cnt[i][j][k];
		for(int j=m;j>1;--j)for(int k=1;k<=m;++k)cnt[i][j-1][k]+=cnt[i][j][k];
	}
	for(int i=0;i<m;++i)for(int j=1;j+i<=m;++j)for(int k=j;k<=j+i;++k)f[j][j+i]=max(f[j][j+i],f[j][k-1]+f[k+1][j+i]+cnt[k][j][j+i]*cnt[k][j][j+i]);
	return 0&printf("%d",f[1][m]);
}