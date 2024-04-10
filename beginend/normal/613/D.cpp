#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

const int N=100005;
const int inf=100000;

int n,last[N],ls[N],cnt,size[N],dep[N],fa[N],top[N],dfn[N],tim,vis[N],stack[N],a[N],tot,f[N][2];
struct edge{int to,next;}e[N*4];
std::vector<int> vec;

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
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void add1(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=ls[u];ls[u]=cnt;
}

void dfs1(int x)
{
	dfn[x]=++tim;dep[x]=dep[fa[x]]+1;size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		fa[e[i].to]=x;
		dfs1(e[i].to);
		size[x]+=size[e[i].to];
	}
}

void dfs2(int x,int chain)
{
	top[x]=chain;int k=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&size[e[i].to]>size[k]) k=e[i].to;
	if (!k) return;
	dfs2(k,chain);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k) dfs2(e[i].to,e[i].to);
}

int get_lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) std::swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

bool cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}

void build()
{
	std::sort(a+1,a+tot+1,cmp);
	int top=0;stack[++top]=1;vec.push_back(1);
	for (int i=1;i<=tot;i++)
	{
		int lca=get_lca(a[i],stack[top]);
		if (lca==stack[top])
		{
			if (stack[top]!=a[i]) stack[++top]=a[i],vec.push_back(a[i]);
			continue;
		}
		while (dep[stack[top-1]]>=dep[lca]) add1(stack[top-1],stack[top]),top--;
		if (dep[stack[top]]>dep[lca]) add1(lca,stack[top]),top--;
		if (lca!=stack[top]) stack[++top]=lca,vec.push_back(lca);
		stack[++top]=a[i];vec.push_back(a[i]);
	}
	while (top>1) add1(stack[top-1],stack[top]),top--;
}

void dp(int x)
{
	f[x][0]=f[x][1]=0;
	for (int i=ls[x];i;i=e[i].next) dp(e[i].to);
	if (vis[x]==tim)
	{
		f[x][0]=inf;
		for (int i=ls[x];i;i=e[i].next)
			f[x][1]+=std::min(f[e[i].to][0],f[e[i].to][1]+1);
	}
	else
	{
		int mn=0;
		for (int i=ls[x];i;i=e[i].next)
		{
			f[x][0]+=std::min(f[e[i].to][0],f[e[i].to][1]);
			f[x][1]+=f[e[i].to][0];
			mn=std::min(mn,f[e[i].to][1]-f[e[i].to][0]);
		}
		f[x][0]=std::min(f[x][0]+1,f[x][1]);f[x][1]+=mn;
	}
}

void solve()
{
	tot=read();tim++;int tmp=cnt;
	for (int i=1;i<=tot;i++) a[i]=read(),vis[a[i]]=tim;
	for (int i=1;i<=tot;i++) if (vis[fa[a[i]]]==tim) {puts("-1");return;}
	build();
	dp(1);
	for (int i=0;i<vec.size();i++) ls[vec[i]]=0;
	cnt=tmp;vec.clear();
	printf("%d\n",std::min(f[1][0],f[1][1]));
}

int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	dfs1(1);dfs2(1,1);
	int q=read();
	while (q--) solve();
	return 0;
}