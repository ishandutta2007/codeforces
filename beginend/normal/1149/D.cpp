#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=75;
const int inf=1e9;

int n,m,a,b,cnt,last[N],dis[N][N],f[N],dp[N][150005],s[N],id[N],bin[20];
struct edge{int to,next;}e[405];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int merge(int x,int y)
{
	x=find(x);y=find(y);
	if (x!=y) f[x]=y,s[y]+=s[x];
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void floyd()
{
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			dis[i][j]=dis[j][i]=inf;
	for (int i=1;i<=m;i++)
	{
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		if (w==a) dis[x][y]=dis[y][x]=w,merge(x,y);
		else addedge(x,y);
	}
	int tot=0;
	for (int i=1;i<=n;i++) if (f[i]==i&&s[i]>3) id[i]=++tot;
	bin[0]=1;
	for (int i=1;i<=tot;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=cnt;i+=2)
	{
		int x=e[i].to,y=e[i+1].to;
		if (!id[find(x)]&&!id[find(y)]&&find(x)!=find(y)) dis[x][y]=dis[y][x]=b;
	}
	floyd();
	for (int i=1;i<=n;i++)
		for (int j=0;j<bin[tot];j++)
			dp[i][j]=inf;
	if (id[find(1)]) dp[1][bin[id[find(1)]-1]]=0;
	else dp[1][0]=0;
	for (int j=0;j<bin[tot];j++)
		for (int op=0;op<2;op++)
		{
			for (int i=1;i<=n;i++)
			{
				if (dp[i][j]==inf) continue;
				for (int k=1;k<=n;k++)
					if (find(k)==find(i)||!id[find(k)]) dp[k][j]=std::min(dp[k][j],dp[i][j]+dis[i][k]);
			}
			for (int i=1;i<=n;i++)
			{
				if (dp[i][j]==inf) continue;
				for (int k=last[i],p=id[find(e[k].to)];k;k=e[k].next,p=id[find(e[k].to)])
					if (p!=id[find(i)]&&(!p||!(j&bin[p-1]))) dp[e[k].to][j|bin[p-1]]=std::min(dp[e[k].to][j|bin[p-1]],dp[i][j]+b);
			}
		}
	for (int i=1;i<=n;i++)
	{
		int mn=inf;
		for (int j=0;j<bin[tot];j++) mn=std::min(mn,dp[i][j]);
		printf("%d ",mn);
	}
	puts("");
	return 0;
}