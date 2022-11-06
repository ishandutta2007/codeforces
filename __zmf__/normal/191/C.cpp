//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=4e5+9;
int n,nxt[N],head[N],ans[N],cnt,to[N],a[N],dep[N],fa[20][N];
inline void addedge(int u,int v)
{
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
int k;
inline void dfs1(int u,int f)
{
	fa[0][u]=f;dep[u]=dep[f]+1;
	for(int i=1;i<=18;i++)
		fa[i][u]=fa[i-1][fa[i-1][u]];
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs1(to[i],u);
		}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);//cout<<x<<" "<<y<<endl;
	for(int i=18;i>=0;i--)
		if(dep[fa[i][x]]>=dep[y])
		{
			x=fa[i][x];
		}
//	cout<<x<<" "<<y<<endl;
//	cout<<"------"<<endl;
	for(int i=18;i>=0;i--)
		if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	if(x!=y)x=fa[0][x],y=fa[0][y];
	return x;
}
inline void dfs2(int u,int f)
{
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs2(to[i],u);a[u]+=a[to[i]];ans[i>>1]=a[to[i]];
		}
}
int main()
{
	n=read();cnt=1;
	for(int i=2;i<=n;i++)
	{
		int uu=read(),vv=read();addedge(uu,vv);addedge(vv,uu);
	}
	dfs1(1,0);//for(int i=1;i<=n;i++)cout<<fa[0][i]<<" ";cout<<endl;
	k=read();
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read();
	//	cout<<x<<" "<<y<<" "<<LCA(x,y)<<endl;
		a[x]++,a[y]++,a[LCA(x,y)]-=2;
	}
	dfs2(1,0); 
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	return 0;
}