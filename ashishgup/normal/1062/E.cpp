
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
const int LG = log2(N) + 2;
 
int n, q;
vector<int> g[N];
int tim=0;
int parent[LG][N];
int tin[N], tout[N], level[N], rm[N];
 
void dfs(int k, int par, int lvl)
{
	tin[k]=++tim;
	rm[tim]=k;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
	tout[k]=tim;
}
 
void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}
 
int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}
 
int stmin[4 * N], st2min[4 * N];
 
void build(int node, int L, int R)
{
	if(L==R)
	{
		stmin[node]=tin[L];
		st2min[node]=L;
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	stmin[node]=min(stmin[node*2], stmin[node*2+1]);
	if(stmin[node]==stmin[node*2])
		st2min[node]=st2min[node*2];
	else
		st2min[node]=st2min[node*2+1];
}
 
pair<int, int> query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return make_pair(1e9, 0);
	if(i<=L && R<=j)
		return {stmin[node], st2min[node]};
	int M=(L+R)/2;
	pair<int, int> left=query(node*2, L, M, i, j);
	pair<int, int> right=query(node*2 + 1, M+1, R, i, j);
	if(left.first<right.first)
		return left;
	return right;
}
 
void update(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		stmin[node]=val;
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update(node*2, L, M, pos, val);
	else
		update(node*2 + 1, M+1, R, pos, val);
	stmin[node]=min(stmin[node*2], stmin[node*2 + 1]);
	if(stmin[node]==stmin[node*2])
		st2min[node]=st2min[node*2];
	else
		st2min[node]=st2min[node*2+1];
}
 
int stmax[4 * N], st2max[4 * N];
 
void build2(int node, int L, int R)
{
	if(L==R)
	{
		stmax[node]=tin[L];
		st2max[node]=L;
		return;
	}
	int M=(L+R)/2;
	build2(node*2, L, M);
	build2(node*2+1, M+1, R);
	stmax[node]=max(stmax[node*2], stmax[node*2+1]);
	if(stmax[node]==stmax[node*2])
		st2max[node]=st2max[node*2];
	else
		st2max[node]=st2max[node*2+1];
}
 
pair<int, int> query2(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return make_pair(-1e9, 0);
	if(i<=L && R<=j)
		return {stmax[node], st2max[node]};
	int M=(L+R)/2;
	pair<int, int> left=query2(node*2, L, M, i, j);
	pair<int, int> right=query2(node*2 + 1, M+1, R, i, j);
	if(left.first>right.first)
		return left;
	return right;
}
 
void update2(int node, int L, int R, int pos, int val)
{
	if(L==R)
	{
		stmax[node]=val;
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update2(node*2, L, M, pos, val);
	else
		update2(node*2 + 1, M+1, R, pos, val);
	stmax[node]=max(stmax[node*2], stmax[node*2 + 1]);
	if(stmax[node]==stmax[node*2])
		st2max[node]=st2max[node*2];
	else
		st2max[node]=st2max[node*2+1];
}
 
int32_t main()
{
	IOS;
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		g[i].push_back(p);
		g[p].push_back(i);
	}
	dfs(1, 1, 0);
	precompute();
	build(1, 1, n);
	build2(1, 1, n);
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		pair<int, int> p1=query(1, 1, n, l, r);
		pair<int, int> p2=query2(1, 1, n, l, r);
		int o1=p1.second;
		int o2=p2.second;
		update(1, 1, n, o1, 1e9);
		pair<int, int> p11=query(1, 1, n, l, r);
		update(1, 1, n, o1, tin[o1]);
		update2(1, 1, n, o2, 0);
		pair<int, int> p22=query2(1, 1, n, l, r);
		update2(1, 1, n, o2, tin[o2]);
		int n1=p11.second;
		int n2=p22.second;
		int LCA1=LCA(n1, o2);
		int LCA2=LCA(o1, n2);
		if(level[LCA1]>level[LCA2])
			cout<<o1<<" "<<level[LCA1]<<endl;
		else
			cout<<o2<<" "<<level[LCA2]<<endl;
	}
	return 0;
}