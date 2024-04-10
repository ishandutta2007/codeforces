#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const int maxn = 600005;
const int inf = 1<<30;

int ans,tot; int CCC;
namespace Splay
{
	int p[maxn],c[maxn][2],val[maxn],rt,tag[maxn];
	int dir(int t) {return c[p[t]][1]==t;}
	void inc(int t,int v) {tag[t]+=v;val[t]+=v;}
	void downdate(int t) {if (int v=tag[t]) inc(c[t][0],v),inc(c[t][1],v),tag[t]=0;}
	void relax(int t) {if (p[t]) relax(p[t]);downdate(t);}
	void rotate(int t)
	{
		int f=p[t],d=dir(t),a=p[f],d0=dir(f);
		(p[t]=a)?c[a][d0]=t:rt=t;
		int y=c[t][d^1];(c[f][d]=y)?p[y]=f:0;
		c[t][d^1]=f;p[f]=t;
	}
	void splay(int t,int tar=0)
	{
		for (relax(t);p[t]!=tar;rotate(t))
		if (p[p[t]]!=tar&&dir(t)==dir(p[t]))
			rotate(p[t]);
	}
	int prf(int t)
	{
		splay(t);int w=c[t][0];
		while (c[w][1]) w=c[w][1];
		return w;
	}
	int suc(int t)
	{
		splay(t);int w=c[t][1];
		while (c[w][0]) w=c[w][0];
		return w;
	}
	void ins(int u,int w)
	{
		int v=suc(u);
		int x=++tot;val[x]=w;
		splay(u);splay(v,u);
		c[v][0]=x;p[x]=v;
	}
	void del(int x)
	{
		int u=prf(x),v=suc(x);
		splay(u);splay(v,u);
		c[v][0]=0;p[x]=0;
	}
	int ser(int x)
	{
		int t=rt,res=0;
		while (t)
		{
			downdate(t);
			if (val[t]<x) res=t,t=c[t][1];
			else t=c[t][0];
		}
		return res;
	}
}

using namespace Splay ;

void solve(int l,int r)
{
	int u=ser(l),ur=suc(u);
	int v=ser(r),vr=suc(v);
	if (u!=v) {
		int dpvr=min(val[vr],val[v]+1);
		if (val[vr]==inf) {
			++ans;ins(v,dpvr);
		}
		else val[vr]=dpvr;
		int dpur=min(val[ur],l);
		splay(u);splay(v,u);
		inc(c[v][0],1);
		del(v);ins(u,dpur);
	}
	else {
		int dpur=min(val[ur],l);
		if (val[ur]==inf) {
			++ans;ins(u,dpur);
		}
		else val[ur]=dpur;
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("states.in","r",stdin);
		freopen("states.out","w",stdout);
	#endif
	int n,l,r;scanf("%d",&n);
	int u=++tot;val[tot]=-inf;
	int v=++tot;val[tot]=inf;
	rt=v;p[u]=v;c[v][0]=u;
	for (int i=1;i<=n;i++)
		scanf("%d %d",&l,&r),solve(l,r);
	printf("%d",ans);
	return 0;
}