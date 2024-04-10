#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

struct DSU
{
	int connected;
	int par[N], sz[N];

	DSU() {} 

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
DSU dsu;
vector<pair<int, int> > rem;
vector<pair<int, int> > add;

int32_t main()
{
	IOS;
	cin >> n;
	dsu.init(n);
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		if(dsu.getPar(u) == dsu.getPar(v))
			rem.push_back({u, v});
		else
			dsu.unite(u, v);
	}
	vector<int> temp;
	for(int i = 1; i <= n; i++)
		if(dsu.getPar(i) == i)
			temp.push_back(i);
	int ans = temp.size() - 1;
	cout << ans << endl;
	for(int i = 0; i < ans; i++)
		cout << rem[i].first << " " << rem[i].second << " " << temp[i] << " " << temp[i + 1] << endl;
	return 0;
}