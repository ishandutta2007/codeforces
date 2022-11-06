#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define M 20000000 + 5

int n, sz, tot, Max, A[N], B[N], T[N << 1], Root[N], Tree[N << 1];

struct Sement_Tree
{
	int l, r, Max;
}h[M];

void Add(int x, int op, int k)
{
	if (op) for (; x <= sz; x += (x & -x))
		Tree[x] = max(Tree[x], k);
	else for (; x; x -= (x & -x))
		Tree[x] = max(Tree[x], k);
}

int Calc(int x, int op)
{
	int res = 0;
	if (op) for (; x <= sz; x += (x & -x))
		res = max(res, Tree[x]);
	else for (; x; x -= (x & -x))
		res = max(res, Tree[x]);
	return res;
}

void Modify(int &x, int l, int r, int t, int k)
{
	h[++ tot] = h[x], x = tot;
	if (l == r)
	{
		h[x].Max = max(h[x].Max, k);
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid) Modify(h[x].l, l, mid, t, k);
	else Modify(h[x].r, mid + 1, r, t, k);
	h[x].Max = max(h[h[x].l].Max, h[h[x].r].Max);
}

int Query(int x, int l, int r, int s, int t)
{
	if (!x) return 0;
	if (l == s && r == t) return h[x].Max;
	int mid = l + r >> 1;
	if (t <= mid) return Query(h[x].l, l, mid, s, t);
	else if (s > mid) return Query(h[x].r, mid + 1, r, s, t);
	else return max(Query(h[x].l, l, mid, s, mid), Query(h[x].r, mid + 1, r, mid + 1, t));
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		A[i] -= i, T[i] = A[i];
		B[i] = A[i] + 1, T[i + n] = B[i];
	}
	sort(T + 1, T + 2 * n + 1);
	sz = unique(T + 1, T + 2 * n + 1) - T - 1;
	for (int i = 1; i <= n; i ++)
	{
		A[i] = lower_bound(T + 1, T + sz + 1, A[i]) - T;
		B[i] = lower_bound(T + 1, T + sz + 1, B[i]) - T;
	}
	for (int i = 1; i <= n; i ++)
	{
		int d = Calc(A[i], 0) + 1;
		Add(A[i], 1, d);
		Root[i] = Root[i - 1];
		Modify(Root[i], 1, sz, A[i], d);
	}
	for (int i = 1; i <= sz; i ++)
		Tree[i] = 0;
	Max = h[Root[n - 1]].Max;
	for (int i = n; i > 1; i --)
	{
		int d = Calc(B[i], 1) + 1;
		Add(B[i], 0, d);
		int tmp = Query(Root[i - 2], 1, sz, 1, B[i]);
		Max = max(Max, d + tmp);
	}
	printf("%d\n", n - 1 - Max);
	return 0;
}