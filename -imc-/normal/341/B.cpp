#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int maxN = 100005;

int tree[maxN * 4];

int query (int t, int l, int r, int x, int y)
{
	if (x > r || y < l) return -1;

	if (l >= x && r <= y)
		return tree[t];

	int m = (l + r) / 2;
	return max (query (t * 2 + 1, l, m, x, y), query (t * 2 + 2, m + 1, r, x, y));
}

void update (int t, int l, int r, int index, int value)
{
	if (l == r)
	{
		tree[t] = value;
		return;
	}

	int m = (l + r) / 2;
	if (index <= m)
		update (t * 2 + 1, l, m, index, value);
	else
		update (t * 2 + 2, m + 1, r, index, value);

	tree[t] = max (tree[t * 2 + 1], tree[t * 2 + 2]);
}

int main()
{
	int n;
	scanf ("%d", &n);

	vector <int> a (n), d (n);

	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &a[i]);
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		d[i] = query (0, 0, n - 1, 0, a[i] - 1) + 1;
		update (0, 0, n - 1, a[i] - 1, d[i]);

		if (d[i] > ans)
			ans = d[i];
	}

	printf ("%d\n", ans);

	return 0;
}