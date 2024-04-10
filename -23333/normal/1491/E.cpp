#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (ll i=h;i<=t;i++)
#define dep(i,t,h) for (ll i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int f[N],head[N],g[N],h[N],sum[N],fa[N],l;
int ans[100][100],cnt[100];
struct re{
	int a,b;
}e[N*2];
void arr(int x,int y)
{
	e[++l].a=head[x];
	e[l].b=y;
	head[x]=l;
}
/*void dfs(int x,int y,int z,int p)
{
	sum[x]=1;
	for (int u=head[x];u;u=e[u].a)
	{
		int v=e[u].b;
		if (!h[v]&&v!=y)
		{
			fa[v]=x;
			dfs(v,x,z,p);
			sum[x]+=sum[v];
		}
	}
	if (sum[x]==f[z-1]||sum[x]==f[z-2])
	{
		ans[p][++cnt[p]]=x;
    }
}
bool dfs2(int x,int y,int z1)
{
	if (x<=3) return 1;
	cnt[z1]=0;
	dfs(y,fa[y],x,z1);
	if (z1>100||cnt[z1]>100) while (1){}; 
	rep(i,1,cnt[z1])
	{
		int now=ans[z1][i];
		h[now]=1;
		int tt=g[sum[y]-sum[now]];
		if (dfs2(g[sum[now]],now,z1+1)&&dfs2(tt,y,z1+1))
		{
		  h[now]=0; 
		  return 1;
	    }
	    h[now]=0;
	}
	return 0;
}*/
bool dfs(int x,int fa,int y,int z)
{
	if (g[y]<=3) return 1;
	sum[x]=1;
    for (int u=head[x];u;u=e[u].a)
    {
    	int v=e[u].b;
    	if (!h[u]&&v!=fa)
    	{
    		z|=dfs(v,x,y,z);
    		h[u]=h[u^1]=1;
    		if (z==0&&g[sum[v]]&&g[y-sum[v]])
    		  z|=dfs(v,x,sum[v],z)&&dfs(x,v,y-sum[v],z);
    		h[u]=h[u^1]=0;
    	}
    }
    sum[x]=1;
    for (int u=head[x];u;u=e[u].a)
    {
    	int v=e[u].b;
    	if (!h[u]&&v!=fa)
    	{
    		sum[x]+=sum[v];
    	}
    }
    return z;
}
int main()
{
	ios::sync_with_stdio(false);
	int T,n;
	cin>>n; l=1;
	rep(i,1,n-1)
	{
		int x,y;
	  cin>>x>>y;
	  arr(x,y); arr(y,x);
    }
    f[0]=1; f[1]=1; g[1]=1;
    rep(i,2,27)
	{ 
	  f[i]=f[i-1]+f[i-2];
	  g[f[i]]=i;
    }
    if (g[n])
    {
       if(dfs(1,0,n,0)) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    } else
    {
    	cout<<"NO"<<endl;
    }
	return 0;
}