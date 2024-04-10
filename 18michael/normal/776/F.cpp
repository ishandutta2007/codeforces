#include<bits/stdc++.h>
using namespace std;
int n,m,vec_t=0,st_t=0,edge_t=0,G,tot;
int st[100002],id[100002],la[100002],siz[100002],mx[100002],col[100002];
vector<int> to[100002],vec[100002];
typedef pair<int,int> P;
map<P,int> mp;
struct aaa
{
	int to,nx;
}edge[200002];
inline bool cmp(int x,int y)
{
	for(int i=0;;++i)if(vec[x][i]^vec[y][i])return vec[x][i]<vec[y][i];
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
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
inline void dfs2(int x,int f,int c,int c1)
{
	col[x]=c1;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && col[v]==c)dfs2(v,x,c,c1);
}
inline void solve(int x,int c)
{
	int g;
	dfs(x,0),tot=siz[x],dfs1(G=x,0),g=G;
	for(int i=la[g],v;i;i=edge[i].nx)if(col[v=edge[i].to]==c)dfs2(v,g,c,c+1),solve(v,c+1);
}
int main()
{
	scanf("%d%d",&n,&m),to[n].push_back(1);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		if(x<y)swap(x,y);
		to[x].push_back(y);
	}
	for(int i=1;i<=n;st[++st_t]=i,++i)for(sort(to[i].begin(),to[i].end());to[i].size();vec[vec_t].push_back(to[i].back()),to[i].pop_back())for(vec[++vec_t].push_back(i);st[st_t]!=to[i].back();--st_t)vec[vec_t].push_back(st[st_t]);
	for(int i=1;i<=vec_t;++i)id[i]=i;
	sort(id+1,id+vec_t+1,cmp);
	for(int i=1,x,y;i<=vec_t;++i)
		for(int j=0;j<vec[id[i]].size();++j)
		{
			if(!j)x=vec[id[i]][0],y=vec[id[i]][vec[id[i]].size()-1];
			else x=vec[id[i]][j-1],y=vec[id[i]][j];
			if(!mp.count(P(x,y)))mp[P(x,y)]=i;
			else add_edge(i,mp[P(x,y)]);
		}
	solve(1,0);
	for(int i=1;i<=vec_t;++i)printf("%d ",col[i]+1);
	return 0;
}