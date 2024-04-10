#include<bits/stdc++.h>
using namespace std;
int n,m,p,t,Test_num;
int deg[200002],a[200002];
vector<int> vec[200002];
queue<int> q;
inline void solve()
{
	scanf("%d%d",&n,&m),t=0;
	for(int i=1;i<=n;++i)vec[i].clear(),a[i]=0;
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),vec[x].push_back(y),++deg[y];
	for(int i=1;i<=n;++i)if(!deg[i])q.push(i);
	for(;q.size();)
	{
		p=q.front(),q.pop(),t+=(a[p]==2);
		for(int i=0,v;i<vec[p].size();++i)
		{
			if(!(--deg[v=vec[p][i]]))q.push(v);
			if(a[p]==1)a[v]=2;
			else if(!a[p] && !a[v])a[v]=1;
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=n;++i)if(a[i]==2)printf("%d ",i);
	puts("");
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}