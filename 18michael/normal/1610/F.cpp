#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int u[600002];
typedef pair<int,int> P;
vector<P> vec[300002][2];
inline void dfs(int x,int o)
{
	int t;
	for(P p;!vec[x][0].empty() || !vec[x][1].empty();)
	{
		if(vec[x][o].size())p=vec[x][t=o].back(),vec[x][o].pop_back();
		else p=vec[x][t=o^1].back(),vec[x][o^1].pop_back();
		if(u[p.second>>1])continue;
		u[p.second>>1]=1+(p.second&1),dfs(p.first,t);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;++i)scanf("%d%d%d",&x,&y,&z),z=(z==1),vec[x][z].push_back(P(y,i<<1)),vec[y][z].push_back(P(x,(i<<1)|1));
	for(int i=1,o;i<=n;++i)
	{
		ans+=(o=(vec[i][1].size()&1));
		if((vec[i][0].size()+vec[i][1].size())&1)vec[i][o].push_back(P(0,(m+i)<<1)),vec[0][o].push_back(P(i,((m+i)<<1)|1));
	}
	printf("%d\n",ans);
	for(int i=0;i<=n;++i)dfs(i,0);
	for(int i=1;i<=m;++i)printf("%d",u[i]);
	return 0;
}