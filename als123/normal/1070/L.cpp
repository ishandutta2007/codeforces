#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=2005;
int T;
int n,m;
bitset<N> f[N];
int ans[N];
void solve ()
{
	for (int u=1;u<=n;u++)
	{
		int i=u;
		for (;i<=n;i++) if (f[i][u]==1) break;
		if (f[i][u]==0) continue;
		swap(f[u],f[i]);
		for (int j=u+1;j<=n;j++) if (f[j][u]==1) f[j]^=f[u];
	}
	for (int u=n;u>=1;u--)
	{
		ans[u]=f[u][n+1];
		for (int i=u+1;i<=n;i++)
		if (f[u][i]) ans[u]^=ans[i];
	}
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int u=1;u<=n;u++) f[u].reset();
		for (int u=1;u<=m;u++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			f[x][n+1]=f[x][n+1]^1;f[x][x]=f[x][x]^1;f[x][y]=f[x][y]^1;
			f[y][n+1]=f[y][n+1]^1;f[y][y]=f[y][y]^1;f[y][x]=f[y][x]^1;
		}
		bool tf=true;
		for (int u=1;u<=n;u++) if (f[u][n+1]==1) tf=false;
		if (tf)
		{
			printf("1\n");
			for (int u=1;u<=n;u++) printf("1 ");
			printf("\n");
			continue;
		}
		solve();
		printf("2\n");
		for (int u=1;u<=n;u++) printf("%d ",ans[u]+1);
		printf("\n");
	}
	return 0;
}