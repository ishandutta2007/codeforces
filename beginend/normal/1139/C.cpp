#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int n,k,cnt,last[N],sum;
bool vis[N];
struct edge{int to,next,c;}e[N*2];

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

void addedge(int u,int v,int c)
{
	e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].c=c;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
	vis[x]=1;
	sum++;
	for (int i=last[x];i;i=e[i].next)
		if (!vis[e[i].to]&&!e[i].c) dfs(e[i].to);
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);
	}
	int ans=ksm(n,k);
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			sum=0;
			dfs(i);
			(ans+=MOD-ksm(sum,k))%=MOD;
		}
	printf("%d\n",ans);
	return 0;
}