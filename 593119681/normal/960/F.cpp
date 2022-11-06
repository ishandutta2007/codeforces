#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define LIM 100000
#define M 10000000 + 5

int n, m, tot, ans, Root[N];

struct Segment_Tree
{
	int l, r, Max;
}h[M];

void Modify(int &x, int l, int r, int t, int k)
{
	if (!x) h[++ tot] = h[x], x = tot;
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
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i <= m; i ++)
	{
		scanf("%d%d%d", &u, &v, &w);
		if (w == 0)
		{
			Modify(Root[v], 0, LIM, 0, 1);
			ans = max(ans, 1);
		}
		else
		{
			int _u = Query(Root[u], 0, LIM, 0, w - 1) + 1;
			ans = max(ans, _u);
			Modify(Root[v], 0, LIM, w, _u);
		}
	}
	printf("%d\n", ans);
	return 0;
}