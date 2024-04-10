#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, m, tim=1;
int a[N], level[N], discovery[N], begin1[N], end1[N], st[4*N], lazy[4*N];
vector<int> g[N];

void propagate(int node, int L, int R)
{
	if(L!=R)
	{
		lazy[node*2]+=1;
		lazy[node*2]%=2;
		lazy[node*2+1]+=1;
		lazy[node*2+1]%=2;
	}
	lazy[node]=0;
	st[node]=(R-L+1)-st[node];
}

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[discovery[L]];
		return;
	}
	int M=(L+R)>>1;
	build(node*2, L, M);
	build(node*2 + 1, M+1, R);
	st[node]=st[node*2]+st[node*2+1];
}

void update(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		st[node]=(R-L+1)-(st[node]);
		if(L!=R)
		{
			lazy[node*2]+=1;
			lazy[node*2 + 1]+=1;
			lazy[node*2]%=2;
			lazy[node*2 + 1]%=2;
		}
		return;
	}
	int M=(L+R)>>1;
	update(node*2, L, M, i, j);
	update(node*2 + 1, M+1, R, i, j);;
	st[node]=st[node*2]+st[node*2 + 1];
}

int query(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
	{
		return st[node];
	}
	int M=(L+R)>>1;
	return query(node*2, L, M, i, j) + query(node*2 + 1, M+1, R, i, j);
}

void dfs(int k, int par, int lvl)
{
	level[k]=lvl;
	level[k]%=2;
	discovery[tim]=k;
	begin1[k]=tim;
	tim++;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	end1[k]=tim-1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int u,v;
		u=i;
		cin>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1, 1, 1);
	build(1, 1, n);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string type;
		cin>>type;
		if(type=="pow")
		{
			int x;
			cin>>x;
			update(1, 1, n, begin1[x], end1[x]);
		}
		else
		{
			int x;
			cin>>x;
			int ans=query(1, 1, n, begin1[x], end1[x]);
			cout<<ans<<endl;
		}
	}
	return 0;
}