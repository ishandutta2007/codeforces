#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=0,sq,sq1;
int la[100002]={},dep[100002],fa[100002];
vector<int> vec[322];
struct aaa
{
	int to,nx;
}edge[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline bool dfs(int x,int d)
{
	dep[x]=d,vec[d%sq].push_back(x);
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!dep[v=edge[i].to])
		{
			fa[v]=x;
			if(dfs(v,d+1))return 1;
		}
		else if(dep[x]-dep[v]+1>=sq1)
		{
			for(puts("2");;x=fa[x])
			{
				vec[sq].push_back(x);
				if(x==v)break;
			}
			printf("%d\n",vec[sq].size());
			for(int j=0;j<vec[sq].size();++j)printf("%d ",vec[sq][j]);
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m),sq=sqrt(n),sq1=sq+(sq*sq<n);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	if(!dfs(1,1))
	{
		for(int i=0;;++i)
			if(vec[i].size()>=sq1)
			{
				puts("1");
				for(int j=0;j<sq1;++j)printf("%d ",vec[i][j]);
				break;
			}
	}
	return 0;
}