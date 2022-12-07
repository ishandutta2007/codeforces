#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int MAX=(1<<30);
const int N=200005;
struct qq
{
	int x,y,last;
}e[N];
int num,last[N];
int n,m,q;
void init (int x,int y)
{
	num++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
int Fa[N][21];
int dep[N];
int L[N],R[N],cnt;
void dfs (int x)
{
	L[x]=++cnt;
	for (int u=1;u<=20;u++)	Fa[x][u]=Fa[Fa[x][u-1]][u-1];
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		Fa[y][0]=x;
		dep[y]=dep[x]+1;dfs(y);
	}
	R[x]=cnt;
}
int get_lca (int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int u=20;u>=0;u--)
		if (Fa[x][u]!=0&&dep[Fa[x][u]]>=dep[y])
			x=Fa[x][u];
	if (x==y) return x;
	for (int u=20;u>=0;u--)
		if (Fa[x][u]!=Fa[y][u])
			{x=Fa[x][u];y=Fa[y][u];}
	return Fa[x][0];
}
struct qt
{
	int id;// 
	int x,y;// 
	qt () {};
	qt (int _id,int _x,int _y)	{id=_id;x=_x;y=_y;}
};
vector<qt> s[N];
int low[N];
int fa[N][21];
int pow[21];
void update (int x,int y)
{
	//printf("%d %d %d %d\n",x,y,dep[low[x]],dep[y]);
	if (dep[low[x]]>dep[y]) low[x]=y;
}
void dfs1 (int x)
{
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		dfs1(y);
		update(x,low[y]);
	}
}
void dfs2 (int x)
{
	fa[x][0]=low[x];
	for (int u=1;u<=20;u++)	fa[x][u]=fa[fa[x][u-1]][u-1];
	for (int u=last[x];u!=-1;u=e[u].last)
	{
		int y=e[u].y;
		dfs2(y);
	}
}
int ans[N];
struct qy
{
	int x,y;
}t[N];
void solve (int x,int y,int id)
{
	int o=get_lca(x,y);
	if (x==y) return ;
	for (int u=20;u>=0;u--)
	{
		if (u!=0&&fa[x][u]==fa[x][u-1]) continue;
		int xx=fa[x][u];
		if (dep[xx]>dep[o]) 
		{
			ans[id]=ans[id]+pow[u];
			x=xx;
		}
	}
	for (int u=20;u>=0;u--)
	{
		if (u!=0&&fa[y][u]==fa[y][u-1]) continue;
		int xx=fa[y][u];
		if (dep[xx]>dep[o]) 
		{
			ans[id]=ans[id]+pow[u];
			y=xx;
		}
	}
	if (dep[low[x]]>dep[o]||dep[low[y]]>dep[o])
	{
		ans[id]=-1;
		return ;
	}
	if (x==o||y==o)//lca 
	{
		ans[id]++;
		return ;
	}
	if (L[x]>L[y]) swap(x,y);
	//printf("%d %d %d\n",o,x,y);
	s[o].push_back(qt(id,x,y));
}
int f[N];
int lb (int x)	{return x&(-x);}
void change (int x,int y)
{
	while (x<=n)
	{
		f[x]+=y;
		x=x+lb(x);
	}
}
int find (int x)
{
	int lalal=0;
	while (x>=1)
	{
		lalal=lalal+f[x];
		x=x-lb(x);
	}
	return lalal;
}
qt o[N*4];
int h[N];
bool cmp (qt x,qt y)	
{
	if (x.x==y.x) return (x.id==0);
	else return x.x<y.x;
}
int main()
{
	pow[0]=1;	for (int u=1;u<=20;u++)	pow[u]=(pow[u-1]<<1);
	num=0;memset(last,-1,sizeof(last));
	scanf("%d",&n);
	for (int u=2;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		init(x,u);
	}
	dep[0]=MAX;dfs(1);
	scanf("%d",&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int xx=get_lca(x,y);
		//printf("%d\n",xx);
		if (L[x]>L[y]) swap(x,y);//x 
		s[xx].push_back(qt(-1,L[x],L[y]));
		update(x,xx);update(y,xx);
	}
	dfs1(1);dfs2(1);
	/*for (int u=1;u<=n;u++)	printf("%d ",low[u]);
	printf("\n");*/
	scanf("%d",&q);
	for (int u=1;u<=q;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		solve(x,y,u);
	}
	for (int u=1;u<=n;u++)
	{
		int t=s[u].size();cnt=0;
		for (int i=0;i<t;i++)
		{
		//	printf("%d %d %d\n",s[u][i].x,s[u][i].y,s[u][i].id);
			if (s[u][i].id==-1)
			{
				o[++cnt]=qt(0,s[u][i].x,s[u][i].y);
			}
			else
			{
				int x=s[u][i].x,y=s[u][i].y,id=s[u][i].id;
				o[++cnt]=qt(id,R[x],R[y]);
				o[++cnt]=qt(-id,L[x]-1,R[y]);
				o[++cnt]=qt(-id,R[x],L[y]-1);
				o[++cnt]=qt(id,L[x]-1,L[y]-1);
			}
		}
		sort(o+1,o+1+cnt,cmp);
	//	for (int i=1;i<=cnt;i++) printf("YES:%d %d %d\n",o[i].id,o[i].x,o[i].y);
		for (int i=1;i<=cnt;i++)
		{
			if (o[i].id==0)	change(o[i].y,1);
			else
			{
				if (o[i].id>0)
				{
				//	printf("OZY:%d %d\n",find(o[i].y));
					h[o[i].id]=h[o[i].id]+find(o[i].y);
				}
				else
				{
				//	printf("OZY:%d %d\n",find(o[i].y));
					h[-o[i].id]=h[-o[i].id]-find(o[i].y);
				}
			}
		}
		for (int i=0;i<t;i++)
		{
			int id=s[u][i].id;
			if (id==-1)	change(s[u][i].y,-1);
			else
			{
				if (h[id]>0) ans[id]++;
				else ans[id]=ans[id]+2;
			}
		}
	}
	for (int u=1;u<=q;u++)
		printf("%d\n",ans[u]);
	return 0;
}