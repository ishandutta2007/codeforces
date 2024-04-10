#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=55;
const int M=N*N*N;
const int inf=1e9;

int n,m,k,c,d,cnt,last[M],dis[M],s,t,a[N],pre[M];
bool vis[M];
std::queue<int> que;
struct edge{int to,next,c,w;}e[M*50];

int get(int x,int y)
{
	return (x-1)*n+y;
}

void addedge(int u,int v,int c,int w)
{
	e[++cnt].to=v;e[cnt].c=c;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].c=0;e[cnt].w=-w;e[cnt].next=last[v];last[v]=cnt;
}

bool spfa()
{
	for (int i=s;i<=t;i++) dis[i]=inf;
	dis[s]=0;que.push(s);vis[s]=1;
	while (!que.empty())
	{
		int x=que.front();que.pop();
		vis[x]=0;
		for (int i=last[x];i;i=e[i].next)
			if (e[i].c&&dis[x]+e[i].w<dis[e[i].to])
			{
				dis[e[i].to]=dis[x]+e[i].w;
				pre[e[i].to]=i;
				if (!vis[e[i].to]) vis[e[i].to]=1,que.push(e[i].to);
			}
	}
	return dis[t]<inf;
}

int mcf()
{
	int x=t,mn=inf;
	while (x!=s) mn=std::min(mn,e[pre[x]].c),x=e[pre[x]^1].to;
	x=t;
	while (x!=s)
	{
		e[pre[x]].c-=mn;e[pre[x]^1].c+=mn;
		int id=std::min(pre[x],pre[x]^1);
		if (e[id].w>c) addedge(e[id^1].to,e[id].to,1,e[id].w+d*2);
		x=e[pre[x]^1].to;
	}
	return mn*dis[t];
}

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
	s=0;t=k*k*n+1;cnt=1;
	for (int i=1,x;i<=k;i++) scanf("%d",&x),a[x]++;
	for (int i=1;i<=n;i++) if (a[i]) addedge(s,i,a[i],0);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		for (int j=1;j<k*k;j++) addedge(get(j,x),get(j+1,y),1,c+d),addedge(get(j,y),get(j+1,x),1,c+d);
	}
	for (int i=1;i<k*k;i++)
	{
		for (int j=2;j<=n;j++)
			addedge(get(i,j),get(i+1,j),k,c);
		addedge(get(i+1,1),t,k,0);
	}
	int ans=0;
	while (spfa()) ans+=mcf();
	printf("%d\n",ans);
	return 0;
}