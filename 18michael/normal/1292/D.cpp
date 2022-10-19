#include<cstdio>
#include<bitset>
#include<algorithm>
#define Mx 5000
#define LL long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
int n,p_t=0,num_t=1,mx,edge_t=0,st_t;LL ans=inf;
int p[672],cnt[10002]={},id[10002],to[10002],to1[10002],la[10002]={},siz[10002],st[10002];
LL dp[10002],dp1[10002];
bitset<5002> u;
struct aaa
{
	int a[672];
}num[10002];
struct bbb
{
	int to,nx,val;
}edge[10002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(bbb){y,la[x],z},la[x]=edge_t;
}
inline bool cmp(int a,int b)
{
	for(int i=p_t;i;--i)
	{
		if(num[a].a[i]<num[b].a[i])return 1;
		if(num[a].a[i]>num[b].a[i])return 0;
	}
	return 0;
}
inline bool check(int a,int b)
{
	for(int i=1;i<=p_t;++i)
		if(num[a].a[i]!=num[b].a[i])
			return 1;
	return 0;
}
inline int dis(int x,int y)
{
	int res=0;
	for(int i=1;i<=p_t;++i)res+=num[to1[y]].a[i]-num[to1[x]].a[i];
	return res;
}
inline bool isfa(int x,int y)
{
	for(int i=p_t;i;--i)
		if(num[to1[x]].a[i]!=num[to1[y]].a[i])
		{
			for(int j=1;j<i;++j)
				if(num[to1[x]].a[j])
					return 0;
			break;
		}
	return 1;
}
inline void init()
{
	for(int i=1;i<=Mx;++i)id[i]=i,id[Mx+i]=Mx+i;
	for(int i=2,i1;i<=Mx;++i)
	{
		for(int j=1;j<=p_t;++j)num[i].a[j]=num[i-1].a[j];
		if(!u[i])p[++p_t]=i,++num[i].a[p_t],mx=p_t;
		else
		{
			i1=i;
			for(int j=1;j<=p_t && p[j]<=i1;++j)
				if(!(i1%p[j]))
				{
					mx=j;
					do ++num[i].a[j],i1/=p[j];while(!(i1%p[j]));
				}
		}
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
		for(int j=mx;j<=p_t;++j)num[Mx+i].a[j]=num[i-1].a[j];
	}
	sort(id+1,id+2*Mx+1,cmp),to[id[1]]=1;
	for(int i=2;i<=2*Mx;++i)
	{
		if(check(id[num_t],id[i]))id[++num_t]=id[i];
		to[id[i]]=num_t,to1[num_t]=id[i];
	}
	st[st_t=0]=1;
	for(int i=2;i<=num_t;++i)
	{
		while(st_t && !isfa(st[st_t],i))add_edge(st[st_t-1],st[st_t],dis(st[st_t-1],st[st_t])),--st_t;
		st[++st_t]=i;
	}
	for(int i=st_t;i;--i)add_edge(st[i-1],st[i],dis(st[i-1],st[i]));
}
inline void dfs(int x)
{
	siz[x]=cnt[x],dp[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to),siz[x]+=siz[v],dp[x]+=dp[v]+1LL*siz[v]*edge[i].val;
}
inline void dfs1(int x,int f,LL val)
{
	if(x>1)dp[x]=dp[f]+val*(n-2*siz[x]);ans=min(ans,dp[x]);
	for(int i=la[x];i;i=edge[i].nx)dfs1(edge[i].to,x,edge[i].val);
}
int main()
{
	init(),scanf("%d",&n);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),++cnt[to[x+(!x)]];
	dfs(1),dfs1(1,0,1),printf("%lld",ans);
	return 0;
}