#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#define mp std::make_pair
#define pb push_back

typedef long long LL;
typedef std::pair<LL,int> pi;

const int N=200005;
const LL inf=(LL)1e16;

int n,m,q,cnt,last[N],id[N],tot,bel1[N],bel2[N],fa1[N],fa2[N];
bool vis[N],inq[N];
LL dis1[N],dis2[N],mn[N];
struct edge{int to,next,w;bool f;}e[N*2];
std::vector<int> e1[N],e2[N];
std::vector<LL> vec[N];
std::queue<int> que;
std::priority_queue<pi> pque;
std::multiset<LL> se;
std::multiset<LL>::iterator it;

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void dij(int s)
{
	for (int i=1;i<=n;i++) dis2[i]=inf,vis[i]=0;
	dis2[s]=0;
	pque.push(mp(0,s));
	while (!pque.empty())
	{
		int x=pque.top().second;pque.pop();
		while (vis[x]&&!pque.empty()) x=pque.top().second,pque.pop();
		if (vis[x]) break;
		vis[x]=1;
		for (int i=last[x];i;i=e[i].next)
			if (dis2[x]+e[i].w<dis2[e[i].to]) dis2[e[i].to]=dis2[x]+e[i].w,pque.push(mp(-dis2[e[i].to],e[i].to));
	}
}

void dfs(int x,int fa,int y,int op)
{
	if (op==1)
	{
		bel1[x]=y;
		for (int i=0;i<e1[x].size();i++)
			if (e1[x][i]!=fa) dfs(e1[x][i],x,y,op);
	}
	else
	{
		bel2[x]=y;
		for (int i=0;i<e2[x].size();i++)
			if (e2[x][i]!=fa) dfs(e2[x][i],x,y,op);
	}
}

void build1()
{
	memset(vis,0,sizeof(vis));
	que.push(1);vis[1]=1;
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=last[x];i;i=e[i].next)
			if (dis1[x]+e[i].w==dis1[e[i].to]&&!vis[e[i].to]) 
				vis[e[i].to]=1,fa1[e[i].to]=x,e1[x].pb(e[i].to),que.push(e[i].to),e[i].f=1;
	}
	for (int x=n;x!=1;x=fa1[x]) id[++tot]=x;
	id[++tot]=1;
	std::reverse(id+1,id+tot+1);
	for (int i=1,x=id[i];i<=tot;i++,x=id[i])
		for (int j=0;j<e1[x].size();j++)
			if (e1[x][j]!=id[i+1]) dfs(e1[x][j],x,i,1);
	for(int i=1;i<=tot;i++) bel1[id[i]]=bel2[id[i]]=i,inq[id[i]]=1;
}

void build2()
{
	memset(vis,0,sizeof(vis));
	for (int i=tot;i>=1;i--) vis[id[i]]=1,que.push(id[i]),fa2[id[i]]=id[i+1];
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=last[x];i;i=e[i].next)
			if (dis2[x]+e[i].w==dis2[e[i].to]&&!vis[e[i].to])
				vis[e[i].to]=1,fa2[e[i].to]=x,e2[x].pb(e[i].to),que.push(e[i].to),e[i].f=1;
	}
	for (int i=1,x=id[i];i<=tot;i++,x=id[i])
		for (int j=0;j<e2[x].size();j++)
			if (e2[x][j]!=id[i-1]) dfs(e2[x][j],x,i,2);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	dij(1);
	for (int i=1;i<=n;i++) dis1[i]=dis2[i];
	dij(n);
	build1();
	build2();
	for (int i=1;i<=m;i++)
	{
		int x=e[i*2-1].to,y=e[i*2].to,w=e[i*2].w;
		e[i*2-1].f=e[i*2].f=(e[i*2-1].f|e[i*2].f);
		if (e[i*2].f) continue;
		if (bel1[x]<bel2[y]) vec[bel1[x]].pb(dis1[x]+dis2[y]+w),vec[bel2[y]].pb(-(dis1[x]+dis2[y]+w));
		if (bel1[y]<bel2[x]) vec[bel1[y]].pb(dis1[y]+dis2[x]+w),vec[bel2[x]].pb(-(dis1[y]+dis2[x]+w));
	}
	for (int i=1;i<=n;i++) if (bel1[i]<bel2[i]) vec[bel1[i]].pb(dis1[i]+dis2[i]),vec[bel2[i]].pb(-(dis1[i]+dis2[i]));
	for (int i=1;i<tot;i++)
	{
		for (int j=0;j<vec[i].size();j++)
		{
			LL w=vec[i][j];
			if (w>0) se.insert(w);
			else it=se.lower_bound(-w),se.erase(it);
		}
		if (se.size()) mn[i]=*(se.begin());
		else mn[i]=inf;
	}
	while (q--)
	{
		int t,w;scanf("%d%d",&t,&w);
		int x=e[t*2-1].to,y=e[t*2].to;
		LL ans=std::min(dis1[x]+w+dis2[y],dis1[y]+w+dis2[x]);
		if (inq[x]&&inq[y]&&abs(bel1[x]-bel1[y])==1&&e[t*2].f) ans=std::min(ans,mn[std::min(bel1[x],bel1[y])]);
		else ans=std::min(ans,dis1[n]);
		printf("%lld\n",ans);
	}
	return 0;
}