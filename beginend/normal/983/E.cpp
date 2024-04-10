#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp(x,y) std::make_pair(x,y)

typedef std::pair<int,int> pi;

const int N=200005;

int n,m,q,cnt,last[N],dfn[N],mx[N],tim,up[N][20],fa[N][20],dep[N],ans[N],tmp[N],c[N];
std::vector<int> vec[N];
std::vector<pi> que[N];
struct edge{int to,next;}e[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void dfs(int x)
{
	dep[x]=dep[fa[x][0]]+1;dfn[x]=++tim;up[x][0]=x;
	for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=last[x];i;i=e[i].next) dfs(e[i].to);
	mx[x]=tim;
}

int get_lca(int x,int y)
{
	if (dep[x]<dep[y]) std::swap(x,y);
	for (int i=18;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

void build()
{
	for (int i=n;i>=1;i--)
	{
		up[i][0]=i;
		for (int j=last[i];j;j=e[j].next)
			up[i][0]=dep[up[e[j].to][0]]<dep[up[i][0]]?up[e[j].to][0]:up[i][0];
		for (int j=0;j<vec[i].size();j++)
		{
			int lca=get_lca(i,vec[i][j]);
			up[i][0]=dep[lca]<dep[up[i][0]]?lca:up[i][0];
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=18;j++)
			up[i][j]=up[up[i][j-1]][j-1];
}

void ins(int x,int y)
{
	while (x<=n) c[x]+=y,x+=x&(-x);
}

int query(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

void solve(int x)
{
	for (int i=0;i<que[x].size();i++)
		tmp[que[x][i].second]=query(mx[que[x][i].first])-query(dfn[que[x][i].first]-1);
	for (int i=0;i<vec[x].size();i++)
		ins(dfn[vec[x][i]],1);
	for (int i=last[x];i;i=e[i].next) solve(e[i].to);
	for (int i=0;i<que[x].size();i++)
		ans[que[x][i].second]+=(tmp[que[x][i].second]==query(mx[que[x][i].first])-query(dfn[que[x][i].first]-1));
}

int main()
{
	n=read();
	for (int i=2;i<=n;i++) fa[i][0]=read(),addedge(fa[i][0],i);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1);
	build();
	q=read();
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read(),lca=get_lca(x,y);
		for (int j=18;j>=0;j--)
		{
			if (dep[up[x][j]]>dep[lca]) x=up[x][j],ans[i]+=1<<j;
			if (dep[up[y][j]]>dep[lca]) y=up[y][j],ans[i]+=1<<j;
		}
		if (dep[up[x][0]]>dep[lca]||dep[up[y][0]]>dep[lca]) {ans[i]=-1;continue;}
		ans[i]++;
		if (x!=lca&&y!=lca) que[x].push_back(mp(y,i));
	}
	solve(1);
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}