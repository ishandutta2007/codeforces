#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
#define pb push_back
const int MAXN=1000005;

int n,a[MAXN],p[MAXN];
vector<int> G[MAXN];
inline bool cmp(int x,int y)
	{return a[x]<a[y];}

int fa[MAXN],size[MAXN];
bool vis[MAXN];
int getfa(int u)
	{return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void merge(int u,int v)
{
	u=getfa(u);v=getfa(v);
	if(u==v)return;
	fa[v]=u;
	size[u]+=size[v];
}

int main()
{
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	G[u].pb(v);G[v].pb(u);
    }
    ll ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
		fa[i]=i,size[i]=1,vis[i]=0;
    for(int i=1;i<=n;i++)
    {
    	u=p[i];vis[u]=1;
    	ll sum=0,s2=0,t;
    	for(int j=0;j<G[u].size();++j)
    		if(vis[G[u][j]])
    		{
    			t=size[getfa(G[u][j])];
				sum+=t;s2+=(ll)t*t;
			}
    	for(int j=0;j<G[u].size();++j)
    		if(vis[G[u][j]])
    			merge(u,G[u][j]);
    	ans1+=(ll)a[u]*((sum*sum-s2)/2+size[u]);
    }
    for(int i=1;i<=n;i++)
		fa[i]=i,size[i]=1,vis[i]=0;
    for(int i=n;i>0;i--)
    {
    	u=p[i];vis[u]=1;
    	ll sum=0,s2=0,t;
    	for(int j=0;j<G[u].size();++j)
    		if(vis[G[u][j]])
    		{
    			t=size[getfa(G[u][j])];
				sum+=t;s2+=(ll)t*t;
			}
    	for(int j=0;j<G[u].size();++j)
    		if(vis[G[u][j]])
    			merge(u,G[u][j]);
    	ans2+=(ll)a[u]*((sum*sum-s2)/2+size[u]);
    }
    cout<<ans1-ans2<<endl;
    return 0;
}