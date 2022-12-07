#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
int n,m;
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int dfn[N],low[N],id;
int sta[N],top;
int h[N],cnt;// 
int belong[N];
void dfs (int x)
{
	
	low[x]=dfn[x]=++id;
	sta[++top]=x;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (dfn[y]==-1)
		{
			dfs(y);
			low[x]=min(low[x],low[y]);
			if (low[y]>=dfn[x])
			{
				cnt++;int i;
				do
				{
					i=sta[top--];
					h[cnt]++;
					belong[i]=cnt;
				}while (i!=y);
				h[cnt]++;
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
vector<int> s[N];
int ans[N];
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	memset(dfn,-1,sizeof(dfn));id=0;top=0;cnt=0;
	for (int u=1;u<=n;u++)
		if (dfn[u]==-1)
		{
			dfs(u);
			//printf("%d\n",u);
			cnt++;
			while (top>0)	{h[cnt]++;top--;}
		}
	for (int u=1;u<=m;u++)
	{
		int xx=u*2-1;
		int x=dfn[e[xx].x]>dfn[e[xx].y]?e[xx].x:e[xx].y;
		s[belong[x]].push_back(u);
	}
	for (int u=1;u<=cnt;u++)
		if (s[u].size()==h[u])//
		{
			for (int i=0;i<s[u].size();i++)
				ans[++ans[0]]=s[u][i];
		}
	sort(ans+1,ans+1+ans[0]);
	printf("%d\n",ans[0]);
	for (int u=1;u<=ans[0];u++)
		printf("%d ",ans[u]);
	printf("\n");
	return 0;
}