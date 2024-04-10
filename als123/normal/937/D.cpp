#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=200005;
int n,m;
struct qq
{
	int x,y,last;
}e[N];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
bool f[2][N];
int d[N];
int xx;
int sta[N];
bool tf=false;
bool vis[N];
void dfs (int x,int y,int now)
{
	if (d[y]==0&&x==1)
	{
		printf("Win\n");
		for (int u=1;u<=now;u++) printf("%d ",sta[u]);
		exit(0);
	}
	tf|=vis[y];
	if (f[x][y]) 	return ;
	vis[y]=true;
	f[x][y]=true;
	for (int u=last[y];u!=-1;u=e[u].last)
	{
		int yy=e[u].y;
		sta[now+1]=yy;
		dfs(x^1,yy,now+1);
	}
	vis[y]=false;
}
int main()
{
	memset(vis,false,sizeof(vis));
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&d[u]);
		for (int i=1;i<=d[u];i++)
		{
			int y;
			scanf("%d",&y);
			init(u,y);
		}
	}
	scanf("%d",&xx);
	sta[1]=xx;dfs(0,xx,1);
	if (tf) printf("Draw");
	else printf("Lose");
	return 0;
}