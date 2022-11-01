#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=55;
const int inf=1e9;

int n,m,h,cnt,last[N*N],dis[N*N],cur[N*N],s,t;
struct edge{int to,next,c;}e[N*N*N];
std::queue<int> que;

int point(int x,int y)
{
	return (x-1)*h+y;
}

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
		int x=que.front();que.pop();
		for (int i=last[x];i;i=e[i].next)
			if (e[i].c&&!dis[e[i].to])
			{
				dis[e[i].to]=dis[x]+1;
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
		if (e[i].c&&dis[x]+1==dis[e[i].to])
		{
			int f=dfs(e[i].to,std::min(e[i].c,maxf-ret));
			e[i].c-=f;
			e[i^1].c+=f;
			ret+=f;
			if (maxf==ret) continue;
		}
	return ret;
}

int dinic()
{
	int ans=0;
	while (bfs())
	{
		for (int i=s;i<=t;i++) cur[i]=last[i];
		ans+=dfs(s,inf);
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&n,&h,&m);
	s=0;t=h*n+m+1;cnt=1;
	for (int i=1;i<=n;i++)
	{
		addedge(s,point(i,0),h*h);
		for (int j=0;j<h-1;j++)
			addedge(point(i,j),point(i,j+1),h*h-(j+1)*(j+1));
	}
	for (int i=1;i<=m;i++)
	{
		int l,r,x,c;scanf("%d%d%d%d",&l,&r,&x,&c);
		if (x==h) continue;
		for (int j=l;j<=r;j++) addedge(point(j,x),i+h*n,inf);
		addedge(i+h*n,t,c);
	}
	printf("%d\n",h*h*n-dinic());
	return 0;
}