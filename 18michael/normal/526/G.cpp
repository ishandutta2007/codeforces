#include<bits/stdc++.h>
#define Mx 16
using namespace std;
int n,q,edge_t=0,lastans=0,X,Y,Z;
int la[100002];
struct aaa
{
	int to,nx,val;
}edge[200002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
struct bbb
{
	int val,id;
};
inline bool cmp(bbb a,bbb b)
{
	return a.val>b.val? 1:0;
}
struct ccc
{
	int rt,mx,st_t;
	int dep[100002],son[100002],mxd[100002],sum[100002],top[100002],rk[100002],fa[100002];
	int up[100002][18],mn[100002][18];
	bbb st[100002];
	inline void dfs(int x,int f,bool o)
	{
		if(dep[x]>dep[mx])mx=x;
		if(o)mxd[x]=dep[x];
		for(int i=la[x],v;i;i=edge[i].nx)
			if((v=edge[i].to)!=f)
			{
				dep[v]=dep[x]+edge[i].val,dfs(v,x,o);
				if(o && mxd[v]>mxd[son[x]])mxd[x]=mxd[son[x]=v];
			}
		if(o)for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && v!=son[x])st[++st_t]=(bbb){mxd[v]-dep[x],v};
	}
	inline void dfs1(int x,int f,int t)
	{
		fa[x]=f,top[x]=t;
		if(son[x])dfs1(son[x],x,t);
		for(int i=la[x],v;i;i=edge[i].nx)
			if((v=edge[i].to)!=f && v!=son[x])
				dfs1(v,x,v);
	}
	inline void init()
	{
		dfs1(rt,0,rt),st[++st_t]=(bbb){mxd[rt],rt},sort(st+1,st+st_t+1,cmp);
		for(int i=1;i<=st_t;++i)sum[i]=sum[i-1]+st[i].val,rk[st[i].id]=i;
		for(int i=1;i<=n;++i)up[i][0]=fa[top[i]],mn[i][0]=rk[top[fa[top[i]]]];
		for(int i=1;i<=Mx;++i)for(int j=1;j<=n;++j)up[j][i]=up[up[j][i-1]][i-1],mn[j][i]=min(mn[j][i-1],mn[up[j][i-1]][i-1]);
	}
	inline void solve()
	{
		if(rk[top[X]]<=(Y<<1)-1)return (void)(lastans=max(lastans,sum[min((Y<<1)-1,st_t)]));
		Z=X;for(int i=Mx;~i;--i)if(mn[Z][i]>(Y<<1)-2)Z=up[Z][i];
		lastans=max(lastans,sum[(Y<<1)-2]+mxd[X]-dep[fa[top[Z]]]),Z=X;
		for(int i=Mx;~i;--i)if(mn[Z][i]>(Y<<1)-1)Z=up[Z][i];
		lastans=max(lastans,sum[(Y<<1)-1]+mxd[X]-mxd[fa[top[Z]]]);
	}
}A,B;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,x,y,z;i<n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x,y,z);
	A.dfs(1,A.mx=A.st_t=0,0),B.dfs(B.rt=A.mx,B.mx=B.st_t=0,1),A.dfs(A.rt=B.mx,A.dep[B.mx]=A.mx=0,1),A.init(),B.init();
	for(;q--;)scanf("%d%d",&X,&Y),X=(X+lastans-1)%n+1,Y=(Y+lastans-1)%n+1,lastans=0,A.solve(),B.solve(),printf("%d\n",lastans);
	return 0;
}