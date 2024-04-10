#include<bits/stdc++.h>

const int N=200005;

int n,m,cnt,last[N],f[N],g[N],u,v,mx,deg[N];
struct edge{int to,next;}e[N*2];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int dis,int fa)
{
	if (dis>mx) u=x,mx=dis;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,dis+1,x);
}

bool check(int x,int fa,int dep)
{
	if (dep>m-1) return 0;
	g[x]=dep;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		f[e[i].to]=x;
		if (!check(e[i].to,x,dep+1)) return 0;
		g[x]=std::max(g[x],g[e[i].to]);
	}
	return 1;
}

void work1()
{
	int s1=0,s2=0,s3=0,p1,p2;
	for (int i=1;i<=n;i++)
		if (deg[i]==1) s1++;
		else if (deg[i]==2) s2++,p2=p1,p1=i;
		else if (deg[i]==3) s3++;
		else return;
	if (s1!=(1<<(m-1))-1||s2!=2) return;
	int r=p2;
	for (int i=last[p2];i;i=e[i].next)
		if (deg[e[i].to]==1) {r=p1;break;}
	if (check(r,0,0)) {printf("1\n%d\n",p1==r?p2:p1);exit(0);}
}

int find(int x,int y,int fa,int d1,int d2)
{
	if (x==y) return n+1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		int p=find(e[i].to,y,x,d1+1,d2);
		if (!p) continue;
		if (p<=n) return p;
		else if (d1==d2) return x;
		else return n+1;
	}
	return 0;
}

void work2()
{
	if (mx&1)
	{
		int s1=0,s3=0;
		for (int i=1;i<=n;i++)
			if (deg[i]==1) s1++;
			else if (deg[i]==3) s3++;
			else return;
		if (s1!=(1<<(m-1))) return;
		int r1=find(u,v,0,0,m-1),r2=find(v,u,0,0,m-1);
		if (!check(r1,0,0)||!check(r2,0,0)) return;
		if (r1>r2) std::swap(r1,r2);
		printf("2\n%d %d\n",r1,r2);
	}
	else
	{
		int s1=0,s2=0,s3=0,s4=0,pos,r;
		for (int i=1;i<=n;i++)
			if (deg[i]==1) s1++;
			else if (deg[i]==2) s2++,r=i;
			else if (deg[i]==3) s3++;
			else if (deg[i]==4) s4++,pos=i;
			else return;
		if (s1!=(1<<(m-1))||s4!=1||s2!=1) return;
		if (!check(r,0,0)) return;
		int s5=0,s6=0;
		for (int i=last[pos];i;i=e[i].next)
			if (e[i].to!=f[pos])
			{
				if (g[e[i].to]==m-1) s5++;
				else if (g[e[i].to]==m-2) s6++;
			}
		if (s5!=1||s6!=2) return;
		printf("1\n%d\n",pos);
	}
	exit(0);
}

int main()
{
	scanf("%d",&m);
	n=(1<<m)-2;
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
		deg[x]++;deg[y]++;
	}
	mx=0;dfs(1,0,0);
	v=u;mx=0;dfs(v,0,0);
	if (n==2) {if (e[1].to>e[2].to) std::swap(e[1].to,e[2].to);printf("2\n%d %d\n",e[1].to,e[2].to);return 0;}
	work1();
	work2();
	puts("0");
	return 0;
}