#include<bits/stdc++.h>

typedef long long LL;

const int N=500005;

int n,k,cnt,last[N];
LL a[N],f[N][2];
struct edge{int to,next,w;}e[N*2];

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

bool cmp(LL x,LL y)
{
	return x>y;
}

void dfs(int x,int fa)
{
	f[x][0]=f[x][1]=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
	int tot=0;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa) f[x][0]+=f[e[i].to][0],a[++tot]=f[e[i].to][1]+(LL)e[i].w-f[e[i].to][0];
	std::sort(a+1,a+tot+1,cmp);
	f[x][1]=f[x][0];
	for (int i=1;i<=std::min(k,tot);i++)
	{
		if (a[i]<0) break;
		f[x][0]+=a[i];
	}
	for (int i=1;i<=std::min(k-1,tot);i++)
	{
		if (a[i]<0) break;
		f[x][1]+=a[i];
	}
}

void clear()
{
	for (int i=1;i<=n;i++) last[i]=0;
	cnt=0;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		clear();
		for (int i=1;i<n;i++)
		{
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
		}
		dfs(1,0);
		printf("%lld\n",std::max(f[1][0],f[1][1]));
	}
	return 0;
}