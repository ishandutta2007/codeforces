#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,edge_t=0,col_t=0,G,tot;
LL ans=0;
int la[100002],col[100002],siz[100002],mx[100002];
LL A[100002],B[100002],ipw[100002];
map<int,int> mp;
vector<int> vec;
struct aaa
{
	int to,nx,val;
}edge[200002];
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%m;
	if(b&1)c=(c*a)%m;
	return c;
}
inline int phi(int x)
{
	int res=x;
	for(int i=2;i*i<=x;++i)
		if(!(x%i))
		{
			res=res/i*(i-1);
			do x/=i;while(!(x%i));
		}
	if(x>1)res=res/x*(x-1);
	return res;
}
inline void dfs(int x,int f)
{
	siz[x]=1,mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])dfs(v,x),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f)
{
	if((mx[x]=max(mx[x],tot-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])dfs1(v,x);
}
inline void dfs2(int x,int f,LL tmp)
{
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])ans+=((!(A[v]=(A[x]+tmp*edge[i].val)%m))+(!(B[v]=(B[x]*10+edge[i].val)%m))),dfs2(v,x,(tmp*10)%m);
}
inline void dfs3(int x,int f,int d)
{
	if(mp.count((m+((-B[x]*ipw[d])%m))%m))ans+=mp[(m+((-B[x]*ipw[d])%m))%m];
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])dfs3(v,x,d+1);
}
inline void dfs4(int x,int f)
{
	++mp[A[x]];
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==col[x])dfs4(v,x);
}
inline void dfs5(int x,int f,int c1,int c2)
{
	col[x]=c2;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==c1)dfs5(v,x,c1,c2);
}
inline void solve(int x,int c)
{
	int g;dfs(x,0),tot=siz[x],dfs1(G=x,0),g=G,dfs2(g,A[g]=B[g]=0,1),mp.clear(),vec.clear();
	for(int i=la[g],v;i;i=edge[i].nx)if(col[v=edge[i].to]==c)dfs3(v,g,1),dfs4(v,g),vec.push_back(v);
	mp.clear();
	for(int i=vec.size()-1,v;~i;--i)dfs3(v=vec[i],g,1),dfs4(v,g);
	for(int i=la[g],v;i;i=edge[i].nx)if(col[v=edge[i].to]==c)dfs5(v,g,c,++col_t),solve(v,col_t);
}
int main()
{
	scanf("%d%d",&n,&m),ipw[ipw[0]=1]=Pow(10,phi(m)-1);
	for(int i=2,x,y,z;i<=n;++i)scanf("%d%d%d",&x,&y,&z),add_edge(x+1,y+1,z),ipw[i]=(ipw[i-1]*ipw[1])%m;
	solve(1,0),printf("%lld",ans);
	return 0;
}