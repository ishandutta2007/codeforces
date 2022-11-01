#include<bits/stdc++.h>
#define ls d << 1
#define rs d << 1 | 1
using namespace std;

typedef long long LL;

const int N = 200005;

int n, sz;
struct tree{int l, r; LL s1, s2, tag1, tag2;}t[N * 60];

struct data
{
	int w, l, r;
	data(int w, int l, int r):w(w), l(l), r(r) {}
	bool operator < (const data & a) const {return w < a.w || w == a.w && l < a.l;}
};
set<data> se;

struct Segtree1
{
	int mn[N * 4];
	
	void ins(int d, int l, int r, int x, int y)
	{
		if (l == r) {mn[d] = y; return;}
		int mid = (l + r) / 2;
		if (x <= mid) ins(ls, l, mid, x, y);
		else ins(rs, mid + 1, r, x, y);
		mn[d] = min(mn[ls], mn[rs]);
	}
	
	pair<int, int> query(int d, int l, int r, int x, int y)
	{
		if (mn[d] > y) return make_pair(0, 0);
		if (l == r) return make_pair(l, mn[d]);
		int mid = (l + r) / 2;
		if (mid >= x)
		{
			pair<int, int> ans = query(ls, l, mid, x, y);
			return !ans.first ? query(rs, mid + 1, r, x, y) : ans;
		}
		else return query(rs, mid + 1, r, x, y);
	}
}t1;

struct Segtree2
{
	vector<int> pos, rt;
	
	void ins(int &d, int p, int l, int r, int x, int y, LL w1, LL w2)
	{
		d = ++sz; t[d] = t[p];
		if (x <= l && r <= y)
		{
			t[d].s1 += w1 * (r - l + 1); t[d].s2 += w2 * (r - l + 1);
			t[d].tag1 += w1; t[d].tag2 += w2;
			return;
		}
		int mid = (l + r) / 2;
		if (x <= mid) ins(t[d].l, t[p].l, l, mid, x, y, w1, w2);
		if (y > mid) ins(t[d].r, t[p].r, mid + 1, r, x, y, w1, w2);
		t[d].s1 = t[t[d].l].s1 + t[t[d].r].s1 + (r - l + 1) * t[d].tag1;
		t[d].s2 = t[t[d].l].s2 + t[t[d].r].s2 + (r - l + 1) * t[d].tag2;
	}
	
	pair<LL, LL> query(int d, int l, int r, int x, int y)
	{
		if (x > r || y < l) return make_pair(0, 0);
		if (x <= l && r <= y || !d) return make_pair(t[d].s1, t[d].s2);
		int mid = (l + r) / 2;
		pair<LL, LL> u = query(t[d].l, l, mid, x, y), v = query(t[d].r, mid + 1, r, x, y);
		int len = min(y, r) - max(x, l) + 1;
		return make_pair(u.first + v.first + t[d].tag1 * len, u.second + v.second + t[d].tag2 * len);
	}
	
	void ins(int tim, int l, int r, LL w1, LL w2)
	{
		rt.push_back(0); pos.push_back(tim);
		int p = rt.size() - 1;
		ins(rt[p], p ? rt[p - 1] : 0, 1, n, l, r, w1, w2);
	}
	
	LL query(int l, int r)
	{
		int q = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;
		if (q < 0) return 0;
		pair<LL, LL> ans = query(rt[q], 1, n, l, r);
		return ans.first * (r + 1) - ans.second;
	}
}t2[N];

LL solve(int a, int l, int r, int k, int tim)
{
	int u = a ? 0 : 1;
	t1.ins(1, 0, n, a, tim);
	set<data>::iterator it = se.lower_bound(data(a, 0, 0));
	if (it != se.end() && (*it).w == a)
	{
		int p = (*it).l, q = (*it).r;
		se.erase(it);
		t2[a].ins(tim, p, q, -1, -tim);
		while (p <= q)
		{
			pair<int, int> nx = t1.query(1, 0, n, a + 1, q);
			if (!nx.first || nx.second < p)
			{
				se.insert(data(nx.first, p, q));
				t2[nx.first].ins(tim, p, q, 1, tim);
				q = nx.second; a = nx.first;
				break;
			}
			if (nx.second < q)
			{
				t2[nx.first].ins(tim, nx.second + 1, q, 1, tim);
				se.insert(data(nx.first, nx.second + 1, q));
			}
			q = nx.second;
			a = nx.first;
		}
		it = se.lower_bound(data(a, 0, 0));
		if (it != se.end() && (*it).w == a)
		{
			data tmp = *it;
			it++;
			if (it != se.end() && (*it).w == a)
			{
				se.erase(it); se.erase(se.find(tmp));
				tmp.r = (*it).r;
				se.insert(tmp);
			}
		}
	}
	it = se.lower_bound(data(u, 0, 0));
	if (it != se.end() && (*it).w == u)
	{
		data tmp = *it; tmp.r++;
		se.erase(it); se.insert(tmp);
	}
	else se.insert(data(u, tim, tim));
	t2[u].ins(tim, tim, tim, 1, tim);
	return t2[k].query(l, r);
}

int main()
{
	scanf("%d", &n);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, l, r, k; scanf("%d%d%d%d", &a, &l, &r, &k);
		a = (a + ans) % (n + 1); k = (k + ans) % (n + 1);
		l = (l + ans) % i + 1; r = (r + ans) % i + 1;
		if (l > r) swap(l, r);
		ans = solve(a, l, r, k, i);
		printf("%lld\n", ans);
	}
	return 0;
}