#include<bits/stdc++.h>
#define Mx 18
#define LL long long
#define mod 998244353
using namespace std;
int n,k,edge_t=0,e_t=0;
int a[300002],la[300002],dep[300002],rt[300002],lae[300002],col[300002];
int fa[300002][22];
LL F[300002][2];
vector<int> vec[300002];
struct aaa
{
	int to,nx;
}edge[600002],e[600002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	if(x<y)
	{
		e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t;
		e[++e_t]=(aaa){x,lae[y]},lae[y]=e_t;
	}
}
inline void dfs(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x,d+1);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs1(int x,int f)
{
	F[x][0]=(!col[rt[x]]),F[x][1]=(col[rt[x]]>0);
	for(int i=lae[x],v;i;i=e[i].nx)
		if((v=e[i].to)!=f)
			dfs1(v,x),F[x][1]=(F[x][1]*(F[v][0]+F[v][1])+F[x][0]*F[v][1])%mod,F[x][0]=(F[x][0]*(F[v][0]+F[v][1]))%mod;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),vec[a[i]].push_back(rt[i]=i);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0,1);
	for(int i=1,x;i<=k;++i)
	{
		if(!vec[i].size())continue;
		x=vec[i][0];
		for(int j=1;j<vec[i].size();++j)x=LCA(x,vec[i][j]);
		for(int j=0;j<vec[i].size();++j)for(;dep[vec[i][j]]>dep[x] && (getroot(vec[i][j]),rt[vec[i][j]])!=(getroot(fa[vec[i][j]][0]),rt[fa[vec[i][j]][0]]);rt[rt[fa[vec[i][j]][0]]]=rt[vec[i][j]],vec[i][j]=fa[vec[i][j]][0]);
	}
	for(int i=1;i<=n;++i)
	{
		getroot(i);
		if(!col[rt[i]])col[rt[i]]=a[i];
		else if(a[i] && (col[rt[i]]^a[i]))return 0&puts("0");
	}
	for(int i=1;i<=n;++i)for(int j=la[i];j;j=edge[j].nx)add_e(rt[edge[j].to],rt[i]);
	for(int i=1;i<=n;++i)if(rt[i]==i)return dfs1(i,0),printf("%lld\n",F[i][1]),0;
}