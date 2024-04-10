#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1005;
const int inf=1000000000;

int n,m,s,t,d1[N],d2[N],ma[N][N];
queue<int> que;

void bfs()
{
	for (int i=1;i<=n;i++) d1[i]=d2[i]=inf;
	d1[s]=0;que.push(s);
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=1;i<=n;i++)
			if (ma[x][i]&&d1[x]+1<d1[i])
			{
				d1[i]=d1[x]+1;
				que.push(i);
			}
	}
	d2[t]=0;que.push(t);
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=1;i<=n;i++)
			if (ma[x][i]&&d2[x]+1<d2[i])
			{
				d2[i]=d2[x]+1;
				que.push(i);
			}
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ma[x][y]=ma[y][x]=1;
	}
	bfs();
	int ans=0;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (!ma[i][j]&&min(d1[i]+d2[j],d2[i]+d1[j])+1>=d1[t]) ans++;
	printf("%d",ans);
	return 0;
}