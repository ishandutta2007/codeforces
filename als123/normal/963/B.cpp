#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005*2;
struct qq{int x,y,last;}e[N];
int num,last[N];
int f[N];
int d[N];
int n;
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int ans[N],now=0;
bool ok[N];
void dfs (int x,int fa)
{
	//printf("%d %d\n",x,fa);
	f[x]=fa;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		//printf("%d\n",y);
		if (y==fa) continue;
		dfs(y,x);
	}
	if (d[x]%2==0)// 
	{
		ok[x]=true;
		ans[++now]=x;
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			d[y]--;
		}
	}
}
void dfs2 (int x)
{
	//printf("OZY:%d\n",x);
	if (d[x]%2==0)
	{
		ans[++now]=x;ok[x]=true;
		for (int u=last[x];u!=-1;u=e[u].last)
		{
			int y=e[u].y;
			d[y]--;
		}
	}
	else {printf("NO\n");exit(0);}
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (ok[y]) continue;
		dfs2(y);
	}
}
int main()
{
	memset(ok,false,sizeof(ok));ok[0]=true;
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	int rt;
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		
		if (x!=0) 
		{d[u]++;d[x]++;
			init(x,u);
			init(u,x);
		}
		else rt=u;
	}
	dfs(rt,0);
	//for (int u=1;u<=n;u++) printf("%d ",f[u]);
	//for (int u=1;u<=n;u++) printf("%d ",d[u]);
	//for (int u=1;u<=now;u++) printf("ok:%d\n",ans[u]);
	for (int u=1;u<=n;u++)
	{
		if (ok[u]) continue;
		if (ok[f[u]])	dfs2(u);
	}
	//if (now!=n) printf("NO\n");
	printf("YES\n");
	for (int u=1;u<=now;u++) printf("%d\n",ans[u]);
	return 0;
}