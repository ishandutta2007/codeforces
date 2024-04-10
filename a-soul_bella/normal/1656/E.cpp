#include <bits/stdc++.h>
#define int long long
using namespace std;
int dep[1000005],ans[1000005],sz[1000005],fa[1000005];
vector <int> e[1000005];
inline void dfs(int u,int f)
{
	fa[u]=f;
	sz[u]=0;
	for(auto v:e[u])
	{
		if(v==f) continue;
		dep[v]=dep[u]+1,dfs(v,u),sz[u]+=sz[v];
	}
	if(dep[u]==0) ans[u]=-sz[u],sz[u]=0;
	else if(dep[u]&1) ans[u]=1-sz[u],sz[u]=1;
	else ans[u]=-1-sz[u],sz[u]=-1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) e[i].clear(),ans[i]=sz[i]=dep[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}