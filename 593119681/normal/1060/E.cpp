#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 524288 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, L[N], R[N];
vector <int> Vec[N];
LL ans;

struct SegmentTree
{
	int cnt1, del;
	LL sum;
}h[M];

void apply(int x, int l, int r, int k)
{
	h[x].del += k;
	h[x].sum += 1LL * (r - l + 1) * (k >> 1);
	if (k & 1)
	{
		h[x].cnt1 = (r - l + 1) - h[x].cnt1;
		h[x].sum += h[x].cnt1;
	}
}

void push(int x, int l, int r)
{
	if (h[x].del)
	{
		int mid = l + r >> 1;
		apply(ls(x), l, mid, h[x].del);
		apply(rs(x), mid + 1, r, h[x].del);
		h[x].del = 0;
	}
}

void update(int x)
{
	h[x].sum = h[ls(x)].sum + h[rs(x)].sum;
	h[x].cnt1 = h[ls(x)].cnt1 + h[rs(x)].cnt1;
}

void Modify(int x, int l, int r, int s, int t, int k)
{
	if (l == s && r == t)
	{
		apply(x, l, r, k);
		return ;
	}
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t, k);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t, k);
	else Modify(ls(x), l, mid, s, mid, k), Modify(rs(x), mid + 1, r, mid + 1, t, k);
	update(x);
}

void dfs(int z, int dep, int fa)
{
	static int id = 0;
	L[z] = ++ id;
	Modify(1, 1, n, id, id, dep);
	for (int d : Vec[z])
		if (d != fa)
			dfs(d, dep + 1, z);
	R[z] = id;
}

void dfs(int z, int fa)
{
	ans += h[1].sum;
	for (int d : Vec[z])
		if (d != fa)
		{
			Modify(1, 1, n, 1, n, 1);
			Modify(1, 1, n, L[d], R[d], -2);
			dfs(d, z);
			Modify(1, 1, n, 1, n, -1);
			Modify(1, 1, n, L[d], R[d], 2);
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(1, 0, 0);
	dfs(1, 0);
	printf("%lld\n", ans / 2);
	return 0;
}