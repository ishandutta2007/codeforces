#include<bits/stdc++.h>
#define mod 1000000007
#define LL long long
using namespace std;
int n,edge_t=0;
LL ans=0,ans1=0;
int la[200002]={};
LL val[200002];
LL f[200002][2],g[200002][2];
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
inline void dfs(int x,int fa)
{
	LL f0=0,f1=0,g0=0,g1=0;
	f[x][0]=g[x][0]=0,f[x][1]=val[x],g[x][1]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=fa)
		{
			dfs(v,x);
			f[x][0]=(f[x][0]+val[x]*g[v][1]-f[v][1])%mod;
			g[x][0]=(g[x][0]+g[v][1])%mod;
			f[x][1]=(f[x][1]+val[x]*g[v][0]-f[v][0])%mod;
			g[x][1]=(g[x][1]+g[v][0])%mod;
			ans=(((ans-f0*g[v][0]+f1*g[v][1]-f[v][0]*g0+f[v][1]*g1)%mod)+((g0*g[v][0]-g1*g[v][1])%mod)*val[x])%mod;
			f0=(f0+f[v][0])%mod;
			f1=(f1+f[v][1])%mod;
			g0=(g0+g[v][0])%mod;
			g1=(g1+g[v][1])%mod;
		}
	ans=(ans+f[x][1]-val[x])%mod,ans1=(ans1+val[x])%mod;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(val[i]);
	for(int i=1,x,y;i<n;++i)read(x),read(y),add_edge(x,y);
	dfs(1,0);
	return 0&printf("%lld",((((ans<<1)+ans1)%mod)+mod)%mod);
}