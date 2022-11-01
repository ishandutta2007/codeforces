#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;
const int MOD=998244353;

int n,cnt,last[N],jc[N],deg[N],f[N];
struct edge{int to,next;}e[N*2];

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x,int fa)
{
	f[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa) continue;
		dfs(e[i].to,x);
		deg[x]++;
		f[x]=(LL)f[x]*f[e[i].to]%MOD;
	}
	f[x]=(LL)f[x]*jc[deg[x]+1]%MOD;
}

int main()
{
	scanf("%d",&n);
	jc[0]=1;
	for (int i=1;i<=n;i++) jc[i]=(LL)jc[i-1]*i%MOD;
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0);
	printf("%d\n",(LL)f[1]*n%MOD*ksm(deg[1]+1,MOD-2)%MOD);
	return 0;
}