#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;

int n,cnt,last[N],f[N][4];
struct edge{int to,next,c;}e[N*2];
LL ans;
bool p[4][4];

void addedge(int u,int v,int c)
{
	e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].c=c;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int fa)
{
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		int to=e[i].to;
		dfs(to,x);
		if (e[i].c)
		{
			f[to][1]++;
			f[to][2]+=f[to][0];
			f[to][0]=f[to][3]=0;
		}
		else
		{
			f[to][0]++;
			f[to][3]+=f[to][1];
			f[to][2]=f[to][1]=0;
		}
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++)
				if (p[j][k]) ans+=(LL)f[x][j]*f[to][k]+(LL)f[x][k]*f[to][j];
		for (int j=0;j<4;j++) f[x][j]+=f[to][j];
	}
	ans+=f[x][0]*2+f[x][1]*2+f[x][2]+f[x][3];
}

int main()
{
	p[0][0]=p[0][1]=p[0][3]=p[1][1]=p[2][1]=1;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}