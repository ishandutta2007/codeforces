#include<bits/stdc++.h>
#define pb push_back

typedef long long LL;

const int N=3005;
const LL inf=(LL)1e18;

int n,m,a[N],f[N][N],tmp1[N],size[N];
LL tmp2[N],g[N][N];
std::vector<int> e[N];

void dfs(int x,int fa)
{
	size[x]=1;
	for (int i=1;i<=m;i++) g[x][i]=-inf,f[x][i]=0;
	g[x][1]=a[x];
	for (auto to:e[x])
	{
		if (to==fa) continue;
		dfs(to,x);
		for (int i=1;i<=std::min(m,size[x]+size[to]);i++) tmp1[i]=0,tmp2[i]=-inf;
		for (int i=1;i<=std::min(m,size[x]);i++)
			for (int j=1;j<=std::min(m,size[to]);j++)
			{
				int s1=f[x][i]+f[to][j];
				LL s2=g[x][i]+g[to][j];
				if (s1>tmp1[i+j-1]||s1==tmp1[i+j-1]&&s2>tmp2[i+j-1])
					tmp1[i+j-1]=s1,tmp2[i+j-1]=s2;
				s1=f[x][i]+f[to][j]+(g[to][j]>0);
				s2=g[x][i];
				if (s1>tmp1[i+j]||s1==tmp1[i+j]&&s2>tmp2[i+j])
					tmp1[i+j]=s1,tmp2[i+j]=s2;
			}
		size[x]+=size[to];
		for (int i=1;i<=std::min(m,size[x]);i++) f[x][i]=tmp1[i],g[x][i]=tmp2[i];
	}
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1,x;i<=n;i++) scanf("%d",&x),a[i]=x-a[i];
		for (int i=1;i<n;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			e[x].pb(y);e[y].pb(x);
		}
		dfs(1,0);
		printf("%d\n",f[1][m]+(g[1][m]>0));
	}
	return 0;
}