#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1000005;
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int n;
int dep[N],mx[N],son[N];
int fa[N];
void dfs (int x)
{
	mx[x]=dep[x];
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa[x]) continue;
		fa[y]=x;dep[y]=dep[x]+1;dfs(y);
		mx[x]=max(mx[x],mx[y]);
		if (mx[y]>mx[son[x]]) son[x]=y;
	}
}
int ans[N];
int tmp[N],*s[N],*id=tmp;
void update (int now,int x)
{
	//printf("%d %d %d %d\n",now,x,s[now][x],ans[now]);
	if (s[now][x]>s[now][ans[now]]) ans[now]=x;
	else if (s[now][x]==s[now][ans[now]]&&x<ans[now]) ans[now]=x;
}
void solve (int x)
{
	ans[x]=0;s[x][0]=1;
	if (son[x]!=0)
	{
		s[son[x]]=s[x]+1;solve(son[x]);
		update(x,ans[son[x]]+1);
	}
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (y==fa[x]||y==son[x]) continue;
		s[y]=id;id=id+mx[y]-dep[y]+1;solve(y);
		for (int i=0;i<=mx[y]-dep[y];i++) 
		{
			s[x][i+1]=s[x][i+1]+s[y][i];
			update(x,i+1);
		}
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	dep[1]=1;dfs(1);
	s[1]=id;id=id+mx[1];solve(1);
	for (int u=1;u<=n;u++) printf("%d\n",ans[u]);
	return 0;
}