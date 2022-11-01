#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mp std::make_pair

typedef std::pair<int,int> pi;

const int N=100005;

int n,root,cnt,last[N],rt[N],sz,size[N],ans[N],rt2[N];
struct edge{int to,next;}e[N*2];
struct tree{int l,r,s;}t[N*100];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void ins(int &d,int l,int r,int x)
{
	int p=d;d=++sz;t[d]=t[p];t[d].s++;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

void ins(int &d,int p,int l,int r,int x)
{
	d=++sz;t[d]=t[p];t[d].s++;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,t[p].l,l,mid,x);
	else ins(t[d].r,t[p].r,mid+1,r,x);
}

int merge(int x,int y)
{
	if (!x||!y) return x^y;
	int d=++sz;
	t[d].s=t[x].s+t[y].s;
	t[d].l=merge(t[x].l,t[y].l);
	t[d].r=merge(t[x].r,t[y].r);
	return d;
}

void dfs(int x,int fa)
{
	size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		rt[x]=merge(rt[x],rt[e[i].to]);
	}
	ins(rt[x],1,n,size[x]);
}

void dfs2(int x,int fa)
{
	ins(rt2[x],rt2[fa],1,n,size[x]);
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs2(e[i].to,x);
}

int qrylef(int d,int p1,int p2,int l,int r,int x)
{
	if (!(t[d].s-t[p1].s-t[p2].s)) return 0;
	if (l==r) return l;
	int mid=(l+r)/2;
	if (x<=mid) return qrylef(t[d].l,t[p1].l,t[p2].l,l,mid,x);
	else
	{
		int y=qrylef(t[d].r,t[p1].r,t[p2].r,mid+1,r,x);
		return y?y:qrylef(t[d].l,t[p1].l,t[p2].l,l,mid,x);
	}
}

int qryrig(int d,int p1,int p2,int l,int r,int x)
{
	if (!(t[d].s-t[p1].s-t[p2].s)) return 0;
	if (l==r) return l;
	int mid=(l+r)/2;
	if (x>mid) return qryrig(t[d].r,t[p1].r,t[p2].r,mid+1,r,x);
	else
	{
		int y=qryrig(t[d].l,t[p1].l,t[p2].l,l,mid,x);
		return y?y:qryrig(t[d].r,t[p1].r,t[p2].r,mid+1,r,x);
	}
}

int calc(int mx,int mn,int p,int fa)
{
	if (!fa)
	{
		int x=qrylef(rt[p],0,0,1,n,(mx-mn+1)/2),y=qryrig(rt[p],0,0,1,n,(mx-mn+1)/2),ans=mx;
		if (x) ans=std::min(ans,std::max(mx-x,mn+x));
		if (y) ans=std::min(ans,std::max(mx-y,mn+y));
		return ans;
	}
	else
	{
		int x=qrylef(rt[root],rt[p],rt2[fa],1,n,(mx-mn+1)/2),y=qryrig(rt[root],rt[p],rt2[fa],1,n,(mx-mn+1)/2),ans=mx;
		if (x) ans=std::min(ans,std::max(mx-x,mn+x));
		if (y) ans=std::min(ans,std::max(mx-y,mn+y));
		x=qrylef(rt2[fa],0,0,1,n,std::min((mx-mn+1)/2+size[p],n));y=qryrig(rt2[fa],0,0,1,n,std::min((mx-mn+1)/2+size[p],n));
		if (x) ans=std::min(ans,std::max(mx-x+size[p],mn+x-size[p]));
		if (y) ans=std::min(ans,std::max(mx-y+size[p],mn+y-size[p]));
		return ans;
	}
}

void solve(int x,int fa)
{
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) solve(e[i].to,x);
	if (size[x]==1) {ans[x]=n-1;return;}
	int mx1=n-size[x],id1=fa,mx2=0,mn=fa?n-size[x]:n;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		if (size[e[i].to]>mx1) mx2=mx1,mx1=size[e[i].to],id1=e[i].to;
		else if (size[e[i].to]>mx2) mx2=size[e[i].to];
		if (size[e[i].to]<mn) mn=size[e[i].to];
	}
	if (mx1==mx2) {ans[x]=mx1;return;}
	ans[x]=std::max(mx2,calc(mx1,mn,id1==fa?x:id1,id1==fa?fa:0));
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (!x) root=y;
		else addedge(x,y);
	}
	dfs(root,0);
	dfs2(root,0);
	solve(root,0);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}