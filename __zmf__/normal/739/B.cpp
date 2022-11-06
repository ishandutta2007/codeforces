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
int n,cnt,col[N],a[N];
int to[N],nxt[N],head[N],val[N],dis[N],ans[N];
int fa[22][N];
inline void addedge(int u,int v,int w)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;val[cnt]=w;
}
inline void dfs1(int u,int f)
{
	fa[0][u]=f;
	for(int i=1;i<=20;i++)fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dis[to[i]]=dis[u]+val[i];
			dfs1(to[i],u);
		}
}
inline void dfs2(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs2(to[i],u);
			ans[u]+=ans[to[i]];
		}
}
inline void work(int u)
{
	int v=u;
	for(int i=20;i>=0;i--)
		if(fa[i][v]&&dis[u]-dis[fa[i][v]]<=a[u])v=fa[i][v];
	ans[fa[0][u]]++;ans[fa[0][v]]--;
//	cout<<u<<" "<<v<<endl;
	return ;
}
signed main()
{
	n=read();dis[0]=-(1e9+7);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int uu=i+1,vv=read(),ww=read();
		addedge(uu,vv,ww);addedge(vv,uu,ww);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++)work(i);
	dfs2(1,0);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}