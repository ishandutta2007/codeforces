#include<bits/stdc++.h>
#define Mx 18
using namespace std;
int n,m,q,edge_t=0,ans=0,vec_t,vec1_t;
int la[300002]={},X[300002],Y[300002],qx[300002],qy[300002],cnt[300002],vec[300002],vec1[300002],dep[300002];
bool u[300002]={},vis[300002]={};
int fa[300002][22];
struct aaa
{
	int to,nx;
}edge[600002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(!vis[v=edge[i].to])
			fa[v][0]=x,dep[v]=dep[x]+1,dfs(v),u[(i+1)/2]=1;
}
inline void init()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=n;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=m;++i)read(X[i]),read(Y[i]),add_edge(X[i],Y[i]);
	dep[1]=1,dfs(1),edge_t=0;for(int i=1;i<=n;++i)la[i]=0;
	for(int i=1;i<=m;++i)if(u[i])add_edge(X[i],Y[i]);
	read(q);for(int i=1;i<=q;++i)read(qx[i]),read(qy[i]),++cnt[qx[i]],++cnt[qy[i]];
	for(int i=1;i<=n;++i)ans+=(cnt[i]&1);
	if(!ans)
	{
		puts("YES"),init();
		for(int i=1,z;i<=q;++i)
		{
			vec_t=vec1_t=0,z=LCA(qx[i],qy[i]);
			while(qx[i]!=z)vec[++vec_t]=qx[i],qx[i]=fa[qx[i]][0];
			while(qy[i]!=z)vec1[++vec1_t]=qy[i],qy[i]=fa[qy[i]][0];
			printf("%d\n",vec_t+vec1_t+1);
			for(int j=1;j<=vec_t;++j)printf("%d ",vec[j]);
			printf("%d ",z);
			for(int j=vec1_t;j;--j)printf("%d ",vec1[j]);
			puts("");
		}
	}
	else printf("NO\n%d",(ans>>1));
	return 0;
}