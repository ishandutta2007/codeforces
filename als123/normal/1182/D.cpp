#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=100005;
int n;
vector<int> vec[N]; 
int tmp,tmp1;
int fa[N],du[N];
void dfs (int x,int d)
{
	if (d>tmp1)	{tmp=x;tmp1=d;}
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (y==fa[x]) continue;
		fa[y]=x;dfs(y,d+1);
	}
}
bool tf;
int dep[N];
void dfs (int x,int ff,int d)
{
	if (tf==false) return ;
	if (dep[d]==-1) dep[d]=du[x];
	if (dep[d]!=du[x]) {tf=false;return ;}
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (y==ff) continue;
		dfs(y,x,d+1);
	}
}
void check (int x)
{
	memset(dep,-1,sizeof(dep));
	tf=true;dfs(x,0,0);
	if (tf)	{printf("%d\n",x);exit(0);}
}
int dis[N];
int rt;
void solve (int now)
{
	memset(dis,0,sizeof(dis));
	queue<int> q;
	q.push(now);dis[now]=1;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		int siz=vec[x].size();
		for (int u=0;u<siz;u++)
		{
			int y=vec[x][u];
			if (du[y]>2) continue;
			if (dis[y]!=0) continue;
			dis[y]=dis[x]+1;q.push(y);
		}
	}
	for (int u=1;u<=n;u++) if (dis[u]!=0&&dis[u]!=dis[rt]&&du[u]==1)	{check(u);return ;}
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
		du[x]++;du[y]++;
	}
	tmp1=0;fa[1]=0;dfs(1,1);
	check(tmp);
	rt=tmp;tmp1=0;fa[rt]=0;dfs(rt,1);
	check(tmp);
	int cnt=1;
	int now=tmp;
	while (now!=rt) {cnt++;now=fa[now];}
	/*if (cnt&1)
	{*/
		cnt>>=1;now=tmp;
		while (cnt>0)	{now=fa[now];cnt--;}
		check(now);
		solve(now);
	//}
	printf("-1\n");
	return 0;
}