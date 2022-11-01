#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>

typedef long long LL;

const int N=100005;
const int inf=1000000000;

int n,m,k,s,cnt,last[N],dis[N];
struct edge{int to,next;}e[N*2];
std::vector<int> vec[N];
std::queue<int> que;
std::priority_queue<int> w[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void bfs()
{
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=last[x];i;i=e[i].next)
			if (dis[x]+1<dis[e[i].to])
			{
				dis[e[i].to]=dis[x]+1;
				que.push(e[i].to);
			}
	}
	for (int i=1;i<=n;i++)
	{
		if (w[i].size()==s&&w[i].top()<=dis[i]) continue;
		if (w[i].size()==s) w[i].pop();
		w[i].push(dis[i]);
	}
}

int main()
{
	n=read();m=read();k=read();s=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		vec[x].push_back(i);
	}
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n;j++) dis[j]=inf;
		for (int j=0;j<vec[i].size();j++) que.push(vec[i][j]),dis[vec[i][j]]=0;
		bfs();
	}
	for (int i=1;i<=n;i++)
	{
		LL ans=0;
		while (!w[i].empty()) ans+=w[i].top(),w[i].pop();
		printf("%I64d ",ans);
	}
	return 0;
}