//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=4e5+9;
int n,nxt[N],head[N],cnt,val[N],to[N],a[N],dist[N],ans;
bool vis[N];
inline void addedge(int u,int v,int w)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;val[cnt]=w;
}
inline void dfs1(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dist[to[i]]=max(0ll,dist[u]+val[i]);
			dfs1(to[i],u);
		}
}
inline void dfs2(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			if(vis[u])vis[to[i]]=1;
			dfs2(to[i],u);
		}
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)
	{
		int vv=read(),ww=read();addedge(i,vv,ww);addedge(vv,i,ww);
	}
	dfs1(1,-1);
	for(int i=1;i<=n;i++)
		if(dist[i]>a[i])vis[i]=1;
	dfs2(1,-1);
	for(int i=1;i<=n;i++)
		if(vis[i])ans++;
	cout<<ans<<endl;
	return 0;
}