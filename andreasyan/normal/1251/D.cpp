#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    return a.l < b.l;
}

int n;
long long g;
ban a[N];

bool c[N];
bool stg(int x)
{
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        c[i] = false;
        if (x <= a[i].r)
            ++q;
    }
    if (q < (n / 2 + 1))
        return false;
    q = (n / 2 + 1);
    long long gg = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].l >= x)
        {
            --q;
            gg += a[i].l;
            c[i] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        if (x <= a[i].r)
        {
            if (q > 0)
            {
                --q;
                gg += x;
                c[i] = true;
                continue;
            }
        }
        gg += a[i].l;
        c[i] = true;
    }
    return (gg <= g);
}

void solv()
{
    scanf("%d%lld", &n, &g);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].l, &a[i].r);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int l = 1, r = 1000000000;
    int ans;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (stg(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    printf("%d\n", ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}