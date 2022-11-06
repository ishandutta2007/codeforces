#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct node
{
    int m, i, l;
};

node seg[8200];
void init(int x, int l, int r)
{
    seg[x] = { -l, l, 0 };
    if(l == r)
        return;

    int mid = (l + r) / 2;
    init(2 * x, l, mid);
    init(2 * x + 1, mid + 1, r);
}
void prop(int x)
{
    int l = seg[x].l;
    seg[x].l = 0;
    seg[2 * x].m += l;
    seg[2 * x].l += l;
    seg[2 * x + 1].m += l;
    seg[2 * x + 1].l += l;
}
void add(int x, int l, int r, int s, int g, int v)
{
    if(g < l || r < s || g < s)
        return;

    if(s <= l && r <= g)
    {
        seg[x].m += v;
        seg[x].l += v;
        return;
    }

    int mid = (l + r) / 2;
    prop(x);
    add(2 * x, l, mid, s, g, v);
    add(2 * x + 1, mid + 1, r, s, g, v);

    if(seg[2 * x].m >= seg[2 * x + 1].m)
    {
        seg[x].m = seg[2 * x].m;
        seg[x].i = seg[2 * x].i;
    }
    else
    {
        seg[x].m = seg[2 * x + 1].m;
        seg[x].i = seg[2 * x + 1].i;
    }
}
pair<int, int> get_max(int x, int l, int r, int s, int g)
{
    if(g < l || r < s || g < s)
        return { -INF, -1 };

    if(s <= l && r <= g)
        return { seg[x].m, seg[x].i };

    int mid = (l + r) / 2;
    prop(x);
    auto [m1, i1] = get_max(2 * x, l, mid, s, g);
    auto [m2, i2] = get_max(2 * x + 1, mid + 1, r, s, g);

    if(m1 >= m2)
        return { m1, i1 };
    else
        return { m2, i2 };
}

struct str
{
    int x, i;
    bool operator <(const str& a) const
    {
        return x < a.x;
    }
};

int ori[3010];
str arr[3010];
int res[3010];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        x -= i;
        ori[i] = x;
        arr[i] = { x, i };
    }

    sort(arr + 1, arr + n + 1);
    init(1, 1, n);

    int s = 1;
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i].i >= s)
            v.push_back(i);

        if(i != n && arr[i].x == arr[i + 1].x || v.empty())
            continue;

        for(int x : v)
            add(1, 1, n, arr[x].i, n, 2);

        while(s <= n)
        {
            auto [x, y] = get_max(1, 1, n, s, n);
            if(x < 0)
                break;

            int t = 0;
            for(int j = s; j <= y; j++)
            {
                if(ori[j] <= arr[i].x)
                    t--;
                else
                    t++;
                res[j] = arr[i].x;
            }

            add(1, 1, n, y + 1, n, t);
            s = y + 1;
        }

        v.clear();
    }

    long long diff = 0;
    for(int i = 1; i <= n; i++)
        diff += abs(ori[i] - res[i]);

    printf("%lld\n", diff);
    return 0;
}