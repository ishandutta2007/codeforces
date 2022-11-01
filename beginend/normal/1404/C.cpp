#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, rt, a[N], q;
struct tree{int l, r, s, mn, fa;}t[N];

void update(int x)
{
    t[x].mn=min(x, min(t[t[x].l].mn,t[t[x].r].mn));
    t[x].s=t[t[x].l].s+t[t[x].r].s+1;
}

void rttr(int x)
{
    int y=t[x].l;
    if (x==rt) rt=y;
    t[x].l=t[y].r;t[t[y].r].fa=x;
    if (x==t[t[x].fa].l) t[t[x].fa].l=y;
    else if (x==t[t[x].fa].r) t[t[x].fa].r=y;
    t[y].fa=t[x].fa;
    t[x].fa=y;t[y].r=x;
    update(x);update(y);
}

void rttl(int x)
{
    int y=t[x].r;
    if (x==rt) rt=y;
    t[x].r=t[y].l;t[t[y].l].fa=x;
    if (x==t[t[x].fa].l) t[t[x].fa].l=y;
    else if (x==t[t[x].fa].r) t[t[x].fa].r=y;
    t[y].fa=t[x].fa;
    t[x].fa=y;t[y].l=x;
    update(x);update(y);
}

void splay(int x,int y)
{
    while (t[x].fa!=y)
    {
        int p=t[x].fa,g=t[p].fa;
        if (g==y)
        {
            if (x==t[p].l) rttr(p);
            else rttl(p);
            return;
        }
        if (x==t[p].l)
            if (p==t[g].l) rttr(g),rttr(p);
            else rttr(p),rttl(g);
        else
            if (p==t[g].r) rttl(g),rttl(p);
            else rttl(p),rttr(g);
    }
}

int get_kth(int k)
{
	int x = rt;
	while (x)
		if (t[t[x].l].s + 1 == k) return splay(x, 0), x;
		else if (t[t[x].l].s + 1 > k) x = t[x].l;
		else k -= t[t[x].l].s + 1, x = t[x].r;
	return x;
}

struct Segtree
{
	int rt[N], sz;
	struct tree{int l, r, s;}t[N * 20];
	
	void ins(int & d, int l, int r, int x)
	{
		int p = d; d = ++sz; t[d] = t[p];
		t[d].s++;
		if (l == r) return;
		int mid = (l + r) / 2;
		if (x <= mid) ins(t[d].l, l, mid, x);
		else ins(t[d].r, mid + 1, r, x);
	}
	
	int query(int d, int l, int r, int x, int y)
	{
		if (x <= l && r <= y) return t[d].s;
		int mid = (l + r) / 2;
		if (y <= mid) return query(t[d].l, l, mid, x, y);
		else if (x > mid) return query(t[d].r, mid + 1, r, x, y);
		else return query(t[d].l, l, mid, x, y) + query(t[d].r, mid + 1, r, x, y);
	}
}tr;

int main()
{
	//freopen("a.in", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = i - a[i];
	t[n + 2].fa = n + 1; t[n + 1].l = n + 2; rt = n + 1;
	t[0].mn = n + 10;
	update(n + 2); update(n + 1);
	for (int i = 1; i <= n; i++)
	{
		tr.rt[i] = tr.rt[i - 1];
		if (a[i] < 0) continue;
		if (a[i] > t[rt].s - 2) continue;
		int l = get_kth(a[i] + 1), r = get_kth(a[i] + 2);
		splay(r, 0); splay(l, r);
		tr.ins(tr.rt[i], 1, n, t[l].mn <= n ? t[l].mn : i);
		//printf("%d %d\n", i, t[l].mn <= n ? t[l].mn : i);
		t[i].fa = l; t[l].r = i;
		update(i); update(l); update(r);
	}
	while (q--)
	{
		int x, y; scanf("%d%d", &x, &y);
		int l = x + 1, r = n - y;
		printf("%d\n", tr.query(tr.rt[n - y], 1, n, l, r));
	}
	return 0;
}