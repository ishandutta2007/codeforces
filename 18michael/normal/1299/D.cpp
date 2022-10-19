#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,m,t=0,edge_t=0,rt_t=0,i0=0,i1=1,ans=0;
int la[100002],rt[100002],pre[100002],deg[100002],sum[100002];
int num[382][382],f[2][382];
bool u[100002];
vector<int> Vec;
vector<int> vec[382],vec2[100002];
unordered_map<int,int> mp;
struct aaa
{
	int to,nx,val;
}edge[200002];
struct bbb
{
	int a[5];
	inline bool ins(int x)
	{
		for(int i=4;~i;--i)
			if((x>>i)&1)
			{
				if(!a[i])
				{
					a[i]=x;
					for(int j=0;j<i;++j)if((a[i]>>j)&1)a[i]^=a[j];
					for(int j=4;j>i;--j)if((a[j]>>i)&1)a[j]^=a[i];
					return 1;
				}
				x^=a[i];
			}
		return 0;
	}
	inline int getHs()
	{
		return a[0]|(a[1]<<1)|(a[2]<<3)|(a[3]<<6)|(a[4]<<15);
	}
}A[382],B[100002],tmp;
inline void add(int &x,int y)
{
	if((x+=y)>=mod)x-=mod;
}
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void dfs(int x,bbb a)
{
	vec[++t]=Vec,A[mp[a.getHs()]=t]=a;
	if(x>31)return ;
	for(int i=x;i<32;++i)if((tmp=a).ins(i) && !mp.count(tmp.getHs()))Vec.push_back(i),dfs(i+1,tmp),Vec.pop_back();
}
inline void init()
{
	dfs(1,(bbb){{}});
	for(int i=1;i<=t;++i)
		for(int j=1;j<=t;++j)
		{
			tmp=A[j],num[i][j]=1;
			for(int k=0;k<=4;++k)if(A[i].a[k])num[i][j]&=tmp.ins(A[i].a[k]);
			if(num[i][j])num[i][j]=mp[tmp.getHs()];
		}
}
inline void dfs(int x,int f)
{
	rt[x]=rt_t;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!rt[v=edge[i].to])pre[v]=(pre[x]^edge[i].val),dfs(v,x);
		else if(rt[v]==rt[x] && v!=f && x<v && !B[rt_t].ins(pre[x]^pre[v]^edge[i].val))u[rt_t]=1;
	}
}
int main()
{
	init(),scanf("%d%d",&n,&m),rt[1]=-1,f[1][1]=1;
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	for(int i=la[1],v;i;i=edge[i].nx)
	{
		if(!rt[v=edge[i].to])++rt_t,dfs(v,1);
		vec2[rt[v]].push_back(v),sum[rt[v]]^=edge[i].val,++deg[rt[v]];
	}
	for(int i=1,x;i<=rt_t;++i)
	{
		if(u[i])continue;
		i0^=1,i1^=1;
		for(int j=1;j<=t;++j)f[i1][j]=f[i0][j];
		x=mp[B[i].getHs()];
		for(int j=1;j<=t;++j)
		{
			add(f[i1][num[x][j]],f[i0][j]);
			if(deg[i]>1)add(f[i1][num[x][j]],f[i0][j]);
		}
		if(deg[i]==1)continue;
		for(int j=la[vec2[i][0]],v;j;j=edge[j].nx)if((v=edge[j].to)==vec2[i][1])sum[i]^=edge[j].val;
		if(B[i].ins(sum[i]))
		{
			x=mp[B[i].getHs()];
			for(int j=1;j<=t;++j)add(f[i1][num[x][j]],f[i0][j]);
		}
	}
	for(int i=1;i<=t;++i)add(ans,f[i1][i]);
	return 0&printf("%d",ans);
}