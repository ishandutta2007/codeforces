#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef long long LL;
typedef pair<LL,int> pi;

const int N=200005;
const LL inf=(LL)1e18;

int n,m,cnt,last[N];
LL dis[N];
bool vis[N];
struct edge{int to,next;LL w;}e[N*4];
priority_queue<pi> que;

void addedge(int u,int v,LL w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void dij()
{
	for (int i=1;i<=n;i++) dis[i]=inf;
	que.push(mp(0,0));
	while (!que.empty())
	{
		int x=que.top().second;que.pop();
		while (!que.empty()&&vis[x]) x=que.top().second,que.pop();
		if (vis[x]) break;
		vis[x]=1;
		for (int i=last[x];i;i=e[i].next)
			if (dis[x]+e[i].w<dis[e[i].to])
			{
				dis[e[i].to]=dis[x]+e[i].w;
				que.push(mp(-dis[e[i].to],e[i].to));
			}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;LL z;scanf("%d%d%I64d",&x,&y,&z);
		addedge(x,y,z*2);
	}
	for (int i=1;i<=n;i++)
	{
		LL w;scanf("%I64d",&w);
		addedge(0,i,w);
	}
	dij();
	for (int i=1;i<=n;i++) printf("%I64d ",dis[i]);
	return 0;
}