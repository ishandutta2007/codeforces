#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=1000005;

int n,f[N*2],w[N*2],a[N],b[N],tot,cnt,last[N*2];
bool g[N*2],vis[N*2];
struct edge{int to,next;bool used;}e[N*2];
std::queue<int> que;

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

bool check(int mid)
{
	while (!que.empty()) que.pop();
	for (int i=1;i<=tot;i++) vis[i]=0,f[i]=i,g[i]=0;
	for (int i=mid+1;i<=tot;i++) que.push(i),vis[i]=1;
	for (int i=2;i<=cnt;i++) e[i].used=0;
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=last[x];i;i=e[i].next)
		{
			if (e[i].used) continue;
			int y=e[i].to;
			if (vis[y]) return 0;
			vis[y]=1;que.push(y);
			e[i].used=e[i^1].used=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		int x=a[i],y=b[i];
		if (vis[x]||vis[y]) continue;
		x=find(x);y=find(y);
		if (x!=y)
		{
			if (g[x]&&g[y]) return 0;
			f[x]=y;g[y]|=g[x];
		}
		else
		{
			if (g[x]) return 0;
			g[x]=1;
		}
	}
	return 1;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

int main()
{
	scanf("%d",&n);cnt=1;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),w[++tot]=a[i],w[++tot]=b[i];
	std::sort(w+1,w+tot+1);
	tot=std::unique(w+1,w+tot+1)-w-1;
	for (int i=1;i<=n;i++)
	{
		a[i]=std::lower_bound(w+1,w+tot+1,a[i])-w;
		b[i]=std::lower_bound(w+1,w+tot+1,b[i])-w;
		addedge(a[i],b[i]);
	}
	int l=1,r=tot;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	if (r==tot) puts("-1");
	else printf("%d\n",w[r+1]);
	return 0;
}