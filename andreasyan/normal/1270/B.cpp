#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
int a[N];

pair<int, int> t[N * 4];

pair<int, int> mer(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second < b.second)
        return a;
    return b;
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(x, y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2),
               qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

pair<int, int> solvv()
{
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n, i, a[i] - i + 1, 1);
    }
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[i] >= a[s.top()])
            s.pop();
        int l;
        if (s.empty())
            l = 1;
        else
            l = s.top();
        pair<int, int> u = qry(1, n, l, i, 1);
        if (u.second <= a[i] - i)
            return m_p(u.first, i);
    }
    return m_p(-1, -1);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    pair<int, int> u = solvv();
    if (u.first != -1)
    {
        printf("YES\n");
        printf("%d %d\n", u.first, u.second);
        return;
    }
    reverse(a + 1, a + n + 1);
    u = solvv();
    if (u.first != -1)
    {
        u.first = n - u.second + 1;
        u.second = n - u.first + 1;
        printf("YES\n");
        printf("%d %d\n", u.first, u.second);
        return;
    }
    printf("NO\n");
}

void solv2()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i)
    {
        if (abs(a[i] - a[i + 1]) >= 2)
        {
            printf("YES\n");
            printf("%d %d\n", i, i + 1);
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv2();
    return 0;
}