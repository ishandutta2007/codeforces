#include<bits/stdc++.h>
#define LL long long
using namespace std;
int Test_num,n,edge_t,s,st_t,dfn_t;LL ans;
int la[200002],st[200002],dfn[200002],siz[200002];
bool ring[200002];
struct aaa
{
	int to,nx;
}edge[400002];
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
inline void dfs_ring(int x,int y)
{
	dfn[x]=(++dfn_t);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=y)
		{
			if(dfn[v])s=v;else dfs_ring(v,x);
			if(s)
			{
				if(dfn[x]>=dfn[s])st[++st_t]=x,ring[x]=1;
				return ;
			}
		}
}
inline void dfs(int x,int y)
{
	LL res=0;siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=y && !ring[v])
			dfs(v,x),siz[x]+=siz[v],ans+=(res+1)*siz[v],res+=siz[v];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),edge_t=s=st_t=dfn_t=0,ans=1LL*n*n;
		for(int i=1;i<=n;++i)la[i]=dfn[i]=ring[i]=0;
		for(int i=1,x,y;i<=n;++i)read(x),read(y),add_edge(x,y);
		dfs_ring(1,0);
		for(int i=1;i<=st_t;++i)dfs(st[i],0),ans-=1LL*siz[st[i]]*siz[st[i]];
		printf("%lld\n",ans);
	}
	return 0;
}