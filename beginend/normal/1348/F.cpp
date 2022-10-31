#include <bits/stdc++.h>
#define ls d << 1
#define rs d << 1 | 1
using namespace std;

const int N = 200005;

int n, ans[N], match[N];
struct seg{int tag, mn;}t[N * 4];
struct data{int l, r, id;}a[N];

void mark(int d, int w)
{
	t[d].tag += w; t[d].mn += w;
}

void pushdown(int d)
{
	int w = t[d].tag; t[d].tag = 0;
	mark(ls, w); mark(rs, w);
}

void ins(int d, int l, int r, int x, int y, int z)
{
	if (x <= l && r <= y) {mark(d, z);; return;}
	pushdown(d);
	int mid = (l + r) / 2;
	if (x <= mid) ins(ls, l, mid, x, y, z);
	if (y > mid) ins(rs, mid + 1, r, x, y, z);
	t[d].mn = min(t[ls].mn, t[rs].mn);
}

int get_pos(int d, int l, int r)
{
	if (l==r) return l;
	pushdown(d);
	int mid = (l + r) / 2;
	if (t[ls].mn == t[d].mn) return get_pos(ls, l, mid);
	else return get_pos(rs, mid + 1, r);
}

pair<int, int> get_pos(int d, int l, int r, int x, int y)
{
	if (l == r) return make_pair(t[d].mn, l);
	int mid = (l + r) / 2;
	if (x <= l && r <= y) return t[ls].mn == t[d].mn ? get_pos(ls, l, mid, x, y) : get_pos(rs, mid + 1, r, x, y);
	if (y <= mid) return get_pos(ls, l, mid, x, y);
	else if (x > mid) return get_pos(rs, mid + 1, r, x, y);
	else return min(get_pos(ls, l, mid, x, y), get_pos(rs, mid + 1, r, x, y));
}

void rebuild(int d, int l, int r)
{
	t[d].tag = 0;
	if (l == r) {t[d].mn = a[match[l]].l; return;}
	int mid = (l + r) / 2;
	rebuild(ls, l, mid);
	rebuild(rs, mid + 1, r);
	t[d].mn = min(t[ls].mn, t[rs].mn);
}

bool cmp(data a, data b)
{
	return a.l < b.l;
}

void pre()
{
	sort(a + 1, a + n + 1, cmp);
	set<pair<int, int> > se;
	int p = 1;
	for (int i = 1; i <= n; i++)
	{
		while (p <= n && a[p].l == i) se.insert(make_pair(a[p].r, p)), p++;
		match[i] = (*se.begin()).second;
		se.erase(se.begin());
	}
}

bool check()
{
	for (int i = 1; i <= n; i++) ins(1, 1, n, a[i].l, a[i].r, 1);
	for (int i = 1; i <= n; i++)
	{
		if (t[1].mn != 1) return 0;
		int pos = get_pos(1, 1, n);
		ins(1, 1, n, a[match[pos]].l, a[match[pos]].r, -1);
		ins(1, 1, n, pos, pos, n);
	}
	return 1;
}

void pri()
{
	rebuild(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		int l = a[match[i]].l, r = a[match[i]].r;
		if (i == r) continue;
		int pos = get_pos(1, 1, n, i + 1, r).second;
		if (a[match[pos]].l <= i)
		{
			swap(ans[a[match[i]].id], ans[a[match[pos]].id]);
			break;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;
	pre();
	for (int i = 1; i <= n; i++) ans[a[match[i]].id] = i;
	if (check())
	{
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	else
	{
		puts("NO");
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
		pri();
	}
	return 0;
}