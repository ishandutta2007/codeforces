#include<bits/stdc++.h>
#define Mx 18
#define eps 1e-9
#define LL long long
#define mod 1000000007
using namespace std;
int n,edge_t=0,dfn_t=0,to_t=0,st_t,p_t=0;
LL ans=0,res,res1;
int a[200002],la[200002],dfn[200002],dep[200002],num[200002],st[200002],phi[200002],p[200002];
bool u[200002];
LL f[200002];
int to[400002][22];
vector<int> Vec;
vector<int> vec[200002],vec1[200002],vec2[200002];
struct aaa
{
	int to,nx;
}edge[400002];
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
	phi[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!u[i])p[++p_t]=i,phi[i]=i-1;
		for(int j=1;j<=p_t && p[j]<=n/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))
			{
				phi[p[j]*i]=phi[i]*p[j];
				break;
			}
			phi[p[j]*i]=phi[i]*(p[j]-1);
		}
	}
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	dfn[x]=(++dfn_t),to[num[x]=(++to_t)][0]=x;
	for(int i=0;i<vec2[a[x]].size();++i)vec[vec2[a[x]][i]].push_back(x);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dep[v]=dep[x]+1,dfs(v,x),to[++to_t][0]=x;
}
inline int merge(int x,int y)
{
	return dep[x]<dep[y]? x:y;
}
inline int LCA(int x,int y)
{
	if(num[x]>num[y])swap(x,y);
	int len=log2(num[y]-num[x]+1)+eps;
	return merge(to[num[x]][len],to[num[y]-(1<<len)+1][len]);
}
inline void ins(int x,int y)
{
	if(vec1[x].empty())Vec.push_back(x);
	vec1[x].push_back(y);
}
inline LL dfs1(int x,int y)
{
	LL sum=(u[x]? phi[a[x]]:0),tmp;
	for(int i=0,v;i<vec1[x].size();++i)tmp=dfs1(v=vec1[x][i],y),f[y]=(f[y]-((sum*tmp)%mod)*dep[x]*4)%mod,sum=(sum+tmp)%mod;
	return sum;
}
int main()
{
	scanf("%d",&n),init();
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]),u[i]=0;
		for(int j=i;j<=n;j+=i)vec2[j].push_back(i);
	}
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0);
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=to_t;++j)to[j][i]=merge(to[j][i-1],to[j+(1<<(i-1))][i-1]);
	for(int i=1;i<=n;++i)
	{
		res=res1=0,st[st_t=1]=1;
		while(!Vec.empty())vec1[Vec.back()].clear(),Vec.pop_back();
		for(int j=0,v,x;j<vec[i].size();++j)
		{
			u[v=vec[i][j]]=1,res=(res+(LL)phi[a[v]]*dep[v])%mod,res1=(res1+phi[a[v]])%mod,f[i]=(f[i]-(((LL)phi[a[v]]*phi[a[v]])%mod)*dep[v]*2)%mod;
			if(v==1)continue;
			x=LCA(v,st[st_t]);
			while(st_t>1 && dep[st[st_t-1]]>=dep[x])ins(st[st_t-1],st[st_t]),--st_t;
			if(st[st_t]^x)ins(x,st[st_t]),st[st_t]=x;
			st[++st_t]=v;
		}
		for(int i=1;i<st_t;++i)ins(st[i],st[i+1]);
		dfs1(st[1],i),f[i]=(f[i]+res*res1*2)%mod;
		for(int j=0;j<vec[i].size();++j)u[vec[i][j]]=0;
	}
	for(int i=n;i;--i)
	{
		for(int j=2*i;j<=n;j+=i)f[i]=(f[i]-f[j])%mod;
		ans=(ans+((Pow(phi[i],mod-2)*i)%mod)*f[i])%mod;
	}
	return 0&printf("%lld",(((ans*Pow(((LL)n*(n-1))%mod,mod-2))%mod)+mod)%mod);
}