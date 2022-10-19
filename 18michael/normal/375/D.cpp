#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,edge_t=0,V_t=0,Mx=0;
int c[100002],la[100002]={},siz[100002]={},son[100002]={},ans[100002],V[100002]={},tim[100002]={},D[100002]={};
bool vis[100002]={};
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	int k,num;
};
vector<bbb> vec[100002];
inline bool cmp(bbb a,bbb b)
{
	return a.k<b.k? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=fa)
		{
			dfs(v,x),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int fa,int opt)
{
	if(!vis[x])
		for(int i=la[x],v;i;i=edge[i].nx)
			if((v=edge[i].to)!=fa && v!=son[x])
				dfs1(v,x,0);
	if(son[x])dfs1(son[x],x,1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=fa && v!=son[x])
			dfs1(v,x,1);
	if(!tim[c[x]])V[++V_t]=c[x];
	++D[++tim[c[x]]];
	if(tim[c[x]]>Mx)Mx=tim[c[x]];
	if(!vis[x])
	{
		vis[x]=1;
		for(int i=0;i<vec[x].size();++i)ans[vec[x][i].num]=D[vec[x][i].k];
	}
	if(!opt)
	{
		for(int i=1;i<=V_t;++i)tim[V[i]]=0;
		for(int i=1;i<=Mx;++i)D[i]=0;
		V_t=Mx=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[x].push_back((bbb){y,i});
	dfs(1,1),dfs1(1,1,1);
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}