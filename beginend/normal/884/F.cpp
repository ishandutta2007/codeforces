#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=105;
const int inf=100000000;

int n,s,t,cnt,last[N*20],dis[N*30],pre[N*20],val[N],a[N],ans,sum[26];
char str[N];
struct edge{int to,next,c,w;}e[N*100];
queue<int> que;
bool vis[N*20];

int point(int x,int y)
{
	return n+26+x*n/2+y;
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
				pre[e[i].to]=i;
				dis[e[i].to]=dis[u]+e[i].w;
				if (!vis[e[i].to]) vis[e[i].to]=1,que.push(e[i].to);
			}
		vis[u]=0;
	}
	return dis[t]!=-inf;
}

void mcf()
{
	ans+=dis[t];
	int x=t;
	while (x!=s)
	{
		e[pre[x]].c--;
		e[pre[x]^1].c++;
		x=e[pre[x]^1].to;
	}
}

int main()
{
	scanf("%d%s",&n,str+1);s=0;t=n+26+26*n/2+1;cnt=1;
	for (int i=1;i<=n;i++) a[i]=str[i]-'a',sum[a[i]]++;
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	for (int i=1;i<=n;i++) addedge(i,t,1,0);
	for (int i=0;i<26;i++) addedge(s,i+n+1,sum[i],0);
	for (int i=0;i<26;i++)
		for (int j=1;j<=n/2;j++)
		{
			addedge(i+n+1,point(i,j),1,0);
			addedge(point(i,j),j,1,a[j]==i?val[j]:0);
			addedge(point(i,j),n-j+1,1,a[n-j+1]==i?val[n-j+1]:0);
		}
	while (spfa()) mcf();
	printf("%d",ans);
	return 0;
}