#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=4e5+5;

int n, m, tim=0;
int a[N], c[N], tin[N], tout[N];
int st[4*N], lazy[4*N];
vector<int> g[N];

void dfs(int k, int par)
{
	tin[k]=++tim;
	a[tim]=c[k];
	for(auto &it:g[k])
		if(it!=par)
			dfs(it, k);
	tout[k]=tim;
}

void propogate(int node, int L, int R)
{
	if(L!=R)
		lazy[node*2]=lazy[node*2+1]=lazy[node];
	st[node]=lazy[node];
	lazy[node]=0;
}

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[L];
		return;
	}
	int M=(L+R)>>1;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=st[node*2]|st[node*2+1];
}

void update(int node, int L, int R, int i, int j, int val)
{
	if(lazy[node])
		propogate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		st[node]=val;
		if(L!=R)
		{
			lazy[node*2]=val;
			lazy[node*2+1]=val;
		}
		return;
	}
	int M=(L+R)>>1;
	update(node*2, L, M, i, j, val);
	update(node*2+1, M+1, R, i, j, val);
	st[node]=st[node*2]|st[node*2+1];
}

int query(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propogate(node, L, R);
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)>>1;
	return query(node*2, L, M, i, j)|query(node*2+1, M+1, R, i, j);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		c[i]=(1LL<<c[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	build(1, 1, n);
	for(int i=1;i<=m;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int v, col;
			cin>>v>>col;
			col=(1LL<<col);
			update(1, 1, n, tin[v], tout[v], col);
		}
		else
		{
			int v;
			cin>>v;
			cout<<__builtin_popcountll(query(1, 1, n, tin[v], tout[v]))<<endl;
		}
	}
	return 0;
}