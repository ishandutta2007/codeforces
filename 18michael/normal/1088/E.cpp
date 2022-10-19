#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,mx=-inf,edge_t=0,num=0;LL ans=0;
int a[300002],la[300002]={};LL dp[300002];
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
inline void dfs1(int x,int f)
{
	dp[x]=a[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs1(v,x);
			if(dp[v]>0)dp[x]+=dp[v];
		}
	ans=max(ans,dp[x]);
}
inline void dfs2(int x,int f)
{
	dp[x]=a[x];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs2(v,x);
			if(dp[v]>0)dp[x]+=dp[v];
		}
	if(dp[x]==ans)++num,dp[x]=0;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),mx=max(mx,a[i]);
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	if(mx<=0)
	{
		for(int i=1;i<=n;++i)if(a[i]==mx)++ans;
		printf("%lld %lld",ans*mx,ans);
	}
	else dfs1(1,0),dfs2(1,0),printf("%lld %d",ans*num,num);
	return 0;
}