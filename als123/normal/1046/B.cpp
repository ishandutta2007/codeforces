#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100005*4;
const int M=500005;
int n,m,q;
struct qq
{
	int x,y,last;
}e[M*2];int num,last[N];
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int dfn[N],low[N],sta[N],top,id;
vector<int> vec[N];
int cnt;
void dfs (int x)
{
    low[x]=dfn[x]=++id;sta[++top]=x;
    //printf("YES:%d\n",x);
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
                    vec[cnt].push_back(i);
                   // printf("YES:%d %d\n",cnt,i);
                    vec[i].push_back(cnt);
                }while (i!=y);
                //printf("YES:%d %d\n",cnt,x);
                vec[cnt].push_back(x);
                vec[x].push_back(cnt);
            }
        }
        else low[x]=min(low[x],dfn[y]);
    }
}
int dep[N],dep1[N];//   
int fa[N][21];
void dfs1 (int x)
{
	for (int u=1;u<=20;u++)	fa[x][u]=fa[fa[x][u-1]][u-1];
	if (x>n) dep1[x]++;
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (y==fa[x][0]) continue;
		dep1[y]=dep1[x];dep[y]=dep[x]+1;
		fa[y][0]=x;
		dfs1(y);
	}
}
int get (int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int u=20;u>=0;u--)
		if (dep[fa[x][u]]>=dep[y])
			x=fa[x][u];
	if (x==y) return x;
	for (int u=20;u>=0;u--)
		if (fa[x][u]!=fa[y][u])
			{x=fa[x][u];y=fa[y][u];}
	return fa[x][0];
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	scanf("%d%d%d",&n,&m,&q);cnt=n;
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		init(x,y);init(y,x);
	}
	memset(dfn,-1,sizeof(dfn));
	dfs(1);
	dep[0]=-1;
	dfs1(1);
	while (q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int lca=get(x,y);
		int a=dep[x]+dep[y]-2*dep[lca];
		int b=dep1[x]+dep1[y]-dep1[lca]-dep1[fa[lca][0]];
		//printf("%d %d %d\n",lca,a,b);
		printf("%d\n",a-b);
	}
	return 0;
}