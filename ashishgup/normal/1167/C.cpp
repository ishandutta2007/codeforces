#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

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

int n, m;
DSU dsu;

int32_t main()
{
	IOS;
	cin >> n >> m;
	dsu.init(n);
	for(int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		int prev = 1;
		for(int j = 1;j <= k; j++)
		{
			int x;
			cin >> x;
			if(j > 1)
				dsu.unite(prev, x);
			prev = x;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << dsu.getSize(i) << " " ;
	return 0;
}