#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,p,edge_t=0,t;
LL res;
int la[2002],st[2002];
LL fac[2002],inv[2002],ans[2002];
LL dp[2002][2002],pre[2002][2002],suf[2002][2002];
struct aaa
{
	int to,nx;
}edge[4002];
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
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%p;
	if(b&1)c=(c*a)%p;
	return c;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%p;
	inv[n]=Pow(fac[n],p-2);for(int i=n;i;--i)inv[i-1]=(inv[i]*i)%p;
}
inline LL C(int a,int b)
{
	return (((fac[a]*inv[b])%p)*inv[a-b])%p;
}
inline void dfs(int x,int f)
{
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs(v,x);
	t=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			st[++t]=v;
			for(int j=1;j<n;++j)pre[t][j]=suf[t][j]=dp[v][j];
		}
	if(!t)
	{
		for(int i=1;i<n;++i)dp[x][i]=i;
		return ;
	}
	for(int i=2;i<=t;++i)for(int j=1;j<=n;++j)(pre[i][j]*=pre[i-1][j])%=p;
	for(int i=t-1;i;--i)for(int j=1;j<n;++j)(suf[i][j]*=suf[i+1][j])%=p;
	for(int i=1;i<n;++i)dp[x][i]=pre[t][i];
	if(x==1)return ;
	for(int i=1;i<=t;++i)
	{
		res=0;
		for(int j=1;j<n;++j)(dp[x][j]+=res*(dp[st[i]][j]-dp[st[i]][j-1]))%=p,(res+=(i>1? pre[i-1][j]:1)*(i<t? suf[i+1][j]:1))%=p;
	}
	for(int i=2;i<n;++i)(dp[x][i]+=dp[x][i-1])%=p;
}
int main()
{
	read(n),read(p),init();
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0);
	for(int i=1;i<n;++i)
	{
		ans[i]=dp[1][i];
		for(int j=1;j<i;++j)(ans[i]-=C(i,j)*ans[j])%=p;
		printf("%lld ",(ans[i]+p)%p);
	}
	return 0;
}