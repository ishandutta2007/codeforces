#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=205;
const int inf=1e9;

int n,m,cnt,last[N],dis[N],cur[N],w1[N],w2[N],s,t;
std::queue<int> que;
struct edge{int to,next,c;}e[N*N*10];
struct data{int x1,y1,x2,y2;}a[N];
bool tag[N][N];

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
	scanf("%d%d",&n,&m);
	int t1=0,t2=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
		a[i].x2++;a[i].y2++;
		w1[++t1]=a[i].x1;w1[++t1]=a[i].x2;
		w2[++t2]=a[i].y1;w2[++t2]=a[i].y2;
	}
	std::sort(w1+1,w1+t1+1);
	std::sort(w2+1,w2+t2+1);
	t1=std::unique(w1+1,w1+t1+1)-w1-1;
	t2=std::unique(w2+1,w2+t2+1)-w2-1;
	s=0;t=t1+t1+1;cnt=1;
	for (int i=1;i<t1;i++) addedge(s,i,w1[i+1]-w1[i]);
	for (int i=1;i<t2;i++) addedge(i+t1,t,w2[i+1]-w2[i]);
	for (int i=1;i<=m;i++)
	{
		int x1=std::lower_bound(w1+1,w1+t1+1,a[i].x1)-w1;
		int x2=std::lower_bound(w1+1,w1+t1+1,a[i].x2)-w1;
		int y1=std::lower_bound(w2+1,w2+t2+1,a[i].y1)-w2;
		int y2=std::lower_bound(w2+1,w2+t2+1,a[i].y2)-w2;
		for (int j=x1;j<x2;j++)
			for (int k=y1;k<y2;k++)
				tag[j][k]=1;
	}
	for (int i=1;i<t1;i++)
		for (int j=1;j<t2;j++)
			if (tag[i][j]) addedge(i,j+t1,inf);
	printf("%d\n",dinic());
	return 0;
}