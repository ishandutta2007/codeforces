#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long LL;
#define pb push_back
const int maxn = 400005;
const int mod = 1e9+7;

LL QuickPow(LL p,LL k=mod-2)
{
	LL res=1ll;
	while (k) {
		if (k&1) (res*=p)%=mod;
		(p*=p)%=mod;k>>=1;
	}
	return res;
}

int ehead[maxn],ecnt;
struct edge {
	int u,v,next;
}edg[maxn];
void add(int u,int v)
{
	edg[++ecnt]=(edge){u,v,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,ehead[v]};
	ehead[v]=ecnt;
}

bool vis[maxn];
int cnt[maxn],siz[maxn],sum,rt;
bool is[maxn];int prm[maxn],tot;
int n,f[maxn],phi[maxn],a[maxn],b[maxn];
int s1[maxn],s2[maxn];
vector<int> ect[maxn];
LL ans=0; 

void predo(int n)
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!is[i]) prm[++tot]=i,phi[i]=i-1;
		for (int j=1;j<=tot;j++)
		{
			int num=prm[j]*i;
			if (num>n) break;
			if (i%prm[j]) {is[num]=1;phi[num]=phi[i]*(prm[j]-1);}
			else {is[num]=1;phi[num]=phi[i]*prm[j];break;}
		}
	}
}
void dfs1(int u,int fa)
{
	siz[u]=1;cnt[u]=0;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa&&!vis[v]) {
		dfs1(v,u);siz[u]+=siz[v];
		cnt[u]=max(cnt[u],siz[v]);
	}
}
void dfs2(int u,int fa)
{
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa&&!vis[v]) dfs2(v,u);
	cnt[u]=max(cnt[u],sum-siz[u]);
	if (cnt[u]<cnt[rt]) rt=u;
}

void gotta(int u,int fa,int d)
{
	int w2=b[u],w1=(LL)d*b[u]%mod;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa&&!vis[v])
		gotta(v,u,d+1);
	
	int o=a[u],sz=ect[o].size();
	for (int j=0;j<sz;j++)
	{
		int t=ect[o][j];
		f[t]=(f[t]+(LL)w1*s2[t]+(LL)w2*s1[t])%mod;
	}
}
void metta(int u,int fa,int d)
{
	int w2=b[u],w1=(LL)d*b[u]%mod;
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa&&!vis[v])
		metta(v,u,d+1);
	
	int o=a[u],sz=ect[o].size();
	for (int j=0;j<sz;j++)
	{
		int t=ect[o][j];
		s1[t]=(s1[t]+w1)%mod;
		s2[t]=(s2[t]+w2)%mod;
	}
}
void clear(int u,int fa)
{
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa&&!vis[v])
		clear(v,u);
	
	int o=a[u],sz=ect[o].size();
	for (int j=0;j<sz;j++)
	{
		int t=ect[o][j];
		s1[t]=s2[t]=0;
	}
}

void solve(int u)
{
	int o=a[u],sz=ect[o].size(),w2=b[u];
	for (int j=0;j<sz;j++)
	{
		int t=ect[o][j];
		s2[t]=(s2[t]+w2)%mod;
	}
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v])
		gotta(v,u,1),metta(v,u,1);
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v])
		clear(v,u);
	for (int j=0;j<sz;j++)
	{
		int t=ect[o][j];
		s2[t]=0;
	}
}
void conquar(int u)
{
	vis[u]=true;solve(u);
	for (int v,j=ehead[u];j;j=edg[j].next)
	if (!vis[v=edg[j].v]) {
		cnt[rt=0]=1<<30;
		dfs1(v,0);sum=siz[v];
		dfs2(v,0);conquar(rt);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("surprise.in","r",stdin);
		freopen("surprise.out","w",stdout);
	#endif
	scanf("%d",&n);predo(n);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		a[i]=x;b[i]=phi[x];
	}
	for (int u,v,i=1;i<n;i++)
		scanf("%d %d",&u,&v),add(u,v);
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j+=i)
		ect[j].pb(i);
	conquar(1);
	for (int i=n;i>=1;i--)
	{
		int sum=f[i];
		for (int j=i<<1;j<=n;j+=i)
			sum=(sum-f[j])%mod;
		ans=(ans+(LL)sum*i%mod*QuickPow(phi[i]))%mod;
		f[i]=sum;
	}
	ans=ans*2*QuickPow((LL)n*(n-1)%mod)%mod;
	printf("%lld",ans<0?ans+mod:ans);
	return 0;
}