#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, q, u, v, k, sz=0, num=0;
int st[21*N], lc[21*N], rc[21*N], a[N], root[N];


int build(int L, int R)
{
	int node=++sz;
	if(L==R)
		return node;
	int M=(L+R) >> 1;
	lc[node] = build(L, M);
	rc[node] = build(M+1, R);
	return node;
}

int update(int onode, int L, int R, int pos)
{
	int node=++sz;
	if(L==R)
	{
		st[node]=st[onode] + 1;
		return node;
	}
	lc[node] = lc[onode];
	rc[node] = rc[onode];
	int M=(L+R) >> 1;
	if(pos<=M)
		lc[node] = update(lc[onode], L, M, pos);
	else
		rc[node] = update(rc[onode], M+1, R, pos);
	st[node] = st[lc[node]] + st[rc[node]];
	return node;
}

int query(int lnode, int rnode, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 0;
	if(i<=L && R<=j)
	{
		return st[rnode] - st[lnode];
	}
	int M=(L+R) >> 1;
	return query(rc[lnode], rc[rnode], M+1, R, i, n) + query(lc[lnode], lc[rnode], L, M, i, n);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=min(n, a[i]);
	}
	num=n;
	root[0] = build(1, num);
	for(int i=1;i<=n;i++)
	{
		root[i] = update(root[i-1], 1, num, a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=i)
			continue;
		int cur=query(root[i], root[a[i]], 1, n, i, n);
		ans+=cur;
	}
	cout<<ans;
	return 0;
}