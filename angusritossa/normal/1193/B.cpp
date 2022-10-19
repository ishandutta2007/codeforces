#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node
{
	ll val, lzadd, mx;
	int left, right;
};
Node rangetree[20000000];
int upto;
void push(int curr)
{
	if (!rangetree[curr].left) rangetree[curr].left = ++upto;
	if (!rangetree[curr].right) rangetree[curr].right = ++upto;
	rangetree[rangetree[curr].right].val += rangetree[curr].lzadd;
	rangetree[rangetree[curr].left].val += rangetree[curr].lzadd;
	rangetree[rangetree[curr].right].mx += rangetree[curr].lzadd;
	rangetree[rangetree[curr].left].mx += rangetree[curr].lzadd;
	rangetree[rangetree[curr].right].lzadd += rangetree[curr].lzadd;
	rangetree[rangetree[curr].left].lzadd += rangetree[curr].lzadd;
	rangetree[rangetree[curr].right].mx = max(rangetree[rangetree[curr].right].mx, rangetree[curr].mx);
	rangetree[rangetree[curr].left].mx = max(rangetree[rangetree[curr].left].mx, rangetree[curr].mx);
	rangetree[rangetree[curr].right].val = max(rangetree[rangetree[curr].right].mx, rangetree[rangetree[curr].right].val);
	rangetree[rangetree[curr].left].val = max(rangetree[rangetree[curr].left].mx, rangetree[rangetree[curr].left].val);
	rangetree[curr].lzadd = 0;
}
void update(int s, int e, ll valadd, ll valmx, int curr, int cstart = 0, int cend = 100000)
{
	if (s <= cstart && cend <= e)
	{
		rangetree[curr].lzadd += valadd;
		rangetree[curr].val += valadd;
		rangetree[curr].mx += valadd;
		rangetree[curr].mx = max(rangetree[curr].mx, valmx);
		rangetree[curr].val = max(rangetree[curr].val, rangetree[curr].mx);
		return;
	}
	int mid = (cstart+cend)/2;
	push(curr);
	if (e <= mid) update(s, e, valadd, valmx, rangetree[curr].left, cstart, mid);
	else if (s > mid) update(s, e, valadd, valmx, rangetree[curr].right, mid+1, cend);
	else
	{
		update(s, e, valadd, valmx, rangetree[curr].left, cstart, mid);
		update(s, e, valadd, valmx, rangetree[curr].right, mid+1, cend);
	}
}
ll query(int node, int curr, int cstart = 0, int cend = 100000)
{
	if (cstart == cend) return rangetree[curr].val;
	int mid = (cstart+cend)/2;
	push(curr);
	if (node <= mid) return query(node, rangetree[curr].left, cstart, mid);
	else return query(node, rangetree[curr].right, mid+1, cend);
}
vector<int> adj[100010];
ll val[100010];
int day[100010], n, m, k;
vector<int> updatesapplied[100010];
int dothing(int a)
{
	int root = ++upto;
	for (auto b : adj[a])
	{
		int nr = dothing(b);
		if (updatesapplied[b].size() > updatesapplied[a].size())
		{
			swap(root, nr);
			updatesapplied[a].swap(updatesapplied[b]);
		}
		sort(updatesapplied[b].begin(), updatesapplied[b].end());
		for (int i = 0; i < updatesapplied[b].size(); i++)
		{
			int c = updatesapplied[b][i];
			int end = 100000;
			if (i+1 != updatesapplied[b].size()) end = updatesapplied[b][i+1]-1;
			if (end >= c)
			{
				ll q = query(c, nr);
				update(c, end, q, 0, root);
				updatesapplied[a].push_back(c);
			}
		}
	}
	ll q = query(day[a], root);
	q += val[a];
	update(day[a], 100000, 0, q, root);
	updatesapplied[a].push_back(day[a]);
	return root;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		adj[a].push_back(i+1);
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		scanf("%d%lld", &day[a], &val[a]);
	}
	int root = dothing(1);
	ll ans = query(100000, root);
	printf("%lld\n", ans);
}