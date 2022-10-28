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

#define x first
#define y second

int n;
int l[N], r[N];
DSU dsu;
map<int, vector<pair<int, int> > > m;
pair<pair<int, int>, int> a[N];

int32_t main()
{
	IOS;
	cin >> n;
	dsu.init(n);
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		a[i].x.x = l[i];
		a[i].x.y = r[i];
		a[i].y = i;
	}
	sort(a + 1, a + n + 1);
	multiset<pair<int, int> > s;
	map<int, vector<pair<int, int> > > rem;
	int edges = 0;
	for(int i = 1; i <= n; i++)
	{
		for(auto &it:rem[i])
			s.erase(s.find(it));
		auto it = s.lower_bound({a[i].x.x, 1});
		while(true && edges <= n - 1)
		{
			if(it == s.end())
				break;
			if(it -> first > a[i].x.y)
				break;
			dsu.unite(it -> second, i);
			edges++;
			it++;
		}
		s.insert({a[i].x.y, i});
		rem[a[i].x.y].push_back({a[i].x.y, i});
	}
	if(dsu.connected == 1 && edges == n - 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}