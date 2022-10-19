#include<bits/stdc++.h>
#define Mx 18
using namespace std;
int n,k,r,tot,edge_t=0,Q;
int la[400002],rt[400002],col[400002],dep[400002];
int fa[400002][22];
vector<int> vec[200002];
typedef pair<int,int> P;P p;
queue<P> q;
struct aaa
{
	int to,nx;
}edge[800002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void getroot(int x)
{
	if(rt[x]==x)return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f)
{
	for(int i=0,v;i<vec[x].size();++i)if((v=vec[x][i])!=f)add_edge(x,++tot),add_edge(tot,v),dep[v]=(dep[tot]=dep[fa[fa[v][0]=tot][0]=x]+1)+1,dfs(v,x);
}
inline void get_LCA()
{
	for(int i=1;i<=Mx;++i)
		for(int j=1;j<=tot;++j)
			fa[j][i]=fa[fa[j][i-1]][i-1];
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
int main()
{
	scanf("%d%d%d",&n,&k,&r),tot=n;
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),vec[x].push_back(y),vec[y].push_back(x);
	dfs(dep[1]=1,0),get_LCA();
	for(int i=1,x;i<=r;++i)scanf("%d",&x),q.push(P(rt[x]=col[x]=x,0));
	for(;!q.empty();)
	{
		p=q.front(),q.pop(),getroot(col[p.first]);
		for(int i=la[p.first],v;i;i=edge[i].nx)
		{
			if(!col[v=edge[i].to])
			{
				col[v]=col[p.first];
				if(p.second+1<k)q.push(P(v,p.second+1));
			}
			else getroot(col[v]),rt[rt[col[v]]]=rt[col[p.first]];
		}
	}
	for(int i=1;i<=n;++i)if(rt[i])getroot(i);
	for(int i=1;i<=tot;++i)if(col[i] && rt[col[i]]!=col[i])col[i]=rt[col[i]];
	scanf("%d",&Q);
	for(int x,y,z;Q--;)
	{
		scanf("%d%d",&x,&y);
		if(dep[x]+dep[y]-2*dep[z=LCA(x,y)]<=2*k)
		{
			puts("YES");
			continue;
		}
		if(dep[x]-dep[z]<k)swap(x,y);
		for(int i=Mx;~i;--i)if((k>>i)&1)x=fa[x][i];
		if(dep[y]-dep[z]<k)z=dep[x]+dep[y]-2*dep[z]-k,y=x;
		else z=k;
		for(int i=Mx;~i;--i)if((z>>i)&1)y=fa[y][i];
		puts((col[x] && col[x]==col[y])? "YES":"NO");
	}
	return 0;
}