#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 10;
const int p = 1e9 + 7;

struct edge
{
    int l, r, uk;
};

edge a[MAXN];
int dp[4 * MAXN];
int b[MAXN];
int n, m;

void update(int k)
{
    dp[k] = (dp[k * 2] + dp[k * 2 + 1]) % p;
    if (k > 1)
        update(k / 2);
}
long long getsum(int v, int ll, int rr, int l, int r)
{
    if (ll > r || rr < l)
        return 0;
    if (ll >= l && rr <= r)
        return dp[v];
    return (getsum(v * 2, ll, (ll + rr) / 2, l, r) + getsum(v * 2 + 1, (ll + rr) / 2 + 1, rr, l, r)) % p;
}
bool operator < (edge a, edge b)
{
    return a.r < b.r;
}
int binr (int l, int r, int q)
{
    while (l < r - 1)
    {
        if (b[(l + r) / 2] < q)
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    return r;
}

int main()
{
    int i, size = 1, uk, l;
    cin >> n >> m;
    while (size < m)
    {
        size *= 2;
    }
    for (i = 0; i < m; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a, a + m);
    b[0] = 0;
    b[1] = a[0].r;
    uk = 2;
    for (i = 1; i < m; i++)
    {
        if (a[i - 1].r != a[i].r)
        {
            b[uk] = a[i].r;
            uk++;
        }
        a[i].uk = uk;
    }
    dp[size] = 1;
    update(size / 2);
    int uk1 = 1;
    for (i = 0; i < m; i++)
    {
        l = binr(-1, uk - 1, a[i].l);
        l++;
        if (i != 0 && a[i - 1].r != a[i].r)
            uk1++;
        dp[size + uk1] = (dp[size + uk1] + getsum(1, 1, size, l, uk1)) % p;
        update((size + uk1) / 2);
    }
    uk--;
    if (a[m - 1].r != n)
        cout << 0;
    else
        cout << dp[size + uk1];

    return 0;
}