#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 400005;
struct ban
{
    int l1, r1;
    int l2, r2;
};
bool operator<(const ban& a, const ban& b)
{
    return a.r1 < b.r1;
}

int n;
ban a[N];

int z;

vector<int> v[N];

bool laz[N * 4];
bool t[N * 4];

void shi(int pos)
{
    if (laz[pos])
    {
        t[pos * 2] = t[pos * 2 + 1] = true;
        laz[pos * 2] = laz[pos * 2 + 1] = true;
        laz[pos] = false;
    }
}

void ubd(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = true;
        laz[pos] = true;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    t[pos] = (t[pos * 2] || t[pos * 2 + 1]);
}
bool qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return false;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) ||
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

bool stg()
{
    for (int i = 0; i <= n; ++i)
        v[i].clear();
    memset(t, false, sizeof t);
    memset(laz, false, sizeof laz);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i - 1;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m].r1 < a[i].l1)
            {
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        v[ans].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, z, a[i].l2, a[i].r2, 1);
        for (int j = 0; j < v[i].size(); ++j)
        {
            int k = v[i][j];
            if (qry(1, z, a[k].l2, a[k].r2, 1))
                return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", &a[i].l1, &a[i].r1, &a[i].l2, &a[i].r2);
    vector<int> v;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].l1);
        v.push_back(a[i].r1);
        v.push_back(a[i].l2);
        v.push_back(a[i].r2);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
            mp[v[i]] = ++z;
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].l1 = mp[a[i].l1];
        a[i].r1 = mp[a[i].r1];
        a[i].l2 = mp[a[i].l2];
        a[i].r2 = mp[a[i].r2];
    }
    if (!stg())
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        swap(a[i].l1, a[i].l2);
        swap(a[i].r1, a[i].r2);
    }
    if (!stg())
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}