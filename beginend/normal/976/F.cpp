#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=2005;
const int inf=1000000000;

int n1,n2,m,s,t,num[N*2],cnt,last[N*2],cur[N*2],dis[N*2],tot[N],ans[N][N],deg[N*2];
struct edge{int to,c,next;}e[N*10];
std::queue<int> que;

void addedge(int u,int v,int c)
{
	e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].c=0;e[cnt].next=last[v];last[v]=cnt;
}

bool bfs()
{
	for (int i=s;i<=t;i++) dis[i]=0;
	while (!que.empty()) que.pop();
	dis[s]=1;que.push(s);
	while (!que.empty())
	{
		int u=que.front();que.pop();
		for (int i=last[u];i;i=e[i].next)
			if (e[i].c&&!dis[e[i].to])
			{
				dis[e[i].to]=dis[u]+1;
				if (e[i].to==t) return 1;
				que.push(e[i].to);
			}
	}
	return 0;
}

int dfs(int x,int maxf)
{
	if (x==t||!maxf) return maxf;
	int ret=0;
	for (int &i=cur[x];i;i=e[i].next)
		if (e[i].c&&dis[e[i].to]==dis[x]+1)
		{
			int f=dfs(e[i].to,std::min(e[i].c,maxf-ret));
			e[i].c-=f;
			e[i^1].c+=f;
			ret+=f;
			if (maxf==ret) break;
		}
	return ret;
}

void dinic()
{
	while (bfs())
	{
		for (int i=s;i<=t;i++) cur[i]=last[i];
		dfs(s,inf);
	}
}

int main()
{
	scanf("%d%d%d",&n1,&n2,&m);
	s=0;t=n1+n2+1;cnt=1;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		deg[x]++;deg[y+n1]++;
		addedge(x,y+n1,1);
	}
	int mn=m,tmp=cnt;
	for (int i=1;i<=n1+n2;i++) mn=std::min(mn,deg[i]);
	for (int i=1;i<=n1;i++) addedge(s,i,deg[i]-mn),num[i]=cnt;
	for (int i=n1+1;i<=n1+n2;i++) addedge(i,t,deg[i]-mn),num[i]=cnt;
	for (int i=mn;i>=0;i--)
	{
		dinic();
		for (int j=2;j<=tmp;j+=2)
			if (e[j].c) ans[i][++tot[i]]=j/2;
		for (int j=1;j<=n1+n2;j++)
			e[num[j]^1].c++;
	}
	for (int i=0;i<=mn;i++)
	{
		printf("%d ",tot[i]);
		for (int j=1;j<=tot[i];j++) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}