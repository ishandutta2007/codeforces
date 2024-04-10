#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=3005;
int n,m,q;
struct qq
{
	int x,y,last;
}s[N];int num,last[N];
void init (int x,int y)
{
	num++;
	s[num].x=x;s[num].y=y;
	s[num].last=last[x];
	last[x]=num;
}
qq e[N];int num1,last1[N];// 
void Init (int x,int y)//
{
	num1++;
	e[num1].x=x;e[num1].y=y;
	e[num1].last=last1[x];
	last1[x]=num1;
}
bool vis[N][N];// 
void bfs (int xx)
{
	queue<int> q;
	q.push(xx);vis[xx][xx]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int u=last1[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			if (vis[y][xx]==true) continue;
			vis[y][xx]=true;
			q.push(y);
		}
	}
}
struct qt
{
	int x,y,k;
	int id;
}Ask[400005];
int ans[400005];
bool cmp (qt a,qt b){return a.y<b.y;}
int f[N][15];//
int solve (int x,int y,int k)
{
	if (f[x][14]!=y) return -1;//
	k--;
	for (int u=14;u>=0;u--)
		if ((1<<u)<=k&&f[x][u]!=y)
		{
			x=f[x][u];
			k-=(1<<u);
		}
	if (k==1) return y;
	if (k==0) return x;
	return -1;
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	num1=0;memset(last1,-1,sizeof(last1));
	scanf("%d%d%d",&n,&m,&q);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);Init(y,x);
	}
	memset(vis,false,sizeof(vis));
	for (int u=1;u<=n;u++)// 
		bfs(u);
	for (int u=1;u<=q;u++)	
	{
		scanf("%d%d%d",&Ask[u].x,&Ask[u].y,&Ask[u].k);
		Ask[u].id=u;
	}
	sort(Ask+1,Ask+1+q,cmp);
	for (int u=1;u<=q;u++)
	{
		int i;
		for (i=u;i<=q;i++)
			if (Ask[i].y!=Ask[u].y)
				break;
		i--;
		int End=Ask[i].y;
		/**/
		for (int j=1;j<=n;j++)
		{
			f[j][0]=0;
			if (vis[j][End]==false) continue;//
			if (j==End) 
			{
				f[j][0]=j;
				continue;
			}
			int shen=3001;
			for (int k=last[j];k!=-1;k=s[k].last)
			{
				int y=s[k].y;
				if (vis[y][End]==true&&y<shen) shen=y; 
			} 
			if (shen!=3001) f[j][0]=shen;
		}
		for (int j=1;j<=14;j++)
			for (int k=1;k<=n;k++)//
				f[k][j]=f[f[k][j-1]][j-1];
		for (int j=u;j<=i;j++)
			ans[Ask[j].id]=solve(Ask[j].x,End,Ask[j].k);
		/**/
		u=i;
	}
	for (int u=1;u<=q;u++) printf("%d\n",ans[u]);
	return 0;
}