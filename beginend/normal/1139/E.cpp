#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=5005;

int n,cnt,d,m,last[N],ans,mat[N],p[N],c[N];
bool vis[N];
struct edge{int to,next,op;}e[N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

bool ins(int x)
{
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]||e[i].op) continue;
		vis[e[i].to]=1;
		if (mat[e[i].to]==-1||ins(mat[e[i].to]))
		{
			mat[e[i].to]=x;
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]),addedge(p[i],c[i]);
	for (int i=1;i<=m;i++) mat[i]=-1;
	for (;;ans++)
	{
		for (int j=1;j<=m;j++) vis[j]=0;
		if (!ins(ans)) break;
	}
	scanf("%d",&d);
	while (d--)
	{
		int x;scanf("%d",&x);
		e[x].op=1;
		if (mat[c[x]]==p[x])
		{
			mat[c[x]]=-1;
			for (int j=0;j<=m;j++) vis[j]=0;
			while (ans>p[x])
			{
				for (int j=0;j<=m;j++) vis[j]=0;
				if (!ins(p[x]))
				{
					ans--;
					for (int j=1;j<=m;j++) if (mat[j]==ans) mat[j]=-1;
				}
				else break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}