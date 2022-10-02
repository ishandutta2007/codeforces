#include <bits/stdc++.h>
#define int long long
using namespace std;
int deg[20005],fa[20005],vis[20005];
int ff(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=ff(fa[x]);
}
void solve()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) cin >> deg[i];
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		pair<int,int> mx={-1,0};
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]) mx=max(mx,{deg[j],j});
		}
		vis[mx.second]=1;
		for(int j=1;j<=deg[mx.second];j++)
		{
			cout << "? " << mx.second << "\n";
			fflush(stdout);
			int x;
			cin >> x;
			fa[ff(mx.second)]=ff(x);
			if(vis[x])
				break;
			vis[x]=1;
		}
	}
	cout << "! ";
	for(int i=1;i<=n;i++)
	{
		cout << ff(i) << " ";
	}
	cout << "\n";
	fflush(stdout);
}
signed main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	return 0;
}