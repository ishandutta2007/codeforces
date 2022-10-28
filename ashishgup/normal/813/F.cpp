#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
 
struct DSU
{
	int connected;
	int sz[N];
	pair<int, int> par[N]; //stores <parent, parity of distance from parent>
	vector<int> changes;

	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]={i, 0};
			sz[i]=1;
		}
		connected=n;
	}

	pair<int, int> getPar(int x)
	{
		if(par[x].first==x)
			return par[x];
		pair<int, int> p = getPar(par[x].first);
		p.second ^= par[x].second;
		return p;
	}

	bool unite(int u, int v) //Returns 1 if the graph is no longer bipartite
	{
		pair<int, int> x=getPar(u), y=getPar(v);
		if(x.first==y.first)
		{
			if(x.second==y.second)
				return 1;
			changes.push_back(-1);
			return 0;
		}

		connected--;

		if(sz[x.first] < sz[y.first])
			swap(x, y);
		par[y.first]={x.first, 1^x.second^y.second};
		sz[x.first]+=sz[y.first];
		changes.push_back(y.first);
		return 0;
	}

	void undo() //Reversed the previous performed operation
	{
		if(!changes.size())
			return;
		if(changes.back()!=-1)
		{
			int x=changes.back();
			sz[par[x].first]-=sz[x];
			par[x]={x, 0};
		}
		changes.pop_back();
	}
};

int n, q;
bool ans[4*N];
vector<pair<int, int> > upd[4*N];
map<pair<int, int>, int> m;
DSU dsu;

void insert(int node, int L, int R, int i, int j, int x, int y)
{
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		upd[node].push_back({x, y});
		return;
	}
	int M=(L+R)/2;
	insert(node*2, L, M, i, j, x, y);
	insert(node*2 + 1, M+1, R, i, j, x, y);
}

void work(int node, int L, int R, bool bad)
{
	int cnt=0;
	if(!bad)
	{
		for(auto &it:upd[node])
		{
			if(dsu.unite(it.first, it.second))
			{
				bad=1;
				break;
			}
			cnt++;
		}
	}
	if(L==R)
		ans[L]=!bad;
	else
	{
		int M=(L+R)/2;
		work(node*2, L, M, bad);
		work(node*2+1, M+1, R, bad);
	}
	while(cnt--)
		dsu.undo();
}

int32_t main()
{
	IOS;
	cin>>n>>q;
	dsu.init(n);
	for(int i=1;i<=q;i++)
	{
		int x, y;
		cin>>x>>y;
		if(m.count({x, y}))
		{
			insert(1, 1, q, m[{x, y}], i-1, x, y);
			m.erase({x, y});
		}
		else
			m[{x, y}]=i;
	}
	for(auto &it:m)
		insert(1, 1, q, it.second, q, it.first.first, it.first.second);
	work(1, 1, q, 0);
	for(int i=1;i<=q;i++)
		if(ans[i])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	return 0;
}