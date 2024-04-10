#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=3005;
int n;
struct qq
{
	int x,y,last;
}e[N*2];int num,last[N];
void init (int x,int y)
{
	e[++num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
vector<int> vec;// 
int fa[N];
bool in[N];
int dep[N];
int bel[N];
void dfs1 (int x,int top)
{
	bel[x]=top;
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		if (in[y]||y==fa[x]) continue;
		fa[y]=x;dep[y]=dep[x]+1;dfs1(y,top);
	}
}
void dfs (int x,int from)
{
	//printf("YES:%d %d\n",x,fa[x]);
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		if (u==from||(u^1)==from) continue;
		int y=e[u].y;
		if (fa[y]==-1)	{fa[y]=x;dfs(y,u);}
		else if (in[x]==false)
		{
			int now=x;
			while (now!=y)
			{
				/*printf("%d %d\n",now,y);
				system("pause");*/
				in[now]=true;
				vec.push_back(now);
				now=fa[now];
			}
			in[y]=true;vec.push_back(y);
		}
	}
}
int dis[N][N];
int get_dis (int x,int y)
{
	if (dis[x][y]!=-1) return dis[x][y];
	if (dep[x]<dep[y]) swap(x,y);
	dis[x][y]=get_dis(fa[x],y)+1;
	return dis[x][y];
}
int main()
{
	memset(dis,-1,sizeof(dis));
	memset(in,false,sizeof(in));
	num=1;memset(last,-1,sizeof(last));
	memset(fa,-1,sizeof(fa));
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;y++;
		init(x,y);init(y,x);
	}
	fa[1]=0;dfs(1,0);
	int siz=vec.size();
	for (int u=0;u<siz;u++)
	{
		int xx=vec[u];
	//	printf("xx:%d\n",xx);
		fa[xx]=0;dep[xx]=0;dfs1(xx,u+1);
	}
	double ans=0;
	for (int u=1;u<=n;u++) dis[u][u]=1;
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=n;i++)
		{
			if (bel[u]==bel[i])
			{
				ans=ans+1.0/get_dis(u,i);
			}
			else
			{
				int t1=dep[u],t2=dep[i];//
				int d1=abs(bel[u]-bel[i]),d2=siz-d1;//
				d1++;
				d2++;// 
				ans=ans+1.0/(d1+t1+t2)+1.0/(d2+t1+t2)-1.0/(siz+t1+t2);
			}
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}