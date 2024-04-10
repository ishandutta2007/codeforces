#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,G,edge_t=0;
LL k,mnans=0,mxans=0,res;
int la[100002],siz[100002],mx[100002],dep[100002],t[100002],fa[100002];
bool u[100002],u2[100002];
typedef pair<int,int> P;
P p1,p2;
vector<P> vec[100002];
vector<int> Vec[100002];
set<P,greater<P> > s;
set<P,greater<P> >::iterator it;
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs(v,x),siz[x]+=siz[v],mx[x]=max(mx[x],siz[v]);
}
inline void dfs1(int x,int f)
{
	if((mx[x]=max(mx[x],n-siz[x]))<mx[G])G=x;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs1(v,x);
}
inline void dfs2(int x,int f)
{
	siz[x]=1,fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dep[v]=dep[x]+1,dfs2(v,x),siz[x]+=siz[v],mnans+=(siz[v]&1),mxans+=siz[v];
}
inline void dfs3(int x,int f,int y)
{
	int z=0;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs3(v,x,y);
			if(!u[v])
			{
				if(!z)z=v;
				else vec[y].push_back(P(z,v)),u[z]=u[v]=1,z=0;
			}
		}
	if(z)vec[y].push_back(P(z,x)),u[z]=u[x]=1;
}
inline void dfs4(int x,int f,int y)
{
	if(!u2[x])Vec[y].push_back(x);
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)dfs4(v,x,y);
}
inline int LCA(int x,int y)
{
	return dep[x]==dep[y]? fa[x]:(dep[x]>dep[y]? y:x);
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0),dfs1(G=1,0),dfs2(G,0);
	if(k<mnans || k>mxans || ((res=mxans-k)&1))return 0&puts("NO");
	puts("YES");
	for(int i=la[G],v;i;i=edge[i].nx)
	{
		v=edge[i].to,dfs3(v,G,v);
		if(siz[v]>1)s.insert(P(siz[v],v));
	}
	for(int x,y,z,w,a;res;)
	{
		it=s.begin(),a=(*it).first,x=(*it).second,s.erase(it),w=LCA(y=vec[x][t[x]].first,z=vec[x][t[x]].second);
		if(dep[w]*2<=res)
		{
			printf("%d %d\n",y,z),u2[y]=u2[z]=1,++t[x],res-=dep[w]*2;
			if(a>3)s.insert(P(a-2,x));
			continue;
		}
		for(;dep[w]*2>res;w=fa[w]);
		printf("%d %d\n",y,w),u2[y]=u2[w]=1;
		break;
	}
	s.clear();
	for(int i=la[G],v;i;i=edge[i].nx)
	{
		v=edge[i].to,dfs4(v,G,v);
		if(Vec[v].size())s.insert(P(Vec[v].size(),v));
	}
	for(Vec[G].push_back(G),s.insert(P(1,G));s.size();)
	{
		p1=(*s.begin()),s.erase(s.begin()),p2=(*s.begin()),s.erase(s.begin()),printf("%d %d\n",Vec[p1.second].back(),Vec[p2.second].back()),Vec[p1.second].pop_back(),Vec[p2.second].pop_back();
		if(--p1.first)s.insert(p1);
		if(--p2.first)s.insert(p2);
	}
	return 0;
}