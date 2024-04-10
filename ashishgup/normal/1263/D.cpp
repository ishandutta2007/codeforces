#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

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
DSU dsu;
set<int> s[26];

int32_t main()
{
	IOS;
	cin >> n;
	dsu.init(n);
	for(int i = 1; i <= n; i++)
	{	
		string str;
		cin >> str;
		for(auto &it:str)
			s[it - 'a'].insert(i);
	}
	for(int i = 0; i < 26; i++)
	{
		int prv = 0;
		for(auto &it:s[i])
		{
			if(prv)
				dsu.unite(prv, it);
			prv = it;
		}
	}
	cout << dsu.connected;
	return 0;
}