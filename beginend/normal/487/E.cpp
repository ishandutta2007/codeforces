#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=200005;
const int inf=1000000000;

int n,m,q,cnt,last[N],ls[N],w[N],dfn[N],tim,low[N],sta[N],tp,tot,size[N],dep[N],fa[N],pos[N],bel[N],top[N];
bool ins[N];
struct edge{int to,next;}e[N*5];
struct tree{int mn;}t[N*4];

struct Queue
{
	priority_queue<int> a,b;
	
	int top()
	{
		while (!b.empty()&&a.top()==b.top()) a.pop(),b.pop();
		return a.empty()?inf:-a.top();
	}
	
	void push(int x)
	{
		a.push(-x);
	}
	
	void del(int x)
	{
		b.push(-x);
	}
}que[N];

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

void tarjan(int x,int from)
{
	dfn[x]=low[x]=++tim;ins[x]=1;
	for (int i=ls[x];i;i=e[i].next)
	{
		if (i==(from^1)) continue;
		if (!dfn[e[i].to])
		{
			sta[++tp]=i;tarjan(e[i].to,i);
			low[x]=min(low[x],low[e[i].to]);
			if (low[e[i].to]>=dfn[x])
			{
				int y=0;tot++;
				while (y!=i) y=sta[tp--],addedge(e[y].to,tot+n);
				addedge(tot+n,x);
			}
		}
		else if (ins[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	}
	ins[x]=0;
}

void dfs1(int x)
{
	size[x]=1;dep[x]=dep[fa[x]]+1;
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
	pos[x]=++tim;bel[tim]=x;top[x]=chain;int k=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&size[e[i].to]>size[k]) k=e[i].to;
	if (!k) return;
	dfs2(k,chain);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k) dfs2(e[i].to,e[i].to);
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].mn=w[bel[l]];return;}
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
	t[d].mn=min(t[d*2].mn,t[d*2+1].mn);
}

void modify(int d,int l,int r,int x)
{
	if (l==r) {t[d].mn=w[bel[l]];return;}
	int mid=(l+r)/2;
	if (x<=mid) modify(d*2,l,mid,x);
	else modify(d*2+1,mid+1,r,x);
	t[d].mn=min(t[d*2].mn,t[d*2+1].mn);
}

int query(int d,int l,int r,int x,int y)
{
	if (l==x&&r==y) return t[d].mn;
	int mid=(l+r)/2;
	if (y<=mid) return query(d*2,l,mid,x,y);
	else if (x>mid) return query(d*2+1,mid+1,r,x,y);
	else return min(query(d*2,l,mid,x,mid),query(d*2+1,mid+1,r,mid+1,y));
}

int query(int x,int y)
{
	int ans=inf;
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=min(ans,query(1,1,n+tot,pos[top[x]],pos[x]));
		x=fa[top[x]];
	}
	if (dep[x]<dep[y]) swap(x,y);
	ans=min(ans,query(1,1,n+tot,pos[y],pos[x]));
	if (y>n) ans=min(ans,w[fa[y]]);
	return ans;
}

int main()
{
	n=read();m=read();q=read();cnt=1;
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		e[++cnt].to=y;e[cnt].next=ls[x];ls[x]=cnt;
		e[++cnt].to=x;e[cnt].next=ls[y];ls[y]=cnt;
	}
	tarjan(1,0);
	tim=0;dfs1(1);dfs2(1,1);
	for (int i=n+1;i<=n+tot;i++)
	{
		for (int j=last[i];j;j=e[j].next)
			if (e[j].to!=fa[i]) que[i].push(w[e[j].to]);
		w[i]=que[i].top();
	}
	build(1,1,n+tot);
	while (q--)
	{
		char ch[2];scanf("%s",ch);
		int x=read(),y=read();
		if (ch[0]=='C')
		{
			if (fa[x]) que[fa[x]].del(w[x]);
			w[x]=y;modify(1,1,n+tot,pos[x]);
			if (fa[x]) que[fa[x]].push(w[x]),w[fa[x]]=que[fa[x]].top(),modify(1,1,n+tot,pos[fa[x]]);
		}
		else printf("%d\n",query(x,y));
	}
	return 0;
}