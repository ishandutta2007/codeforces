#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int n,m,cnt,last[N],t0[N],t1[N],now,sum,dep[N],a[N],ans,tot,po[N];
bool vis[N],flag;
LL bin[65],bas[65],val[N];
struct edge{int to,next;LL w;}e[N*4];

void addedge(int u,int v,LL w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

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

void ins(LL x)
{
	for (int i=60;i>=0;i--)
		if (x&bin[i])
		{
			if (!bas[i])
			{
				bas[i]=x;
				break;
			}
			else x^=bas[i];
		}
}

void dfs(int x)
{
	vis[x]=1;a[++tot]=x;
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to])
		{
			if (dep[e[i].to]<dep[x]) ins(val[x]^val[e[i].to]^e[i].w);
			continue;
		}
		val[e[i].to]=val[x]^e[i].w;
		dep[e[i].to]=dep[x]+1;
		dfs(e[i].to);
	}
}

void calc(int x)
{
	vis[x]=1;t0[x]=1;t1[x]=0;
	for (int i=last[x];i;i=e[i].next)
	{
		if (vis[e[i].to]) continue;
		calc(e[i].to);
		if (e[i].w&bin[now]) std::swap(t1[e[i].to],t0[e[i].to]);
		(sum+=(LL)t0[x]*t1[e[i].to]%MOD)%=MOD;
		(sum+=(LL)t1[x]*t0[e[i].to]%MOD)%=MOD;
		t0[x]+=t0[e[i].to];t1[x]+=t1[e[i].to];
	}
}

void solve(int rt)
{
	memset(bas,0,sizeof(bas));
	tot=0;dfs(rt);
	for (int i=0;i<=60;i++)
	{
		sum=0;now=i;
		for (int j=1;j<=tot;j++) vis[a[j]]=0;
		calc(rt);
		int s0=0,s1=0;
		for (int j=0;j<=60;j++)
			if (bas[j])
			{
				if (bas[j]&bin[i]) s1++;
				else s0++;
			}
		if (!s1) (ans+=(LL)bin[i]%MOD*sum%MOD*ksm(2,s0)%MOD)%=MOD;
		else (ans+=(LL)bin[i]%MOD*po[s0+s1-1]%MOD*((LL)tot*(tot-1)/2%MOD)%MOD)%=MOD;
	}
}

int main()
{
	bin[0]=1;
	for (int i=1;i<=60;i++) bin[i]=bin[i-1]*2;
	scanf("%d%d",&n,&m);
	po[0]=1;
	for (int i=1;i<=n;i++) po[i]=po[i-1]*2%MOD;
	for (int i=1;i<=m;i++)
	{
		int x,y;LL z;scanf("%d%d%lld",&x,&y,&z);
		addedge(x,y,z);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) solve(i);
	printf("%d",ans);
	return 0;
}