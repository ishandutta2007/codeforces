#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
const int maxn = 100005;
const LL inf = 1ll<<50;

int n,m,s,t,L;LL dis[maxn];
int ehead[maxn],ecnt=1;
int stk[maxn],top;bool vis[maxn];
struct edge{
	int u,v;LL w;int next;
}edg[maxn];
void add(int u,int v,LL w) {
	edg[++ecnt]=(edge){u,v,w,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,w,ehead[v]};
	ehead[v]=ecnt;
	if (!w) stk[++top]=ecnt;
}

struct qnode {
	int u;LL dis;
	bool operator<(const qnode &v) const {
		return v.dis<dis;
	}
};
priority_queue<qnode> q;
bool upd(LL &x,LL y) {
	return x>y?(x=y,1):0;
}
LL dijkstra() {
	memset(vis,false,sizeof vis);
	for (int i=1;i<=n;i++) dis[i]=inf;
	q.push((qnode){s,0});dis[s]=0;
	while (!q.empty()) {
		int u=q.top().u;q.pop();
		if (vis[u]) continue;
		vis[u]=true;
		for (int j=ehead[u];j;j=edg[j].next)
		if (upd(dis[edg[j].v],dis[edg[j].u]+edg[j].w))
			q.push((qnode){edg[j].v,dis[edg[j].v]});
	}
	return dis[t];
}
void putGraph() {
	puts("YES");
	for (int i=2;i<=ecnt;i+=2)
		printf("%d %d %lld\n",edg[i].u-1,edg[i].v-1,edg[i].w);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	#endif
	scanf("%d %d %d %d %d",&n,&m,&L,&s,&t);++s;++t;
	for (int u,v,w,i=1;i<=m;i++) {
		scanf("%d %d %d",&u,&v,&w);
		++u;++v;add(u,v,w);
	}
	for (int i=1;i<=top;i++)
		edg[stk[i]].w=edg[stk[i]^1].w=1;
	LL res1=dijkstra();
	if (res1>L) {puts("NO");return 0;}
	if (res1==L) {putGraph();return 0;}
	for (int i=1;i<=top;i++)
		edg[stk[i]].w=edg[stk[i]^1].w=inf;
	LL res2=dijkstra();
	if (res2<L) {puts("NO");return 0;}
	if (res2==L) {putGraph();return 0;}
	
	for (int i=1;i<=top;i++) {
		edg[stk[i]].w=edg[stk[i]^1].w=1;
		LL res=dijkstra();
		if (res>L) continue;
		edg[stk[i]].w+=L-res;
		edg[stk[i]^1].w+=L-res;
		putGraph();return 0;
	}
	puts("NO");
	return 0;
}