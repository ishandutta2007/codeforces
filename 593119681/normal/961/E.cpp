#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 10000000 + 5

int n, tot, Root[N];
LL ans;

struct Segment_Tree
{
	int l, r, sum;
}h[M];

void Modify(int &x, int l, int r, int t, int k)
{
	h[++ tot] = h[x], x = tot;
	if (l == r)
	{
		h[x].sum += k;
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid) Modify(h[x].l, l, mid, t, k);
	else Modify(h[x].r, mid + 1, r, t, k);
	h[x].sum = h[h[x].l].sum + h[h[x].r].sum;
}

int Query(int x, int l, int r, int s, int t)
{
	if (!x) return 0;
	if (l == s && r == t) return h[x].sum;
	int mid = l + r >> 1;
	if (t <= mid) return Query(h[x].l, l, mid, s, t);
	else if (s > mid) return Query(h[x].r, mid + 1, r, s, t);
	else return Query(h[x].l, l, mid, s, mid) + Query(h[x].r, mid + 1, r, mid + 1, t);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		x = min(x, n);
		ans += Query(Root[min(i - 1, x)], 1, n, i, n);
		Root[i] = Root[i - 1];
		Modify(Root[i], 1, n, x, 1);
	}
	printf("%lld\n", ans);
	return 0;
}