#include<cstdio>
#include<vector>
using namespace std;
int n,m,n1,n2,n3,edge_t=0,rt_t=0,ok=0;
int la[5002]={},rt[5002],col[5002];
int cnt[5002][2]={};
vector<int> vec[5002];
struct aaa
{
	int to,nx;
}edge[200002];
struct bbb
{
	bool val,from;
}f[5002][5002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int y)
{
	++cnt[rt[x]=rt_t][col[x]=y],vec[rt_t].push_back(x);
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!rt[v=edge[i].to])dfs(v,(y^1));
		else if(col[v]!=(y^1))ok=1;
	}
}
inline void work(int x,int y)
{
	if(!x)return ;
	int c=f[x][y].from;
	work(x-1,y-cnt[x][c]);
	for(int i=0,v;i<vec[x].size();++i)
	{
		if(col[v=vec[x][i]]==c)col[v]=2;
		else if(n1)col[v]=1,--n1;
		else col[v]=3,--n3;
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&n1,&n2,&n3);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)
		if(!rt[i])
		{
			++rt_t,dfs(i,0);
			if(ok)return 0&puts("NO");
		}
	f[0][0].val=1;
	for(int i=1;i<=rt_t;++i)
		for(int j=0;j<=n;++j)
		{
			if(j>=cnt[i][0] && f[i-1][j-cnt[i][0]].val)f[i][j]=(bbb){1,0};
			else if(j>=cnt[i][1] && f[i-1][j-cnt[i][1]].val)f[i][j]=(bbb){1,1};
			else f[i][j]=(bbb){0,0};
		}
	if(!f[rt_t][n2].val)return 0&puts("NO");
	puts("YES"),work(rt_t,n2);
	for(int i=1;i<=n;++i)printf("%d",col[i]);
	return 0;
}