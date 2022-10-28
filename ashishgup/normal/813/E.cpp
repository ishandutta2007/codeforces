#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5+5;

int n, k, q, ct=0, last=0;
int a[2*N], root[2*N], storeind[2*N];
int st[40*N], lc[40*N], rc[40*N];
vector<int> ind[N];

int build(int L, int R)
{
	int node = ++ct;
	if(L==R)
		return node;
	int M = (L+R)/2;
	lc[node] = build(L, M);
	rc[node] = build(M+1, R);
	return node;
}

int update(int onode, int L, int R, int pos, int val)
{
	int node = ++ct;
	if(L==R)
	{
		st[node] = st[onode] + val;
		return node;
	}
	int M = (L+R)/2;
	lc[node] = lc[onode];
	rc[node] = rc[onode];
	if(pos<=M)
		lc[node] = update(lc[onode], L, M, pos, val);
	else
		rc[node] = update(rc[onode], M+1, R, pos, val);
	st[node] = st[lc[node]] + st[rc[node]];
	return node;
}

int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
		return st[node];
	int M = (L+R)/2;
	return query(lc[node], L, M, i, j) + query(rc[node], M+1, R, i, j);
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		storeind[i] = -1;
		int sz = ind[a[i]].size();
		if(sz>=k)
			storeind[i]=ind[a[i]][sz-k];
		ind[a[i]].push_back(i);
	}
	cin>>q;
	root[0]=build(1, N);
	for(int i=1;i<=n;i++)
	{
		root[i]=update(root[i-1], 1, N, i, 1);
		if(storeind[i]!=-1)
			root[i]=update(root[i], 1, N, storeind[i], -1);
	}
	for(int i=1;i<=q;i++)
	{
		int x, y;
		cin>>x>>y;
		int l = 1 + (x + last)%n;
		int r = 1 + (y + last)%n;
		if(l>r)
			swap(l, r);
		last=query(root[r], 1, N, l, r);
		cout<<last<<endl;
	}
	return 0;
}