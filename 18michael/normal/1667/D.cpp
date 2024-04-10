#include<bits/stdc++.h>
using namespace std;
int n,Test_num,edge_t,e_t,p;
bool ok;
int la[200002],lae[200002],X[200002],Y[200002],deg[200002];
vector<int> vec[200002][2];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[400002],e[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t,++deg[y];
}
inline void dfs(int x,int f)
{
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x),vec[x][vec[v][0].size()>=vec[v][1].size()].push_back(i>>1),vec[v][vec[v][0].size()>=vec[v][1].size()].push_back(i>>1);
	if(vec[x][0].size()+2<vec[x][1].size() || vec[x][0].size()>vec[x][1].size()+1)ok=0;
}
inline void Topo()
{
	for(int i=1;i<n;++i)if(!deg[i])q.push(i);
	while(!q.empty())
	{
		p=q.front(),printf("%d %d\n",X[p],Y[p]),q.pop();
		for(int i=lae[p],v;i;i=e[i].nx)if(!(--deg[v=e[i].to]))q.push(v);
	}
}
inline void solve()
{
	scanf("%d",&n),edge_t=ok=e_t=1;
	for(int i=1;i<=n;++i)la[i]=lae[i]=deg[i]=0,vec[i][0].clear(),vec[i][1].clear();
	for(int i=1;i<n;++i)scanf("%d%d",&X[i],&Y[i]),add_edge(X[i],Y[i]);
	dfs(1,0),ok&=(vec[1][0].size()+1>=vec[1][1].size() && vec[1][0].size()<=vec[1][1].size()),puts(ok? "YES":"NO");
	if(!ok)return ;
	for(int i=1,i0,i1;i<=n;++i)for(p=vec[i][i1=(i0=(vec[i][1].size()==vec[i][0].size()))^1].back(),vec[i][i1].pop_back();!vec[i][i0].empty();i0^=1,i1^=1)add_e(p,vec[i][i0].back()),p=vec[i][i0].back(),vec[i][i0].pop_back();
	Topo();
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)solve();
	return 0;
}