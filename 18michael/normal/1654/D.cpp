#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 200000
#define LL long long
#define mod 998244353
using namespace std;
int n,Test_num,edge_t,p_t=0;LL res,ans;
int la[200002]={},mnp[200002],p[200002],cnt[200002],mx[200002];
struct aaa
{
	int to,nx,A,B;
}edge[400002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void add_edge(int x,int y,int z,int w)
{
	edge[++edge_t]=(aaa){y,la[x],z,w},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],w,z},la[y]=edge_t;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!mnp[i])mnp[i]=i,p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			mnp[p[j]*i]=p[j];
			if(!(i%p[j]))break;
		}
	}
}
inline void dfs(int x,int f)
{
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			for(int j=edge[i].B;j>1;j/=mnp[j])--cnt[mnp[j]];
			for(int j=edge[i].A;j>1;j/=mnp[j])mx[mnp[j]]=max(mx[mnp[j]],++cnt[mnp[j]]);
			dfs(v,x);
			for(int j=edge[i].B;j>1;j/=mnp[j])++cnt[mnp[j]];
			for(int j=edge[i].A;j>1;j/=mnp[j])--cnt[mnp[j]];
		}
}
inline void dfs1(int x,int f,LL res)
{
	//printf("DFS1 %d %d %lld\n",x,f,res);
	ans=(ans+res)%mod;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs1(v,x,(((res*edge[i].B)%mod)*Pow(edge[i].A,mod-2))%mod);
}
int main()
{
	init(),read(Test_num);
	while(Test_num--)
	{
		read(n),edge_t=0,ans=0;
		for(int i=1;i<=n;++i)la[i]=cnt[i]=mx[i]=0;
		for(int i=1,a,b,c,d;i<n;++i)read(a),read(b),read(c),read(d),add_edge(a,b,c,d);
		dfs(1,0),res=1;
		for(int i=1;i<=n;++i)res=(res*Pow(i,mx[i]))%mod;
		dfs1(1,0,res),printf("%lld\n",ans);
	}
	return 0;
}