#include<bits/stdc++.h>

typedef long long LL;

const int N=100005;

int n,m,fa[N][20],nx[N],f[N],dep[N];
LL s,w[N],dis[N];
bool vis[N];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d%d%lld",&n,&m,&s);
	for (int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++) if (w[i]>s) {puts("-1");return 0;}
	dep[1]=nx[1]=1;dis[1]=w[1];
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i][0]);
		for (int j=1;j<=16;j++) fa[i][j]=fa[fa[i][j-1]][j-1];
		dep[i]=dep[fa[i][0]]+1;
		dis[i]=dis[fa[i][0]]+w[i];
		nx[i]=i;
		for (int j=16;j>=0;j--)
			if (fa[nx[i]][j]&&dep[i]-dep[fa[nx[i]][j]]+1<=m&&dis[i]-dis[fa[nx[i]][j]]+w[fa[nx[i]][j]]<=s) nx[i]=fa[nx[i]][j];
	}
	for (int i=1;i<=n;i++) f[i]=i;
	int ans=0;
	for (int i=n;i>=1;i--)
		if (!vis[i])
		{
			ans++;
			int x=i;
			while (dep[x]>=dep[nx[i]]) vis[x]=1,f[x]=fa[x][0],x=find(x);
		}
	printf("%d\n",ans);
	return 0;
}