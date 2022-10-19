#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N], b[N];

int t[N * 8];

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        t[pos]++;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
    }
    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i] - b[i]);
        v.push_back(b[i] - a[i]);
    }
    sort(v.begin(), v.end());
    int z = 0;
    map<int, int> mp;
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
            mp[v[i]] = ++z;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += qry(1, z, mp[b[i] - a[i]] + 1, z, 1);
        ubd(1, z, mp[a[i] - b[i]], 1);
    }
    printf("%lld\n", ans);
    return 0;
}