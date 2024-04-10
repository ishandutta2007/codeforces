#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
const int maxn = 2000005;
const int inf = 1<<30;

int ehead[maxn],ecnt;
struct edge {
	int u,v,vol,next;
}edg[maxn];
void add(int u,int v,int vol)
{
	edg[++ecnt]=(edge){u,v,vol,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,0,ehead[v]};
	ehead[v]=ecnt;
}

int prm[maxn],tot;bool is[maxn];
void predo(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!is[i]) prm[++tot]=i;
		for (int j=1;j<=tot;j++)
		{
			int num=prm[j]*i;
			if (num>n) break;
			is[num]=1;
			if (i%prm[j]==0) break;
		}
	}
}

int cnt,S,T;
int n,K,p[maxn],c[maxn],l[maxn],p1[maxn];
int _od[maxn],_ev[maxn];

namespace Dinic {
	int que[maxn],head,tail,lab[maxn];
	bool bfs()
	{
		memset(lab,-1,sizeof(int)*(cnt+1));
		lab[S]=0;que[head=tail=0]=S;
		while (head<=tail) {
			int u=que[head++];
			for (int v,j=ehead[u];j;j=edg[j].next)
			if (edg[j].vol&&lab[v=edg[j].v]==-1)
				{lab[v]=lab[u]+1;que[++tail]=v;}
		}
		return lab[T]!=-1;
	}
	int dfs(int u,int cur)
	{
		int res=0;
		if (u==T) return cur;
		for (int v,j=ehead[u];j&&res<cur;j=edg[j].next)
		if (edg[j].vol&&lab[v=edg[j].v]==lab[u]+1)
		{
			int tmp=dfs(v,min(cur-res,edg[j].vol));
			edg[j].vol-=tmp;edg[j^1].vol+=tmp;res+=tmp;
		}
		if (!res) lab[u]=-1;
		return res;
	}
	int dinic()
	{
		int res=0;
		while (bfs()) res+=dfs(S,inf);
		return res;
	}
}
using namespace Dinic ;

int Without1()
{
	int sum=0;_od[0]=_ev[0]=0;ecnt=1;
	memset(ehead,0,sizeof(int)*(cnt+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		if (c[j]!=1&&l[j]==i) {
			if (c[j]&1) {
				add(S,j,p[j]);sum+=p[j];
				_od[++_od[0]]=j;
				for (int k=1;k<=_ev[0];k++)
				if (!is[c[j]+c[_ev[k]]])
					add(j,_ev[k],inf);
			}
			else {
				add(j,T,p[j]);sum+=p[j];
				_ev[++_ev[0]]=j;
				for (int k=1;k<=_od[0];k++)
				if (!is[c[j]+c[_od[k]]])
					add(_od[k],j,inf);
			}
		}
		sum-=dinic();
		if (sum>=K) return i;
	}
	return inf;
}
int Within1()
{
	
	int sum=0;_od[0]=_ev[0]=0;ecnt=1;
	memset(ehead,0,sizeof(int)*(cnt+1));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		if (c[j]!=1&&l[j]==i&&is[c[j]+1]) {
			if (c[j]&1) {
				add(S,j,p[j]);sum+=p[j];
				_od[++_od[0]]=j;
				for (int k=1;k<=_ev[0];k++)
				if (!is[c[j]+c[_ev[k]]])
					add(j,_ev[k],inf);
			}
			else {
				add(j,T,p[j]);sum+=p[j];
				_ev[++_ev[0]]=j;
				for (int k=0;k<=_od[0];k++)
				if (!is[c[j]+c[_od[k]]])
					add(_od[k],j,inf);
			}
		}
		sum-=dinic();
		if (sum+p1[i]>=K) return i;
	}
	return inf;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
	#endif
	scanf("%d %d",&n,&K);
	cnt=n;S=++cnt;T=++cnt;
	for (int i=1;i<=n;i++) {
		scanf("%d %d %d",&p[i],&c[i],&l[i]);
		if (c[i]==1) p1[l[i]]=max(p1[l[i]],p[i]);
	}
	for (int i=1;i<=n;i++) p1[i]=max(p1[i-1],p1[i]);
	predo(200000);int ans=min(Within1(),Without1());
	printf("%d",ans!=inf?ans:-1);
	return 0;
}