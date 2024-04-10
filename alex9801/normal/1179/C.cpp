#include <bits/stdc++.h>
using namespace std;

int a[300010];
int b[300010];

int sum[1000010];

struct node
{
    int v, l;
};

node seg[2100000];

void init(int x, int l, int r)
{
    if(l == r)
        seg[x].v = sum[l];
    else
    {
        init(2 * x, l, (l + r) / 2);
        init(2 * x + 1, (l + r) / 2 + 1, r);
        seg[x].v = max(seg[2 * x].v, seg[2 * x + 1].v);
    }
}

void lazy(int x, int l, int r)
{
    seg[2 * x].v += seg[x].l;
    seg[2 * x].l += seg[x].l;
    seg[2 * x + 1].v += seg[x].l;
    seg[2 * x + 1].l += seg[x].l;
    seg[x].l = 0;
}

void add(int x, int l, int r, int s, int g, int v)
{
    if(g < l || r < s || g < s)
        return;

    if(s <= l && r <= g)
    {
        seg[x].v += v;
        seg[x].l += v;
    }
    else
    {
        lazy(x, l, r);
        add(2 * x, l, (l + r) / 2, s, g, v);
        add(2 * x + 1, (l + r) / 2 + 1, r, s, g, v);
        seg[x].v = max(seg[2 * x].v, seg[2 * x + 1].v);
    }
}

int get_ans(int x, int l, int r)
{
    if(seg[x].v <= 0)
        return -1;

    if(l == r)
        return l;

    lazy(x, l, r);
    
    int t = get_ans(2 * x + 1, (l + r) / 2 + 1, r);
    if(t != -1)
        return t;

    return get_ans(2 * x, l, (l + r) / 2);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    for(i = 1; i <= n; i++)
        sum[a[i]]++;
    for(i = 1; i <= m; i++)
        sum[b[i]]--;

    for(i = 1000000; i >= 1; i--)
        sum[i] += sum[i + 1];

    init(1, 1, 1000000);

    int q;
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        int t, x, v;
        scanf("%d%d%d", &t, &x, &v);
        if(t == 1)
        {
            add(1, 1, 1000000, 1, a[x], -1);
            a[x] = v;
            add(1, 1, 1000000, 1, a[x], 1);
        }
        else
        {
            add(1, 1, 1000000, 1, b[x], 1);
            b[x] = v;
            add(1, 1, 1000000, 1, b[x], -1);
        }

        int r = get_ans(1, 1, 1000000);
        printf("%d\n", r);
    }

    return 0;
}