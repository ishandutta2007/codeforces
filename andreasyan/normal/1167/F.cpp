#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const long long M = 1000000007;

struct ban0
{
    long long x;
    ban0()
    {
        x = 0;
    }
    ban0(long long x)
    {
        this->x = x % M;
    }
};
ban0 operator+(const ban0& a, const ban0& b)
{
    return ban0((a.x + b.x) % M);
}
ban0 operator*(const ban0& a, const ban0& b)
{
    return ban0((a.x * b.x) % M);
}

struct ban
{
    int i;
    ban0 x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x.x < b.x.x;
}

int n;
ban a[N];

ban0 t[2][N * 4];

void ubd(int i, int tl, int tr, int x, ban0 y, int pos)
{
    if (tl == tr)
    {
        t[i][pos] = t[i][pos] + y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(i, tl, m, x, y, pos * 2);
    else
        ubd(i, m + 1, tr, x, y, pos * 2 + 1);
    t[i][pos] = t[i][pos * 2] + t[i][pos * 2 + 1];
}
ban0 qry(int i, int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[i][pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(i, tl, m, l, r, pos * 2);
    if (l > m)
        return qry(i, m + 1, tr, l, r, pos * 2 + 1);
    return qry(i, tl, m, l, m, pos * 2) + qry(i, m + 1, tr, m + 1, r, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x.x;
        a[i].i = i;
    }
    sort(a + 1, a + n + 1);
    ban0 ans = 0;
    for (int ii = 1; ii <= n; ++ii)
    {
        int i = a[ii].i;
        ban0 x = a[ii].x;
        ans = ans + ((qry(0, 1, n, 1, i, 1)) * ban0(n - i + 1) * x);
        ans = ans + ((qry(1, 1, n, i, n, 1)) * ban0(i) * x);
        ans = ans + (ban0(i) * ban0(n - i + 1) * x);
        ubd(0, 1, n, i, ban0(i), 1);
        ubd(1, 1, n, i, ban0(n - i + 1), 1);
    }
    cout << ans.x << endl;
    return 0;
}