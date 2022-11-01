#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=505;
const int inf=1000000000;

int n,m,cnt,last[N],len[N],s,t,dis[N],pre[N],ans,w[N];
char str[N],a[N][N];
struct edge{int to,c,w,next;}e[N*N*2];
std::queue<int> que;
bool vis[N];

bool check(int x,int y)
{
	if (x+len[y]-1>n) return 0;
	for (int i=1;i<=len[y];i++)
		if (str[x+i-1]!=a[y][i]) return 0;
	return 1;
}

void addedge(int u,int v,int c,int w)
{
	e[++cnt].to=v;e[cnt].c=c;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].c=0;e[cnt].w=-w;e[cnt].next=last[v];last[v]=cnt;
}

bool spfa()
{
	for (int i=s;i<=t;i++) dis[i]=-inf;
	dis[s]=0;que.push(s);vis[s]=1;
	while (!que.empty())
	{
		int u=que.front();que.pop();
		for (int i=last[u];i;i=e[i].next)
			if (e[i].c&&dis[u]+e[i].w>dis[e[i].to])
			{
				dis[e[i].to]=dis[u]+e[i].w;
				pre[e[i].to]=i;
				if (!vis[e[i].to]) vis[e[i].to]=1,que.push(e[i].to);
			}
			
		vis[u]=0;
	}
	return dis[t]>-inf;
}

void mcf()
{
	int mn=inf,x=t;
	while (x!=s)
	{
		mn=std::min(mn,e[pre[x]].c);
		x=e[pre[x]^1].to;
	}
	ans+=dis[t]*mn;
	x=t;
	while (x!=s)
	{
		e[pre[x]].c-=mn;
		e[pre[x]^1].c+=mn;
		x=e[pre[x]^1].to;
	}
}

int main()
{
	scanf("%d%s%d",&n,str+1,&m);
	for (int i=1;i<=m;i++) scanf("%s%d",a[i]+1,&w[i]),len[i]=strlen(a[i]+1);
	int x;
	scanf("%d",&x);
	s=0;t=n+1;cnt=1;
	addedge(s,1,x,0);
	addedge(n,t,x,0);
	for (int i=1;i<n;i++) addedge(i,i+1,x,0);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (check(i,j)) addedge(i,i+len[j]<=n?i+len[j]:t,1,w[j]);
	while (spfa()) mcf();
	printf("%d",ans);
	return 0;
}