#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 3e5 + 5;
const int M = 5e5 + 5;

int n, m, q;
int a[N], u[N], v[N];
int stpar[M], st2[M];
set<pair<int, int> > store[M];

struct DSU
{
	int connected;
	vector<int> par, sz;
	vector<set<pair<int, int> > > s;

	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		s = vector<set<pair<int, int> > > (n + 1);
		for(int i = 1; i <= n; i++)
		{
			par[i] = i, sz[i] = 1;
			s[i].insert({a[i], i});
		}
		connected = n;
	}

	int getPar(int u)
	{
		if(u != par[u])
			return getPar(par[u]);
		return u;
	}

	int getSize(int u)
	{
		return sz[getPar(u)];
	}

	void getAns(int u)
	{
		int par = getPar(u);
		auto it = *s[par].rbegin();
		cout << it.first << endl;
		s[par].erase(it);
		a[it.second] = 0;
		s[par].insert({a[it.second], it.second});
	}

	void unite(int u, int v, int idx, int flag)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		for(auto &it:s[par1])
			s[par2].insert(it);
		if(flag)
		{
			stpar[idx] = par1;
			for(auto &it:s[par1])
				store[idx].insert(it);
			st2[idx] = par2;
		}
		par[par1] = par[par2];
	}
};

bool mark[N];
int type[M], storeq[M];
DSU dsu;

int32_t main()
{
	IOS;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dsu.init(n);
	for(int i = 1; i <= m; i++)
		cin >> u[i] >> v[i];
	for(int i = 1; i <= q; i++)
	{
		cin >> type[i] >> storeq[i];
		if(type[i] == 2)
			mark[storeq[i]] = 1;
	}
	for(int i = 1; i <= m; i++)
	{
		if(!mark[i])
			dsu.unite(u[i], v[i], 0, 0);
	}
	for(int i = q; i >= 1; i--)
	{
		if(type[i] == 2)
		{
			int idx = storeq[i];
			dsu.unite(u[idx], v[idx], i, 1);
		}	
	}
	for(int i = 1; i <= q; i++)
	{
		if(type[i] == 1)
			dsu.getAns(storeq[i]);
		else
		{
			dsu.par[stpar[i]] = stpar[i];
			int x = stpar[i];
			int y =  st2[i];
			dsu.s[x].clear();
			for(auto &it:store[i])
			{
				dsu.s[x].insert({a[it.second], it.second});
				dsu.s[y].erase({a[it.second], it.second});
			}
		}
	}
	return 0;
}