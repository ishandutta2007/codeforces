#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=300005,MAXK=19;
const ll INF=0x3f3f3f3f3f3f3f3fll;

int n;
ll a[MAXN],cro[MAXN];
struct Edge
{
	int v;ll c[2];
	Edge *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
void addEdge(Edge *h[],int u,int v,ll x,ll y)
{
	Edge *p=&pool[++etot];
	p->v=v;p->c[0]=x;p->c[1]=y;p->next=h[u];h[u]=p;
}

bool vis[MAXN];
int frot[MAXN],size[MAXN];
void getroot(int u,int pa,int full,int &root)
{
	size[u]=1;
	frot[u]=0;
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa || vis[p->v])continue;
		getroot(p->v,u,full,root);
		size[u]+=size[p->v];
		frot[u]=max(frot[u],size[p->v]);
	}
	frot[u]=max(frot[u],full-size[u]);
	if(!root || frot[u]<frot[root])root=u;
}
ll dis[MAXN][2];
void dfs1(int u,int pa,int &mini)
{
	if(dis[u][0]+dis[u][1]+a[u]<=dis[mini][0]+dis[mini][1]+a[mini])mini=u;
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa || vis[p->v])continue;
		for(register int t=0;t<=1;++t)dis[p->v][t]=dis[u][t]+p->c[t];
		dfs1(p->v,u,mini);
	}
}
void dfs2(int u,int pa,int mini)
{
	cro[u]=min(cro[u],dis[u][0]+dis[u][1]+dis[mini][0]+dis[mini][1]+a[mini]);
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa || vis[p->v])continue;
		dfs2(p->v,u,mini);
	}
}
void work(int u)
{
	int mini=u;
	dis[u][0]=dis[u][1]=0;
	dfs1(u,-1,mini);
	dfs2(u,-1,mini);
}
void solve(int u)
{
	work(u);
	vis[u]=1;
	int root;
	for(Edge *p=h[u];p;p=p->next)
	{
		if(vis[p->v])continue;
		root=0;
		getroot(p->v,u,size[p->v],root);
		solve(root);
	}
}

int dep[MAXN],anc[MAXN][MAXK];
ll ever[MAXN][2][2][MAXK];
void dfs(int u,int pa)
{
	for(int i=1;i<MAXK;i++)
	{
		anc[u][i]=anc[anc[u][i-1]][i-1];
		for(int ti=0;ti<=1;++ti)
			for(int tj=0;tj<=1;++tj)
			{
				ever[u][ti][tj][i]=INF;
				for(int tk=0;tk<=1;++tk)
					ever[u][ti][tj][i]=min(ever[u][ti][tj][i],ever[u][ti][tk][i-1]+ever[anc[u][i-1]][tk][tj][i-1]);
			}
	}
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		dep[p->v]=dep[u]+1;
		anc[p->v][0]=u;
		for(int ti=0;ti<=1;++ti)
			for(int tj=0;tj<=1;++tj)
				if(ti==tj)ever[p->v][ti][tj][0]=min(p->c[ti],p->c[ti^1]+cro[u]+cro[p->v]);
				else ever[p->v][ti][tj][0]=min(p->c[ti]+cro[u],p->c[tj]+cro[p->v]);
		dfs(p->v,u);
	}
}
ll jump(int u,int tu,int v,int tv)
{
	if(dep[u]<dep[v])swap(u,v),swap(tu,tv);
	int t=dep[u]-dep[v];
	ll cur[2];cur[tu]=0;cur[tu^1]=cro[u];
	ll tmp[2];
	for(int i=0;i<MAXK;i++)
		if((1<<i)&t)
		{
			tmp[0]=tmp[1]=INF;
			for(int ti=0;ti<=1;++ti)
				for(int tj=0;tj<=1;++tj)
				{
					tmp[tj]=min(tmp[tj],cur[ti]+ever[u][ti][tj][i]);
				}
			cur[0]=tmp[0];cur[1]=tmp[1];
			u=anc[u][i];
		}
	if(u==v)return cur[tv];
	ll cvr[2];cvr[tv]=0;cvr[tv^1]=cro[v];
	for(int i=MAXK-1;i>=0;i--)
	{
		if(anc[u][i]==anc[v][i])continue;
		tmp[0]=tmp[1]=INF;
		for(int ti=0;ti<=1;++ti)
			for(int tj=0;tj<=1;++tj)
				tmp[tj]=min(tmp[tj],cur[ti]+ever[u][ti][tj][i]);
		cur[0]=tmp[0];cur[1]=tmp[1];
		u=anc[u][i];
		
		tmp[0]=tmp[1]=INF;
		for(int ti=0;ti<=1;++ti)
			for(int tj=0;tj<=1;++tj)
				tmp[tj]=min(tmp[tj],cvr[ti]+ever[v][ti][tj][i]);
		cvr[0]=tmp[0];cvr[1]=tmp[1];
		v=anc[v][i];
	}
	tmp[0]=tmp[1]=INF;
	for(int ti=0;ti<=1;++ti)
		for(int tj=0;tj<=1;++tj)
			tmp[tj]=min(tmp[tj],cur[ti]+ever[u][ti][tj][0]);
	cur[0]=tmp[0];cur[1]=tmp[1];
	
	tmp[0]=tmp[1]=INF;
	for(int ti=0;ti<=1;++ti)
		for(int tj=0;tj<=1;++tj)
			tmp[tj]=min(tmp[tj],cvr[ti]+ever[v][ti][tj][0]);
	cvr[0]=tmp[0];cvr[1]=tmp[1];
	return min(cur[0]+cvr[0],cur[1]+cvr[1]);
}

int main()
{
	int Q,u,v;ll x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%lld%lld",&u,&v,&x,&y);
		addEdge(h,u,v,x,y);addEdge(h,v,u,x,y);
	}
	memset(cro,0x3f,sizeof(cro));
	getroot(1,-1,n,u);
	solve(u);
	dfs(1,-1);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&u,&v);
		int tu=!(u&1),tv=!(v&1);
		u=((u-1)>>1)+1;v=((v-1)>>1)+1;
		printf("%lld\n",jump(u,tu,v,tv));
	}
	return 0;
}