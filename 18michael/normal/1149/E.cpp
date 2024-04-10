#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=0,p;
int la[200002],h[200002],deg[200002],cnt[200002],val[200002],sg[200002];
queue<int> q;
vector<int> vec;
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
}
inline void Topo()
{
	for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
	for(;q.size();)
	{
		vec.push_back(p=q.front()),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)if(!(--deg[v=edge[i].to]))q.push(v);
	}
	for(;vec.size();sg[val[vec.back()]]^=h[vec.back()],vec.pop_back())
	{
		for(int i=la[vec.back()];i;i=edge[i].nx)++cnt[val[edge[i].to]];
		for(;cnt[val[vec.back()]];++val[vec.back()]);
		for(int i=la[vec.back()];i;i=edge[i].nx)--cnt[val[edge[i].to]];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	Topo();
	for(int i=n;~i;--i)
		if(sg[i])
		{
			puts("WIN");
			for(int j=1;j<=n;++j)
				if(val[j]==i && (h[j]^sg[i])<h[j])
				{
					h[j]^=sg[i];
					for(int k=la[j],v;k;k=edge[k].nx)v=edge[k].to,h[v]^=sg[val[v]],sg[val[v]]=0;
					break;
				}
			for(int j=1;j<=n;++j)printf("%d ",h[j]);
			return 0;
		}
	return 0&puts("LOSE");
}