#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
struct qq
{
	int x,y,last,id;
}e[N*2];int num,last[N];
void init (int x,int y,int id)
{
	e[++num].x=x;e[num].y=y;e[num].id=id;
	e[num].last=last[x];last[x]=num;
}
int n,m;
int d[N];
vector<int> ans;
bool vis[N];
void dfs (int x)
{
	//printf("%d\n",x);
	vis[x]=true;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		//printf("%d\n",u);
		int y=e[u].y;
		if (vis[y]) continue;
		dfs(y);
		if (d[y]!=0)
		{
			ans.push_back(e[u].id);
			if (d[x]!=-1) d[x]^=1; 
		}
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++) scanf("%d",&d[u]);
	int rt=-1;
	for (int u=1;u<=n;u++) if (d[u]==-1) rt=u;
	if (rt!=-1)
	{
		for (int u=1;u<=n;u++) if (d[u]==-1&&u!=rt) d[u]=0;
	}
	else rt=1;
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y,u);init(y,x,u);
	}
	
	dfs(rt);//printf("YES:%d %d\n",rt,d[rt]);
	if (d[rt]==-1||d[rt]==0)
	{
		int siz=ans.size();
		printf("%d\n",siz);
		for (int u=0;u<siz;u++) printf("%d\n",ans[u]);
	}
	else
	{
		printf("-1");
	}
	return 0;
}