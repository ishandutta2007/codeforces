#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, m, ans=0;
int a[N], b[N], l[N], r[N];
vector<int> out;
int st[4*N], st2[4*N], lazy[4*N], lazy2[4*N];
vector<int> strt[N], ed[N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[L];
		st2[node]=a[L];
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=min(st[node*2], st[node*2+1]);
	st2[node]=max(st2[node*2], st2[node*2+1]);
}

void propagate(int node, int L, int R)
{	
	if(L!=R)
	{
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	st[node]+=lazy[node];
	lazy[node]=0;
}

int query(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)/2;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return min(left, right);
}

void update(int node, int L, int R, int i, int j, int val)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		lazy[node]+=val;
		propagate(node, L, R);
		return;
	}
	int M=(L+R)/2;
	update(node*2, L, M, i, j, val);
	update(node*2 + 1, M+1, R, i, j, val);
	st[node]=min(st[node*2], st[node*2 + 1]);
}

void propagate2(int node, int L, int R)
{	
	if(L!=R)
	{
		lazy2[node*2]+=lazy2[node];
		lazy2[node*2+1]+=lazy2[node];
	}
	st2[node]+=lazy2[node];
	lazy2[node]=0;
}

int query2(int node, int L, int R, int i, int j)
{
	if(lazy2[node])
		propagate2(node, L, R);
	if(j<L || i>R)
		return -1e9;
	if(i<=L && R<=j)
		return st2[node];
	int M=(L+R)/2;
	int left=query2(node*2, L, M, i, j);
	int right=query2(node*2 + 1, M+1, R, i, j);
	return max(left, right);
}

void update2(int node, int L, int R, int i, int j, int val)
{
	if(lazy2[node])
		propagate2(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		lazy2[node]+=val;
		propagate2(node, L, R);
		return;
	}
	int M=(L+R)/2;
	update2(node*2, L, M, i, j, val);
	update2(node*2 + 1, M+1, R, i, j, val);
	st2[node]=max(st2[node*2], st2[node*2 + 1]);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1, 1, n);
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i];
		update(1, 1, n, l[i], r[i], -1);
		update2(1, 1, n, l[i], r[i], -1);
		strt[l[i]].push_back(r[i]);
		ed[r[i]].push_back(l[i]);
	}
	int best=0;
	for(int i=1;i<=n;i++)
	{
		for(auto &it:strt[i])
		{
			update(1, 1, n, i, it, +1);
			update2(1, 1, n, i, it, +1);
		}
		int mn=query(1, 1, n, 1, n);
		int mx=query2(1, 1, n, 1, n);
		if(mx-mn>ans)
			best=i;
		ans=max(ans, mx-mn);
		for(auto &it:ed[i])
		{
			update(1, 1, n, it, i, -1);
			update2(1, 1, n, it, i, -1);
		}
	}
	if(best!=0)
	{
		for(int i=1;i<=m;i++)
		{
			if(best>=l[i] && best<=r[i])
				continue;
			out.push_back(i);
		}
	}
	cout<<ans<<endl;
	cout<<out.size()<<endl;
	for(auto &it:out)
		cout<<it<<" ";
	return 0;
}