#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=4005;
const int M=80;
const int MOD=998244353;

int m,jc[M],ny[M];

struct Tree
{
	int n,cnt,last[N],f[M][N],g[M][N],size[N],ans[M],w[N],tot,a[N],sum,root;
	bool vis[N];
	struct edge{int to,next;}e[N*2];
	
	void addedge(int u,int v)
	{
		e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
		e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
	}
	
	void get_root(int x,int fa)
	{
		size[x]=1;w[x]=0;
		for (int i=last[x];i;i=e[i].next)
		{
			if (e[i].to==fa||vis[e[i].to]) continue;
			get_root(e[i].to,x);
			size[x]+=size[e[i].to];
			w[x]=std::max(w[x],size[e[i].to]);
		}
		w[x]=std::max(w[x],sum-size[x]);
		if (!root||w[x]<w[root]) root=x;
	}
	
	void get(int x,int fa)
	{
		a[++tot]=x;size[x]=1;
		for (int i=last[x];i;i=e[i].next)
			if (e[i].to!=fa&&!vis[e[i].to]) get(e[i].to,x),size[x]+=size[e[i].to];
	}
	
	void calc(int x)
	{
		tot=0;get(x,0);
		for (int i=1;i<=tot;i++) f[0][a[i]]=0;
		f[0][x]=g[0][x]=1;
		for (int i=1;i<=m;i++)
			for (int j=1;j<=tot;j++)
			{
				int y=a[j];
				f[i][y]=g[i][y]=0;
				for (int k=last[y];k;k=e[k].next)
				{
					if (vis[e[k].to]) continue;
					(g[i][y]+=g[i-1][e[k].to])%=MOD;
					if (y!=x) (f[i][y]+=f[i-1][e[k].to])%=MOD;
				}
			}
		for (int i=1;i<=tot;i++)
		{
			int y=a[i];
			if (y==x)
			{
				for (int j=0;j<=m;j++) (ans[j]+=g[j][x])%=MOD;
				continue;
			}
			for (int j=0;j<=m;j++)
				for (int k=0;j+k<=m;k++)
					(ans[j+k]+=(LL)f[j][y]*g[k][y]%MOD)%=MOD;
		}
		vis[x]=1;
		for (int i=last[x];i;i=e[i].next)
		{
			if (vis[e[i].to]) continue;
			root=0;sum=size[e[i].to];
			get_root(e[i].to,x);
			calc(root);
		}
	}
	
	void solve()
	{
		sum=n;root=0;
		get_root(1,0);
		calc(root);
	}
}t1,t2;

int C(int n,int m)
{
	return (LL)jc[n]*ny[m]%MOD*ny[n-m]%MOD;
}

int main()
{
	scanf("%d%d%d",&t1.n,&t2.n,&m);
	jc[0]=jc[1]=ny[0]=ny[1]=1;
	for (int i=2;i<=m;i++) jc[i]=(LL)jc[i-1]*i%MOD,ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=m;i++) ny[i]=(LL)ny[i-1]*ny[i]%MOD;
	for (int i=1;i<t1.n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		t1.addedge(x,y);
	}
	for (int i=1;i<t2.n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		t2.addedge(x,y);
	}
	t1.solve();t2.solve();
	int s=0;
	for (int i=0;i<=m;i++)
		(s+=(LL)t1.ans[i]*t2.ans[m-i]%MOD*C(m,i)%MOD)%=MOD;
	printf("%d",s);
	return 0;
}