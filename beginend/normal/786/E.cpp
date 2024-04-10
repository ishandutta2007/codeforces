#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define ls d<<1
#define rs d<<1|1

const int N=200005;
const int inf=1000000000;

int n,m,id[N];

struct Maxflow
{
	
	int s,t,cnt,last[N*6],cur[N*6],dis[N*6];
	struct edge{int to,c,next;}e[N*80];
	std::queue<int> que;
	bool vis[N*6];
	
	void init()
	{
		cnt=1;s=0;t=n+m+n*4+1;
	}
	
	void addedge(int u,int v,int c)
	{
		e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
		e[++cnt].to=u;e[cnt].c=0;e[cnt].next=last[v];last[v]=cnt;
	}
	
	bool bfs()
	{
		for (int i=s;i<=t;i++) dis[i]=0;
		while (!que.empty()) que.pop();
		dis[s]=1;que.push(s);
		while (!que.empty())
		{
			int x=que.front();que.pop();
			for (int i=last[x];i;i=e[i].next)
				if (e[i].c&&!dis[e[i].to])
				{
					dis[e[i].to]=dis[x]+1;
					if (e[i].to==t) return 1;
					que.push(e[i].to);
				}
		}
		return 0;
	}
	
	int dfs(int x,int maxf)
	{
		if (x==t||!maxf) return maxf;
		int ret=0;
		for (int &i=cur[x];i;i=e[i].next)
			if (e[i].c&&dis[e[i].to]==dis[x]+1)
			{
				int f=dfs(e[i].to,std::min(e[i].c,maxf-ret));
				e[i].c-=f;
				e[i^1].c+=f;
				ret+=f;
				if (maxf==ret) break;
			}
		return ret;
	}
	
	int dinic()
	{
		int ans=0;
		while (bfs())
		{
			for (int i=s;i<=t;i++) cur[i]=last[i];
			ans+=dfs(s,inf);
		}
		return ans;
	}
	
	void fill(int x)
	{
		vis[x]=1;
		for (int i=last[x];i;i=e[i].next)
			if (e[i].c&&!vis[e[i].to]) fill(e[i].to);
	}
	
	void pri()
	{
		fill(s);
		int tot=0;
		for (int i=1;i<=m;i++) if (!vis[n+i]) tot++;
		printf("%d ",tot);
		for (int i=1;i<=m;i++) if (!vis[n+i]) printf("%d ",i);
		puts("");
		tot=0;
		for (int i=1;i<=n;i++) if (vis[i]) tot++;
		printf("%d ",tot);
		for (int i=1;i<=n;i++) if (vis[i]) printf("%d ",id[i]);
	}
}flow;

struct Tree{
	
	int cnt,last[N],size[N],dep[N],fa[N],top[N],pos[N],tim,bel[N];
	struct edge{int to,next;}e[N*2];

	void addedge(int u,int v)
	{
		e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
		e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
	}

	void dfs1(int x)
	{
		size[x]=1;dep[x]=dep[fa[x]]+1;
		for (int i=last[x];i;i=e[i].next)
		{
			if (e[i].to==fa[x]) continue;
			fa[e[i].to]=x;
			id[e[i].to]=(i+1)/2;
			dfs1(e[i].to);
			size[x]+=size[e[i].to];
		}
	}

	void dfs2(int x,int chain)
	{
		pos[x]=++tim;top[x]=chain;bel[tim]=x;int k=0;
		for (int i=last[x];i;i=e[i].next)
			if (e[i].to!=fa[x]&&size[e[i].to]>size[k]) k=e[i].to;
		if (!k) return;
		dfs2(k,chain);
		for (int i=last[x];i;i=e[i].next)
			if (e[i].to!=fa[x]&&e[i].to!=k) dfs2(e[i].to,e[i].to);
	}

	void build(int d,int l,int r)
	{
		if (l==r) {flow.addedge(d+n+m,bel[l],inf);return;}
		int mid=(l+r)/2;
		build(ls,l,mid);flow.addedge(d+n+m,(ls)+n+m,inf);
		build(rs,mid+1,r);flow.addedge(d+n+m,(rs)+n+m,inf);
	}

	void ins(int d,int l,int r,int x,int y,int z)
	{
		if (x<=l&&r<=y) {flow.addedge(z,d+n+m,inf);return;}
		int mid=(l+r)/2;
		if (x<=mid) ins(ls,l,mid,x,y,z);
		if (y>mid) ins(rs,mid+1,r,x,y,z);
	}

	void link(int id,int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (dep[top[x]]<dep[top[y]]) std::swap(x,y);
			ins(1,1,n,pos[top[x]],pos[x],id);
			x=fa[top[x]];
		}
		if (dep[x]<dep[y]) std::swap(x,y);
		if (x!=y) ins(1,1,n,pos[y]+1,pos[x],id);
	}
}seg;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		seg.addedge(x,y);
	}
	flow.init();
	seg.dfs1(1);
	seg.dfs2(1,1);
	seg.build(1,1,n);
	for (int i=1;i<=n;i++) flow.addedge(i,flow.t,1);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		seg.link(i+n,x,y);
		flow.addedge(flow.s,i+n,1);
	}
	printf("%d\n",flow.dinic());
	flow.pri();
	return 0;
}