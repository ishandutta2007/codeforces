#include<cstdio>
#include<vector>
#define Mx 16
using namespace std;
int n,m,edge_t=0,dfn_t=0;
int la[100002]={},ans[100002],mx[100002],son[100002],top[100002],dfn[100002],cnt[100002];
int fa[100002][18];
vector<int> vec;
struct aaa
{
	int to,nx;
}edge[100002];
struct bbb
{
	int x,id;
};
vector<bbb> qry[100002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	mx[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		dfs(v=edge[i].to);
		if(mx[v]+1>mx[x])mx[x]=mx[v]+1,son[x]=v;
	}
}
inline void dfs1(int x)
{
	dfn[x]=(++dfn_t),++cnt[dfn[x]];
	if(son[x])dfs1(son[x]);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=son[x])
		{
			dfs1(v);
			for(int j=0;j<=mx[v];++j)cnt[dfn[x]+j+1]+=cnt[dfn[v]+j];
		}
	for(int i=0;i<qry[x].size();++i)ans[qry[x][i].id]=cnt[dfn[x]+qry[x][i].x]-1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&fa[i][0]);
		if(fa[i][0])add_edge(fa[i][0],i);
		else vec.push_back(i);
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=Mx;++j)fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&m);
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d%d",&x,&y),z=x;
		for(int j=Mx;~j;--j)if((y>>j)&1)z=fa[z][j];
		if(z)qry[z].push_back((bbb){y,i});
	}
	for(int i=0;i<vec.size();++i)dfs(vec[i]),dfs1(vec[i]);
	for(int i=1;i<=m;++i)printf("%d ",ans[i]);
	return 0;
}