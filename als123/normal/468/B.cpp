#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
int n,A,B;
map<int,int> mp;
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
int dfn[N],low[N],id;
int sta[N],top;
int belong[N],cnt;
bool in[N];
int a[N];
vector<int> vec[N];
vector<int> vecc[N];
int d[N];
bool f[N];
bool g[N];// 
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
void dfs (int x)
{
	dfn[x]=low[x]=++id;
	sta[++top]=x;in[x]=true;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (dfn[y]==-1)	{dfs(y);low[x]=min(low[x],low[y]);}
		else if (in[y]) low[x]=min(low[x],dfn[y]);
	}
	//printf("now:%d %d %d\n",x,low[x],dfn[x]);
	if (low[x]==dfn[x])
	{
		cnt++;
		int i;
		do
		{
			i=sta[top--];	
			//printf("YES:%d\n",i);
			in[i]=false;
			belong[i]=cnt;
			vecc[cnt].push_back(i);
		}while (i!=x);
	}
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d%d",&n,&A,&B);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&a[u]);
		mp[a[u]]=u;
	}
	for (int u=1;u<=n;u++)
	{
		int xx;
		xx=A-a[u];
		if (mp[xx]==0)// 
			init(u,u+n);
		else
		{
			init(u,mp[xx]);//xa-x 
			init(u+n,mp[xx]+n);// 
		}
		xx=B-a[u];
		if (mp[xx]==0)// 
			init(u+n,u);
		else
		{
			init(u,mp[xx]);//xa-x 
			init(u+n,mp[xx]+n);// 
		}
	}
	/*for (int u=1;u<=num;u++)
		printf("%d %d\n",e[u].x,e[u].y);*/
	memset(dfn,-1,sizeof(dfn));
	for (int u=1;u<=2*n;u++)
		if (dfn[u]==-1)
			dfs(u);
	for (int u=1;u<=n;u++)
		if (belong[u]==belong[u+n])
		{
			printf("NO\n");
			return 0;
		}
/*	for (int u=1;u<=2*n;u++) printf("%d ",belong[u]);
	printf("\n");*/
	for (int u=1;u<=num;u++)
	{
		if (belong[e[u].x]==belong[e[u].y]) continue;
		vec[belong[e[u].y]].push_back(belong[e[u].x]);
		d[belong[e[u].x]]++;
	}
	queue<int> q;
	for (int u=1;u<=2*n;u++)
		if (d[u]==0)
			q.push(u);
	memset(f,false,sizeof(f));
	memset(g,true,sizeof(g));
	while (!q.empty())
	{
		int x=q.front();q.pop();
		//printf("%d\n",x);
		int siz;
		if (g[x]==true)
		{
			siz=vecc[x].size();
			for (int u=0;u<siz;u++)
			{
				int xx=vecc[x][u];
				f[xx]=true;
				//printf("lalal:%d\n",xx);
				if (xx<=n) g[belong[xx+n]]=false;
				else g[belong[xx-n]]=false;
			}
		}
		siz=vec[x].size();
		for (int u=0;u<siz;u++)
		{
			int xx=vec[x][u];
			d[xx]--;
			if (d[xx]==0) q.push(xx);
		}
	}
	printf("YES\n");
	for (int u=1;u<=n;u++) printf("%d ",!f[u]);
	return 0;
}