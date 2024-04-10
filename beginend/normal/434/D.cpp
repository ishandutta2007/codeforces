#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

typedef long long LL;

const LL Big=(LL)1e9;
const LL inf=(LL)1e15;
const int N=20005;

int n,m,s,t,cnt,last[N],dis[N],cur[N],a[55],b[55],c[55],l[55],r[55],sta[55];
struct edge{int to,next;LL c;}e[N*20];
std::queue<int> que;

int point(int x,int y)
{
	return sta[x]+y-l[x];
}

void addedge(int u,int v,LL c)
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

LL dfs(int x,LL maxf)
{
	if (x==t||!maxf) return maxf;
	LL ret=0;
	for (int &i=cur[x];i;i=e[i].next)
		if (e[i].c&&dis[e[i].to]==dis[x]+1)
		{
			LL f=dfs(e[i].to,std::min(e[i].c,maxf-ret));
			e[i].c-=f;
			e[i^1].c+=f;
			ret+=f;
			if (maxf==ret) break;
		}
	return ret;
}

LL dinic()
{
	LL ans=0;
	while (bfs())
	{
		for (int i=s;i<=t;i++) cur[i]=last[i];
		ans+=dfs(s,inf);
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	int tot=0;cnt=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		sta[i]=tot+1;tot+=r[i]-l[i]+2;
	}
	s=0;t=tot+1;
	for (int i=1;i<=n;i++)
	{
		addedge(s,point(i,l[i]),inf);
		for (int j=l[i];j<=r[i];j++)
			addedge(point(i,j),point(i,j+1),Big-(LL)(a[i]*j*j+b[i]*j+c[i]));
		addedge(point(i,r[i]+1),t,inf);
	}
	for (int i=1;i<=m;i++)
	{
		int u,v,d;scanf("%d%d%d",&u,&v,&d);
		for (int j=l[u];j<=r[u]+1;j++)
			if (j-d>=l[v]&&j-d<=r[v]+1) addedge(point(u,j),point(v,j-d),inf);
	}
	printf("%I64d",(LL)Big*n-dinic());
	return 0;
}