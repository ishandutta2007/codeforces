#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long LL;
const int inf = 1<<28;
const int maxn = 600005;
struct edge{
	int u,v,lim,vol,next;
}edg[maxn];
int ehead[maxn],ecnt=1;
int x[maxn],y[maxn],deg[maxn];
int discx[maxn],cntx;
int discy[maxn],cnty;
int ver[maxn],hor[maxn];
int limx[maxn],limy[maxn];
int du[maxn],S,T,sS,sT,cnt,edgid[maxn];
int n,m,r,b;
void add(int u,int v,int lim,int vol) {
	edg[++ecnt]=(edge){u,v,lim,vol,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,0,0,ehead[v]};
	ehead[v]=ecnt;
}
namespace dinic {
	int lab[maxn];
	int que[maxn],head,tail;
	int dfs(int u,int t,int cur) {
		if (u==t) return cur;
		int res=0;
		for (int v,j=ehead[u];j&&res<cur;j=edg[j].next)
		if (edg[j].vol&&lab[v=edg[j].v]==lab[u]+1) {
			int tmp=dfs(v,t,min(cur-res,edg[j].vol));
			res+=tmp;edg[j].vol-=tmp;edg[j^1].vol+=tmp;
		}
		if (!res) lab[u]=-1;
		return res;
	}
	int bfs(int s,int t) {
		memset(lab,-1,(cnt+1)*sizeof(int));
		head=tail=0;que[head]=s;lab[s]=0;
		while (head<=tail) {
			int u=que[head++];
			for (int v,j=ehead[u];j;j=edg[j].next)
			if (edg[j].vol&&lab[v=edg[j].v]==-1) {
				lab[v]=lab[u]+1;que[++tail]=v;
			}
		}
		return lab[t]!=-1;
	}
	int dinic(int s,int t) {
		int res=0;
		while (bfs(s,t)) res+=dfs(s,t,inf);
		return res;
	}
	void lim_dinic() {
		for (int i=2;i<=ecnt;i+=2) {
			du[edg[i].u]-=edg[i].lim;
			du[edg[i].v]+=edg[i].lim;
			edg[i].vol-=edg[i].lim;
		}
		int oecnt=ecnt,sum=0;
		for (int i=1;i<=T;i++) {
			if (du[i]>0) add(sS,i,0,du[i]),sum+=du[i];
			if (du[i]<0) add(i,sT,0,-du[i]);
		}
	
		add(T,S,0,inf);
		if (sum!=dinic(sS,sT))
			{puts("-1");return ;}
		int ans=edg[ecnt].vol;
		for (int i=oecnt+1;i<=ecnt;i++)
			edg[i].vol=0;
		ans-=dinic(T,S);
		printf("%I64d\n",(LL)ans*max(r,b)+(LL)(n-ans)*min(r,b));
		for (int i=1;i<=n;i++)
		if (edg[edgid[i]^1].vol)
			printf("%c",r<b?'b':'r');
		else printf("%c",r<b?'r':'b');
	}
}
int findp(int *disc,int cnt,int num) {
	int lb=1,rb=cnt+1;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (disc[mid]<=num) lb=mid;
		else rb=mid;
	}
	return lb;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("captain.in","r",stdin);
		freopen("captain.out","w",stdout);
	#endif
	scanf("%d %d %d %d",&n,&m,&r,&b);cnt=0;
	for (int i=1;i<=n;i++)
		scanf("%d %d",&x[i],&y[i]),
		discx[i]=x[i],discy[i]=y[i];
	sort(discx+1,discx+n+1);cntx=1;
	sort(discy+1,discy+n+1);cnty=1;
	for (int i=2;i<=n;i++)
		if (discx[i]!=discx[cntx]) discx[++cntx]=discx[i];
	for (int i=2;i<=n;i++)
		if (discy[i]!=discy[cnty]) discy[++cnty]=discy[i];
	for (int i=1;i<=cntx;i++) ver[i]=++cnt;
	for (int i=1;i<=cnty;i++) hor[i]=++cnt;
	S=++cnt;T=++cnt;sS=++cnt;sT=++cnt;
	
	for (int i=1;i<=n;i++) {
		int _x=ver[findp(discx,cntx,x[i])];
		int _y=hor[findp(discy,cnty,y[i])];
	 	add(_x,_y,0,1);edgid[i]=ecnt-1;
	 	deg[_x]++;deg[_y]++;
//	 	cerr<<_x<<" "<<_y<<endl;
	}
	for (int i=1;i<=cntx;i++) limx[i]=inf;
	for (int i=1;i<=cnty;i++) limy[i]=inf;
	for (int t,l,d,i=1;i<=m;i++) {
		scanf("%d %d %d",&t,&l,&d);
		if (t==1) {
			int _x=findp(discx,cntx,l);
			if (_x<=0||_x>cntx||discx[_x]!=l) continue;
			limx[_x]=min(limx[_x],d);
		}
		else {
			int _y=findp(discy,cnty,l);
			if (_y<=0||_y>cnty||discy[_y]!=l) continue;
			limy[_y]=min(limy[_y],d);
		}
	}
	for (int i=1;i<=cntx;i++) {
		int L=max(0,(deg[ver[i]]-limx[i]+1)/2);
		int R=(deg[ver[i]]+limx[i])/2;
		if (L>R) {puts("-1");return 0;}
		add(S,ver[i],L,R);
//		cerr<<discx[i]<<" "<<L<<" "<<R<<endl;
	}
	for (int i=1;i<=cnty;i++) {
		int L=max(0,(deg[hor[i]]-limy[i]+1)/2);
		int R=(deg[hor[i]]+limy[i])/2;
		if (L>R) {puts("-1");return 0;}
		add(hor[i],T,L,R);
//		cerr<<discy[i]<<" "<<L<<" "<<R<<endl;
	}
	dinic::lim_dinic();
	return 0;
}