#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=1000000007;
typedef long double lb;
int t,n,m,i,head[N],Next[N*2],adj[N*2],leng[N*2],k,vis[N*3],dep[N],p[5],o,q[N*3],u,v,w,x,b[N*3],y,j,f[N],pd[N],nx[N],mp[N];
long long dp[N*3],d[N*3],ans;
vector<int> g[N];
bool flag;
struct str{
	int a[5];
}e[N*3];
void Push(int u,int v,int w)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	leng[k]=w;
}
void Add(int x)
{
	int i;
	for(i=4;i>=0;--i)
		if((x>>i)&1)
			if(p[i]==0)
			{
				p[i]=x;
				return;
			}
			else
				x^=p[i];
	flag=true;
}
void Dec()
{
	int i,j;
	for(i=4;i>=0;--i)
		for(j=i-1;j>=0;--j)
			if((p[i]^p[j])<p[i])
			 	p[i]^=p[j];
}
void dfs(int i,int fa)
{
	int j;
	vis[i]=k;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa&&adj[j]!=1)
			if(vis[adj[j]]!=k)
			{
				dep[adj[j]]=dep[i]^leng[j];
				dfs(adj[j],i);
			}
			else
				if(adj[j]<i)
					Add(dep[adj[j]]^dep[i]^leng[j]);
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void uniot(int u,int v)
{
	int x=Find(u),y=Find(v);
	if(x!=y)
		f[x]=y;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		Push(u,v,w);
		Push(v,u,w);
		if(u>v)
			swap(u,v);
		if(u==1)
			mp[v]=w;
		if(u!=1)
			uniot(u,v);
	}
	for(j=head[1];j!=0;j=Next[j])
		g[Find(adj[j])].push_back(adj[j]);
	k=0;
	for(j=head[1];j!=0;j=Next[j])
		if(pd[Find(adj[j])]==0)
		{
			memset(p,0,sizeof(p));
			pd[Find(adj[j])]=1;
			int x=Find(adj[j]);
			++k;
			flag=false;
			dfs(x,1);
			if(!flag)
			{
				++o;
				nx[o]=1;
				for(int m=0;m<5;++m)
					e[o].a[m]=p[m];
			}
			if(g[x].size()==2)
			{
				if(!flag)
				{
					++nx[o];
					++o;
					for(int m=0;m<5;++m)
						e[o].a[m]=p[m];
				}
				Add(dep[g[x][0]]^dep[g[x][1]]^mp[g[x][0]]^mp[g[x][1]]);
				if(!flag)
				{
					++nx[o-1];
					++o;
					for(int m=0;m<5;++m)
						e[o].a[m]=p[m];
				}
			}
		}
	q[x=1]=0;
	dp[0]=1;
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	for(i=1;i<=o;i+=nx[i])
	{
		y=0;
		for(j=1;j<=x;++j)
			d[q[j]]=dp[q[j]];
		int tot=0;
		for(int y=i;y<i+nx[i];++y)
		{
			for(j=1;j<=x;++j)
			{
				memset(p,0,sizeof(p));
				p[0]=q[j]&1;
				p[1]=(q[j]>>1)&3;
				p[2]=(q[j]>>3)&7;
				p[3]=(q[j]>>6)&15;
				p[4]=(q[j]>>10)&31;
				flag=false;
				for(int t=0;t<5;++t)
					if(e[y].a[t])
						Add(e[y].a[t]);
				if(!flag)
				{
					Dec();
					int t=p[0]+(p[1]<<1)+(p[2]<<3)+(p[3]<<6)+(p[4]<<10);
					d[t]=(d[t]+dp[q[j]])%M;
					if(!vis[t])
					{
						vis[t]=1;
						b[++tot]=t;
					}
				}
			}
		}
		for(j=1;j<=tot;++j)
			q[++x]=b[j];
		for(j=1;j<=x;++j)
			dp[q[j]]=d[q[j]];
	}
	for(j=0;j<(1<<16);++j)
		ans+=dp[j];
	cout<<(ans%M+M)%M;
}