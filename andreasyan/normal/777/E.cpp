#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int l, r, h;
    ban(){}
    ban(int l, int r, int h)
    {
        this->l = l;
        this->r = r;
        this->h = h;
    }
};
bool operator<(const ban& a, const ban& b)
{
    if (a.r > b.r)
        return true;
    if (a.r < b.r)
        return false;
    return a.l > b.l;
}

int n;
ban a[N];

long long t[N * 8];
void ubd(int tl, int tr, int x, long long y, int pos)
{
    if (tl == tr)
    {
        t[pos] = max(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}
long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return max(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

long long dp[N * 4];

int main()
{
    int z = 0;
    vector<int> v;
    map<int, int> mp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].h);
        v.push_back(a[i].l);
        v.push_back(a[i].r);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (i == 0 || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        a[i].l = mp[a[i].l];
        a[i].r = mp[a[i].r];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = qry(1, z, 1, a[i].r - 1, 1) + a[i].h;
        ubd(1, z, a[i].l, dp[i], 1);
    }
    cout << t[1] << endl;
    return 0;
}