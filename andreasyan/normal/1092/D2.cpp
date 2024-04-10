#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;

int n;
int a[N];

int l[N], r[N], p[N];

int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    if (a[x] == a[y])
    {
        p[x] = y;
        l[y] = min(l[y], l[x]);
        r[y] = max(r[y], r[x]);
        return;
    }
    if (a[x] > a[y])
        swap(x, y);
    if ((r[x] - l[x] + 1) % 2 == 0)
    {
        p[x] = y;
        l[y] = min(l[y], l[x]);
        r[y] = max(r[y], r[x]);
        return;
    }
}

void solv(int x)
{
    while (1)
    {
        x = fi(x);
        int ll = l[x];
        int rr = r[x];
        if (l[x] > 1)
            kpc(l[x] - 1, l[x]);
        x = fi(x);
        if (r[x] < n)
            kpc(r[x] + 1, r[x]);
        x = fi(x);
        if (m_p(l[x], r[x]) == m_p(ll, rr))
            break;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        l[i] = r[i] = i;
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i)
        solv(i);
    if (m_p(l[fi(1)], r[fi(1)]) == m_p(1, n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}