#include<bits/stdc++.h>
using namespace std;
const int N=100005,P=1e9+7;
int n,m,cnt,vis[N*12],ans[N*12];vector<int>e[N*12][10];
inline void add(int u,int v,int w)
{
	for(;w>9;w/=10)e[++cnt][w%10].push_back(v),v=cnt;
	e[u][w].push_back(v);
}
inline void bfs()
{
	vector<vector<int> >Q1,Q2;
	vis[1]=1;Q1.push_back(vector<int>(1,1));
	while(!Q1.empty())
	{
		for(auto x:Q1)for(int w=0;w<10;w++)
		{
			vector<int>t(0);
			for(auto i:x)for(auto v:e[i][w])if(!vis[v]){vis[v]=1;ans[v]=(10ll*ans[i]+w)%P,t.push_back(v);}
			if(!t.empty())Q2.push_back(t);
		}
		Q1=Q2;Q2.clear();
	}
}
int main()
{
	scanf("%d%d",&n,&m);cnt=n;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),add(u,v,i),add(v,u,i);
	bfs();for(int i=2;i<=n;i++)printf("%d\n",ans[i]);return 0;
}