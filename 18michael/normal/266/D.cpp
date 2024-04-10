#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,ans=inf;
int X[20002],Y[20002],Z[20002],A[202];
int d[202][202],rk[202][202];
inline bool cmp(int x,int y)
{
	return A[x]<A[y]? 1:0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=(i==j? 0:inf),rk[i][j]=j;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&X[i],&Y[i],&Z[i]),d[X[i]][Y[i]]=d[Y[i]][X[i]]=Z[i];
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)A[j]=d[i][j];
		sort(rk[i]+1,rk[i]+n+1,cmp),ans=min(ans,A[rk[i][n]]*2);
	}
	for(int i=1,o;i<=m;++i)
	{
		o=n;
		for(int j=n-1;j;--j)
		{
			if(d[Y[i]][rk[X[i]][j]]<=d[Y[i]][rk[X[i]][o]])continue;
			ans=min(ans,d[Y[i]][rk[X[i]][o]]+d[X[i]][rk[X[i]][j]]+Z[i]),o=j;
		}
	}
	return 0&printf("%.1lf",ans/2.0);
}