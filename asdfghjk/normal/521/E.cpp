#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,i,j,k,head[N],adj[N*2],nxt[N*2],mn[N],Mn[N],pt[N],Pt[N],dep[N],fa[N],ans[N],cnt;
bool v[N];
void Print()
{
	printf("%d",cnt);
	for(int i=1;i<=cnt;++i)
		printf(" %d",ans[i]);
	puts("");
}
void work(int x,int d)
{
	if(dep[x]!=d)
		work(fa[x],d);
	ans[++cnt]=x;
}
bool dfs(int x,int dad)
{
	//printf("%d\n",x);
	v[x]=true;
	mn[x]=Mn[x]=dep[x],pt[x]=Pt[x]=x;
	for(int y=head[x];y;y=nxt[y])
		if(!v[adj[y]])
		{
			dep[adj[y]]=dep[x]+1;
			fa[adj[y]]=x;
			if(dfs(adj[y],x))
				return true;
			if(mn[adj[y]]<mn[x])
			{
				Mn[x]=mn[x];
				Pt[x]=pt[x];
				mn[x]=mn[adj[y]];
				pt[x]=pt[adj[y]];
			}
			else if(mn[adj[y]]<Mn[x])
				Mn[x]=mn[adj[y]],Pt[x]=pt[adj[y]];
		}
		else if(adj[y]!=dad)
		{
			if(dep[adj[y]]<mn[x])
			{
				Mn[x]=mn[x];
				Pt[x]=pt[x];
				mn[x]=dep[adj[y]];
				pt[x]=x;
			}
			else if(dep[adj[y]]<Mn[x])
			{
				Mn[x]=dep[adj[y]];
				Pt[x]=x;
			}
		}
	if(Mn[x]<dep[x])
	{
		puts("YES");
		cnt=0;
		for(i=x;dep[i]>Mn[x];i=fa[i])
			ans[++cnt]=i;
		ans[++cnt]=i;
		Print();
		cnt=0;
		work(Pt[x],dep[x]);
		ans[++cnt]=i;
		Print();
		cnt=0;
		work(pt[x],dep[x]);
		work(i,mn[x]);
		Print();
		return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=n;++i)
		if(!v[i])
		{
			if(dfs(i,-1))
				return 0;
		}
	printf("NO");
	return 0;
}