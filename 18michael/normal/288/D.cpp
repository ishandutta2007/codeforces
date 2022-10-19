#include<cstdio>
#define LL unsigned long long
int n,edge_t=0;LL ans;
int la[80002]={};LL siz[80002];
struct aaa
{
	int to,nx;
}edge[160002];
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
inline void dfs(int x,int f)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x),siz[x]+=siz[v];
	LL ins=siz[x]*(siz[x]-1)/2,ous=(n-siz[x])*siz[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			ins-=siz[v]*(siz[v]-1)/2;
	ans-=ins*(ins-1)+ins*ous*2;
}
int main()
{
	read(n);if(n<4)return 0&puts("0");
	ans=(1LL*n*(n-1))/2,ans*=(ans-1);
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	dfs(1,1),printf("%llu",ans);
	return 0;
}