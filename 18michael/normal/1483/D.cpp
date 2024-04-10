#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m,q,ans=0;
LL val[602][602],l[602][602],dis[602][602],mx[602][602];
bool u[602][602];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)val[i][j]=inf,l[i][j]=mx[i][j]=-inf;
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),scanf("%lld",&val[x][y]),val[y][x]=val[x][y];
	for(int i=1;i<=n;dis[i][i]=0,++i)for(int j=1;j<=n;++j)dis[i][j]=val[i][j];
	scanf("%d",&q);
	for(int i=1,x,y;i<=q;++i)scanf("%d%d",&x,&y),scanf("%lld",&l[x][y]),l[y][x]=l[x][y];
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)mx[i][j]=max(mx[i][j],l[i][k]-dis[j][k]);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)for(int k=1;k<=n;++k)u[j][k]|=(dis[i][j]+val[j][k]<=mx[i][k]);
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)ans+=(u[i][j]|u[j][i]);
	return 0&printf("%d",ans);
}