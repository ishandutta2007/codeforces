#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=200005;
int n,m;
vector<int> e[N];
int f[N];//
bool vis[N];
int cnt;
vector<int> ans[N];
int find (int x){return f[x]==x?x:f[x]=find(f[x]);}
void dfs (int x)
{
	/*printf("%d\n",x);
	system("pause");*/
	vis[x]=true;
	ans[cnt].push_back(x);
	f[x]=x+1;
	int i=0;
	for (int u=find(1);u<=n;u=find(u+1))
	{
		while (i<e[x].size()&&e[x][i]<u) i++;
		if (i<e[x].size()&&e[x][i]==u) continue;
		dfs(u);
	}
}
int lalal[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);e[y].push_back(x);
	}
	for (int u=1;u<=n;u++) sort(e[u].begin(),e[u].end());
	memset(vis,false,sizeof(vis));
	for (int u=1;u<=n+1;u++) f[u]=u;
	for (int u=1;u<=n;u++)
		if (!vis[u])
		{
			cnt++;
			dfs(u);
		}
	printf("%d\n",cnt);
	for (int u=1;u<=cnt;u++)
		lalal[u]=ans[u].size();
	sort(lalal+1,lalal+1+cnt);
	for (int u=1;u<=cnt;u++)
		printf("%d ",lalal[u]);
	return 0;
}