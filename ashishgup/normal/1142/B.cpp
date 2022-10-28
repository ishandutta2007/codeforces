#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2e5 + 5;
const int LG = log2(N) + 1;
 
int n, m, q;
int p[N], a[N], b[N], st[4 * N];
int nxt[LG][N];
 
void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node] = b[L];
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=min(st[node*2], st[node*2+1]);
}
 
int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)/2;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return min(left, right);
}
 
int walkAhead(int u, int h)
{
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
			u = nxt[i][u];
	}
	return u;
}
 
void precompute()
{
	for(int i=1;i<LG;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(nxt[i-1][j])
				nxt[i][j] = nxt[i-1][nxt[i-1][j]];
		}
	}
}
 
void work()
{
	map<int, int> reqd;
	for(int i = 1; i <= n - 1; i++)
		reqd[p[i]] = p[i + 1];
	reqd[p[n]] = p[1];
	map<int, int> idx;
	for(int i = m; i >= 1; i--)
	{
		if(idx.find(reqd[a[i]]) != idx.end())
			nxt[0][i] = idx[reqd[a[i]]];
		idx[a[i]] = i;
	}
	precompute();
	for(int i = 1; i <= m; i++)
	{
		b[i] = walkAhead(i, n - 1);
		if(!b[i])
			b[i] = m + 1;
	}
	build(1, 1, m);
	for(int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		int ans = query(1, 1, m, l, r) <= r;
		cout << ans;
	}
}
 
int32_t main()
{
	IOS;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	work();
	return 0;
}