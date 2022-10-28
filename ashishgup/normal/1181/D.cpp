#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 6e5 + 5;

int ct=0, num=0;
int root[N], st[21 * N], lc[21 * N], rc[21 * N];

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

int update(int onode, int L, int R, int pos)
{
	int node = ++ct;
	if(L == R)
	{
		st[node] = st[onode] + 1;
		return node;
	}
	int M = (L+R)/2;
	lc[node] = lc[onode];
	rc[node] = rc[onode];
	if(pos <= M)
		lc[node] = update(lc[onode], L, M, pos);
	else
		rc[node] = update(rc[onode], M+1, R, pos);
	st[node] = st[lc[node]] + st[rc[node]];
	return node;
}

int query(int nodeu, int nodev, int L, int R, int pos)
{
	if(L == R)
		return L;
	int M = (L+R)/2;
	int leftval = st[lc[nodev]] - st[lc[nodeu]];
	int rightval = st[rc[nodev]] - st[rc[nodeu]];
	if(leftval >= pos)
		return query(lc[nodeu], lc[nodev], L, M, pos);
	else
		return query(rc[nodeu], rc[nodev], M+1, R, pos - leftval);
}

int n, m, q;
int a[N], f[N];
int store[N], pref[N];
vector<int> g[N];

int32_t main()
{
	IOS;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	for(int i = 1; i <= m; i++)
		g[f[i]].push_back(i);
	root[0] = build(1, m);
	int cur = 0;
	for(int i = 0; i <= n; i++)
	{
		for(auto &it:g[i])
		{
			++cur;
			root[cur] = update(root[cur - 1], 1, m, it);
		}
	}
	store[0] = g[0].size();
	pref[0] = store[0];
	for(int i = 1; i <= n; i++)
	{
		store[i] = store[i - 1] + g[i].size();
		pref[i] = pref[i - 1] + store[i];
	}
	while(q--)
	{
		int k;
		cin >> k;
		k -= n;
		auto it = lower_bound(pref, pref + n, k) - pref;
		int left = k;
		if(it >= 1)
			left -= pref[it - 1];
		int have = store[it];
		left %= have;
		if(left == 0)
			left = have;
		int ans = query(0, root[have], 1, m, left);
		cout << ans << endl;
	}
	return 0;
}