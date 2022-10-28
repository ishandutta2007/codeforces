#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

struct DSU
{
	int connected, left[N], right[N];
	int par[N], sz[N];

	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			left[i]=i;
			right[i]=i;
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
int deg[N], l[N], r[N];
DSU dsu;
deque<int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	dsu.init(n+5);
	for(int i=1;i<=n-1;i++)
	{
		int x, y;
		cin>>x>>y;
		int xLeft=dsu.left[dsu.getPar(x)];
		int yRight=dsu.right[dsu.getPar(y)];
		int xRight=dsu.right[dsu.getPar(x)];
		int yLeft=dsu.left[dsu.getPar(y)];
		if(l[xLeft]==0 && r[yRight]==0)
		{
			x=xLeft;
			y=yRight;
			dsu.unite(x, y);
			l[x]=y;
			r[y]=x;
			dsu.left[dsu.getPar(x)]=yLeft;
			dsu.right[dsu.getPar(x)]=xRight;
		}
		else
		{
			x=xRight;
			y=yLeft;
			dsu.unite(x, y);
			r[x]=y;
			l[y]=x;
			dsu.right[dsu.getPar(x)]=yRight;
			dsu.left[dsu.getPar(x)]=xLeft;
		}
	}
	int cur=1;
	ans.push_back(1);
	while(l[cur]>0)
	{
		cur=l[cur];
		ans.push_front(cur);
	}
	cur=1;
	while(r[cur]>0)
	{
		cur=r[cur];
		ans.push_back(cur);
	}
	while(!ans.empty())
	{
		cout<<ans.front()<<" ";
		ans.pop_front();
	}
	return 0;
}