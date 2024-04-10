#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const long long M=3799912185593857ll;
int n,m,t,i,d[N],vis[N],a[N],f[N],p[N],q[N],u,v,j;
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
vector<int> g[N],c[N],w[N];
void dfs(int i,int fa)
{
	vis[i]=1;
	for(auto j:c[i])
		if(j!=fa)
		{
			dfs(j,i);
			if(!w[j].size())
				w[i].push_back(j);
		}
}
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
		{
			vis[i]=d[i]=f[i]=0;
			g[i].clear();
			c[i].clear();
			w[i].clear();
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			++d[u],++d[v];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(i=1;i<=n;++i)
			if(d[i]!=n-1)
			{
				int k=0;
				for(auto it:g[i])
					a[++k]=it;
				a[++k]=i;
				sort(a+1,a+1+k);
				for(j=1;j<=k;++j)
					if(j!=a[j])
						break;
				int x=Find(i),y=Find(j);
				if(x!=y)
				{
					f[x]=y;
					c[i].push_back(j);
					c[j].push_back(i);
				}
			}
		for(i=1;i<=n;++i)
			if(c[i].size()&&!vis[i])
			{
				dfs(i,0);
				if(!w[i].size())
					w[c[i][0]].push_back(i);
			}
		int k=0;
		for(i=1;i<=n;++i)
			if(!c[i].size())
			{
				p[i]=++k;
				q[i]=k;
			}
			else
				if(w[i].size())
				{
					for(j=0;j<w[i].size();++j)
						p[w[i][j]]=j+k+1;
					p[i]=w[i].size()+k+1;
					q[i]=k+1;
					for(j=0;j<w[i].size();++j)
						q[w[i][j]]=j+k+2;
					k+=w[i].size()+1;
				}
		for(i=1;i<=n;++i)
			printf("%d ",p[i]);
		printf("\n");
		for(i=1;i<=n;++i)
			printf("%d ",q[i]);
		printf("\n");
	}
}