#include<cstdio>
#define Mx 500000
#define LL long long
#define mod 1000000007
#define inv 500000004
int n,m,c=0,res,res1,sum=0,edge_t=0;
int la[500002]={},deg[500002]={},dep[500002]={},fa[500002],len[500002],s[500002],cnt[500002]={};
LL ipw[500002];
struct aaa
{
	int to,nx;
}edge[1000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t,++deg[y];
}
inline void dfs(int x)
{
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!dep[v=edge[i].to])dep[v]=dep[x]+1,fa[v]=x,dfs(v);
		if(dep[v]<dep[x]-1)sum=(sum+ipw[len[++c]=dep[x]-dep[v]+1])%mod,s[c]=x;
	}
}
inline LL VV()
{
	return (((ipw[2]*n)%mod)*(n+1))%mod;
}
inline LL EE()
{
	res=0;for(int i=1;i<=n;++i)res=(res+1LL*deg[i]*(deg[i]-1))%mod;
	return (ipw[2]*m+ipw[3]*res+ipw[4]*((1LL*m*m-m-res)%mod))%mod;
}
inline LL CC()
{
	res=0;for(int i=1;i<=c;++i)for(int j=len[i],x=s[i];j;--j,x=fa[x])cnt[x]=(cnt[x]+ipw[len[i]])%mod;
	for(int i=1;i<=c;++i)
	{
		res1=0;for(int j=len[i],x=s[i];j;--j,x=fa[x])res1=(res1+cnt[x]-ipw[len[i]])%mod;
		res=(res+ipw[len[i]]+((ipw[len[i]]*(sum-ipw[len[i]]-res1))%mod)+2*ipw[len[i]]*res1)%mod;
	}
	return res;
}
inline LL VE()
{
	res=0;for(int i=1;i<=n;++i)res=(res+deg[i])%mod;
	return (ipw[2]*res+ipw[3]*((1LL*n*m-res)%mod))%mod;
}
inline LL VC()
{
	res=0;for(int i=1;i<=c;++i)res=(res+ipw[len[i]]*len[i]+ipw[len[i]+1]*(n-len[i]))%mod;
	return res;
}
inline LL EC()
{
	res=0;
	for(int i=1;i<=c;++i)
	{
		res1=-len[i];for(int j=len[i],x=s[i];j;--j,x=fa[x])res1=(res1+deg[x])%mod;
		res=(res+ipw[len[i]]*len[i]+ipw[len[i]+1]*(res1-len[i])+ipw[len[i]+2]*(m-res1))%mod;
	}
	return res;
}
inline LL X2()
{
	return (VV()+EE()+CC()-2*VE()+2*VC()-2*EC())%mod;
}
inline LL V()
{
	return (ipw[1]*n)%mod;
}
inline LL E()
{
	return (ipw[2]*m)%mod;
}
inline LL C()
{
	res=0;for(int i=1;i<=c;++i)res=(res+ipw[len[i]])%mod;
	return res;
}
inline LL X1()
{
	res=(V()-E()+C())%mod;
	return (1LL*res*res)%mod;
}
int main()
{
	scanf("%d%d",&n,&m),ipw[0]=dep[1]=1;
	for(int i=1;i<=Mx;++i)ipw[i]=(ipw[i-1]*inv)%mod;
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1);return 0&printf("%lld",(X2()-X1()+2*mod)%mod);
}