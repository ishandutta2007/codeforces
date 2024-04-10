#include <cstdio>
#include <algorithm>
using namespace std;

#define V first
#define I second

const int MAXN = 111111;

int n, m, k, v;
int ans, x, y;
pair <int, int> a[MAXN], b[MAXN];
int sa[MAXN], sb[MAXN];

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d %d", &k, &v);
	for (int i = 1; i <= k; i++)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			n++;
			scanf("%d", &a[n].V);
			a[n].I = i;
		}
		else
		{
			m++;
			scanf("%d", &b[m].V);
			b[m].I = i;
		}
	}

	if (n) sort(a + 1, a + n + 1);
	if (m) sort(b + 1, b + m + 1);
	reverse(a + 1, a + n + 1);
	reverse(b + 1, b + m + 1);

	sa[0] = 0;
	for (int i = 1; i <= n; i++)
		sa[i] = sa[i - 1] + a[i].V;


	sb[0] = 0;
	for (int i = 1; i <= m; i++)
		sb[i] = sb[i - 1] + b[i].V;


	x = 0;
	y = 0;
	ans = 0;
	for (int i = 0; i <= m && 2 * i <= v; i++)
		if (sb[i] + sa[min(v - 2 * i, n)] > ans)
		{
			ans = sb[i] + sa[min(v - 2 * i, n)];
			x = i;
			y = min(v - 2 * i, n);
		}

	printf("%d\n", ans);
	for (int i = 1; i <= x; i++)
		printf("%d ", b[i].I);
	for (int i = 1; i <= y; i++)
		printf("%d ", a[i].I);

	printf("\n");
	return 0;
}