#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100005;
int n,q,head[N],adj[N*2],nxt[N*2],len[N*2],p1,p2,p[N],id[N],ans,i,j,k,rt,size[N],fa[N];
ll w,f[N],l;
int find(int x)
{
	return !fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(int a,int b)
{
	return f[a]<f[b];
}
void dfs(int x,int dad,ll d)
{
	if(d>w)
	{
		p1=x;
		w=d;
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
			dfs(adj[y],x,d+len[y]);
}
void Dfs(int x,int dad,ll d)
{
	if(d>w)
	{
		p2=x;
		w=d;
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
			Dfs(adj[y],x,d+len[y]);
}
void work(int x,int dad,ll d)
{
	f[x]=max(f[x],d);
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
			work(adj[y],x,d+len[y]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&j,&k,&len[i*2]);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		len[i*2-1]=len[i*2];
	}
	p1=1,w=0;
	dfs(1,-1,0);
	p2=p1,w=0;
	Dfs(p1,-1,0);
	work(p1,-1,0);
	work(p2,-1,0);
	for(i=2,rt=1;i<=n;++i)
		if(f[i]<f[rt])
			rt=i;
	for(i=1;i<=n;++i)
		p[i]=i;
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;++i)
		id[p[i]]=i;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld",&l);
		for(i=1;i<=n;++i)
			size[i]=0,fa[i]=0;
		ans=0;
		for(i=n,j=n;i>=1;--i)
		{
			++size[find(p[i])];
			for(k=head[p[i]];k;k=nxt[k])
				if(id[adj[k]]>=i&&id[adj[k]]<=j&&find(p[i])!=find(adj[k]))
				{
					size[find(p[i])]+=size[find(adj[k])];
					fa[find(adj[k])]=find(p[i]);
				}
			while(j>=i&&f[p[j]]-f[p[i]]>l)
			{
				--size[find(p[j])];
				--j;
			}
			ans=max(ans,size[find(p[i])]);
		}
		printf("%d\n",ans);
	}
	return 0;
}