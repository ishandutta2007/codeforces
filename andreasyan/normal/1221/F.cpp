#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
struct ban
{
    int l, r, x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.r < b.r;
}

int n;
ban a[N];

vector<int> v;
int z;
map<int, int> mp;
int rmp[N];

pair<long long, int> t[N * 4];
long long laz[N * 4];

pair<long long, int> mer(const pair<long long, int>& l, const pair<long long, int>& r)
{
    if (l.first > r.first)
        return l;
    return r;
}

void shi(int pos)
{
    t[pos * 2].first += laz[pos];
    laz[pos * 2] += laz[pos];
    t[pos * 2 + 1].first += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (tl == tr && tl == 3)
            cout << "";
        t[pos].first += y;
        laz[pos] += y;
        if (tl == tr)
            t[pos].second = tl;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

pair<long long, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].x);
        if (a[i].r < a[i].l)
            swap(a[i].r, a[i].l);
    }
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].l);
        v.push_back(a[i].r);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
            rmp[z] = v[i];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        a[i].l = mp[a[i].l];
        a[i].r = mp[a[i].r];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= z; ++i)
        ubd(1, z, i, i, rmp[i], 1);

    long long ans;
    int ansl, ansr;

    for (int i = 0; ; ++i)
    {
        if (!binary_search(v.begin(), v.end(), i))
        {
            ans = 0;
            ansl = ansr = i;
            break;
        }
    }

    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, z, a[i].l + 1, z, -a[i].x, 1);
        sum += a[i].x;
        if (i == n || a[i].r != a[i + 1].r)
        {
            pair<long long, int> u = qry(1, z, 1, a[i].r, 1);
            if (u.first + sum - rmp[a[i].r] > ans)
            {
                ans = u.first + sum - rmp[a[i].r];
                ansl = rmp[u.second];
                ansr = rmp[a[i].r];
            }
        }
    }
    cout << ans << endl;
    cout << ansl << ' ' << ansl << ' ' << ansr << ' ' << ansr << endl;
    return 0;
}