#include<bits/stdc++.h>
using namespace std;
int n,Test_num,edge_t,t;
int la[1000002];
bool vis[1000002];
vector<int> vec;
struct aaa
{
	int to,nx;
}edge[1000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	vis[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		if(!vis[v=edge[i].to])dfs(v);
		else t=v;
		if(!t)continue;
		if(~t)vec.push_back(x);
		if(t==x)t=-1;
		return ;
	}
}
inline void solve()
{
	scanf("%d",&n),edge_t=t=0,vec.clear();
	for(int i=1;i<=n;++i)la[i]=vis[i]=0;
	for(int i=1,x;i<=n;++i)scanf("%d",&x),add_edge(i,i-x);
	dfs(1),printf("%d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}