#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=300005;
int n,q;
int a[N];
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
int ans[N];
int tot[N];
int fa[N];
void dfs (int x)
{
	tot[x]=1;
	int mx=0,id=x;
	ans[x]=x;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		dfs(y);
		tot[x]=tot[x]+tot[y];
		if (tot[y]>mx)
		{
			mx=tot[y];
			id=y;
		}
	}
	ans[x]=ans[id];
	while (tot[x]-tot[ans[x]]>tot[x]/2) ans[x]=fa[ans[x]];
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&q);
	for (int u=2;u<=n;u++)
	{
		scanf("%d",&fa[u]);
		init(fa[u],u);
	}
	dfs(1);
	while (q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}