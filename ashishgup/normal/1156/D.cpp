#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

struct DSU
{
	int connected;
	int par[N], sz[N];

	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

int n;
vector<pair<int, int> > g[N];
DSU dsu0, dsu1;

int32_t main()
{
	IOS;
	cin >> n;
	dsu0.init(n + 5);
	dsu1.init(n + 5);
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		if(w == 0)
			dsu0.unite(u, v);
		if(w == 1)
			dsu1.unite(u, v);
	}
	set<int> vis0, vis1;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int rt0 = dsu0.getPar(i);
		if(vis0.find(rt0) == vis0.end())
		{
			vis0.insert(rt0);
			int sz = dsu0.getSize(i);
			ans += sz * (sz - 1);
		}
		int rt1 = dsu1.getPar(i);
		if(vis1.find(rt1) == vis1.end())
		{
			vis1.insert(rt1);
			int sz = dsu1.getSize(i);
			ans += sz * (sz - 1);
		}
		ans += (dsu1.getSize(i) - 1) * (dsu0.getSize(i) - 1);
	}
	cout << ans;
	return 0;
}