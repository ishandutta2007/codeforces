#include<bits/stdc++.h>
#define ls (d << 1)
#define rs (d << 1 | 1)
using namespace std;

typedef long long LL;

const int N = 2005;
const int MOD = 1000000007;

int n, m, k, L, w[N], sta[N];
vector<int> vec[N];
struct tree{int mn, mx, tag; LL s;}t[N * 4];
struct data{int x, y, c;}a[N];
struct Event
{
	int l, r, x, y;
	Event(int l, int r, int x, int y):l(l), r(r), x(x), y(y) {}
};

void init()
{
	scanf("%d%d%d", &n, &k, &L); L--;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
		w[++m] = a[i].x;
	}
	sort(a + 1, a + n + 1, [&](const data & a, const data & b){return a.y < b.y;});
	for (int i = n; i >= 1; i--) vec[a[i].c].push_back(i);
	w[++m] = 0;
	sort(w + 1, w + m + 1);
	m = unique(w + 1, w + m + 1) - w - 1;
	for (int i = 1; i <= n; i++) a[i].x = lower_bound(w + 1, w + m + 1, a[i].x) - w;
}

void update(int d)
{
	t[d].s = t[ls].s + t[rs].s;
	t[d].mn = min(t[ls].mn, t[rs].mn);
	t[d].mx = max(t[ls].mx, t[rs].mx);
}

void mark(int d, int l, int r, int p)
{
	t[d].mn = t[d].mx = t[d].tag = p;
	t[d].s = (LL)(w[r + 1] - w[l]) * p;
}

void pushdown(int d, int l, int r)
{
	if (!t[d].tag) return;
	int p = t[d].tag, mid = (l + r) / 2; t[d].tag = 0;
	mark(ls, l, mid, p); mark(rs, mid + 1, r, p);
}

void build(int d, int l, int r, int x)
{
	t[d].tag = 0;
	if (l == r) {t[d].mn = t[d].mx = l < x ? L + 1 : 0; t[d].s = (LL)t[d].mn * (w[l + 1] - w[l]); return;}
	int mid = (l + r) / 2;
	build(ls, l, mid, x); build(rs, mid + 1, r, x);
	update(d);
}

void modify(int d, int l, int r, int x, int y, int p)
{
	if (t[d].mn >= p || x > y) return;
	if (x <= l && r <= y && p >= t[d].mx) {mark(d, l, r, p); return;}
	pushdown(d, l, r);
	int mid = (l + r) / 2;
	if (x <= mid) modify(ls, l, mid, x, y, p);
	if (y > mid) modify(rs, mid + 1, r, x, y, p);
	update(d);
}

int main()
{
	init();
	w[m + 1] = L + 1; w[0] = -1;
	LL ans = 0;
	for (int i = 1; i <= m; i++)
	{
		vector<Event> event;
		build(1, 1, m, i);
		for (int j = 1; j <= k; j++)
		{
			int top = 0;
			for (int id : vec[j]) if (a[id].x >= i)
			{
				int pos = m;
				while (top && a[sta[top]].x >= a[id].x)
				{
					event.push_back(Event(a[sta[top]].x, pos, a[id].y, a[sta[top]].y));
					pos = a[sta[top]].x - 1; top--;
				}
				if (top) event.push_back(Event(a[id].x, pos, a[id].y, a[sta[top]].y));
				else event.push_back(Event(a[id].x, pos, a[id].y, L + 1));
				sta[++top] = id;
			}
			int pos = m;
			while (top)
			{
				modify(1, 1, m, a[sta[top]].x, pos, a[sta[top]].y);
				pos = a[sta[top]].x - 1; top--;
			}
			modify(1, 1, m, 1, pos, L + 1);
		}
		sort(event.begin(), event.end(), [&](const Event & a, const Event & b){return a.x < b.x;});
		int kk = event.size() ? event[0].x + 1 : L + 1;
		(ans += (LL)((LL)(L + 1) * (L + 1) - t[1].s) % MOD * kk % MOD * (w[i] - w[i - 1])) %= MOD;
		event.push_back(Event(0, 0, L + 1, 0));
		for (int p = 0; p < event.size() - 1;)
		{
			modify(1, 1, m, event[p].l, event[p].r, event[p].y); p++;
			while (p < event.size() - 1 && event[p].x == event[p - 1].x)
				modify(1, 1, m, event[p].l, event[p].r, event[p].y), p++;
			(ans += (LL)((LL)(L + 1) * (L + 1) - t[1].s) % MOD * (event[p].x - event[p - 1].x) % MOD * (w[i] - w[i - 1])) %= MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}