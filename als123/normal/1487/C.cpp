#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=205;
struct qq
{
	int x,y,last;
}e[N*N];int num,last[N];
bool vis[N*N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
	swap(x,y);
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int d[N];
int mp[N][N];
void dfs (int x)
{
	while (last[x]!=-1)
	{
		int u=last[x],y=e[u].y;
		if (vis[u]) {last[x]=e[u].last;continue;}
		vis[u]=vis[u^1]=true;
		if (x<y) mp[x][y]=1;
		else mp[y][x]=-1;
		dfs(y);
	}
}
void solve ()
{
		memset(mp,0,sizeof(mp));
	memset(vis,false,sizeof(vis));
	num=1;memset(last,-1,sizeof(last));
	int n;
	scanf("%d",&n);
	if (n&1)
	{
		for (int u=1;u<=n;u++)
		for (int i=u+1;i<=n;i++)
		init(u,i);
	}
	else
	{
			for (int u=1;u<=n;u++)
			for (int i=u+1;i<=n;i++) if (u+i!=n+1)
			init(u,i);
	}
	dfs(1);
	for (int u=1;u<=n;u++) 
	for (int i=u+1;i<=n;i++)
	printf("%d ",mp[u][i]);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	solve();
	return 0;
}