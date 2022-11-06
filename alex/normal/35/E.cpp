#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

double const pi = 3.1415926535897932384626433832795;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define mp make_pair
#define fs first
#define sc second

int const NMAX = 300010;
int n, h[NMAX], tree[NMAX];
pii q[NMAX];
vector <pii> ans;

void paint(int &x1, int &y1, int x2, int y2)
{
	if (abs(x1 - x2) + abs(y1 - y2) == 0) return;
	if (ans.size() >= 2 && ans[ans.size() - 2].sc == y2 && ans[ans.size() - 1].sc == y2)
		ans[ans.size() - 1] = mp(x2, y2);
	else
		ans.pb(mp(x2, y2));
	x1 = x2, y1 = y2;
}

void update(int v, int l, int r, int p, int zn)
{
	if (p < l || p > r) return;
	if (l == r)
	{
		tree[v] = zn;
		return;
	}
	update(2 * v, l, (l + r) >> 1, p, zn);
	update(2 * v + 1, (l + r + 2) >> 1, r, p, zn);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n + 1)
		if (i)
		{
			int l, r;
			scanf("%d%d%d",  &h[i], &l, &r);
			q[i - 1] = mp(l, -i);
			q[n + i - 1] = mp(r, i);
		}

	sort(q, q + 2 * n);
	seta(tree, 0);
	int lx = q[0].fs - 1, ly = 0, i = 0;
	while (i < 2 * n)
	{
		int j = i;
		paint(lx, ly, q[j].fs, ly);
		while (i < 2 * n && q[i].sc < 0 && q[i].fs == q[j].fs)
		{
			update(1, 1, n, -q[i].sc, h[-q[i].sc]);
			i++;
		}
		while (i < 2 * n && q[i].sc > 0 && q[i].fs == q[j].fs)
		{
			update(1, 1, n, q[i].sc, 0);
			i++;
		}
		paint(lx, ly, lx, tree[1]);
	}

	cout << ans.size() << endl;
	forn(i, ans.size())
		printf("%d %d\n", ans[i].fs, ans[i].sc);

	return 0;
}