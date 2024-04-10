#include <bits/stdc++.h>
using namespace std;
const int N = 502, M = 10004;

int n, m;
int x[M], y[M];

int p[M][N];
int s[M][N];

int fi(int x, int p[])
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x], p);
}
void kpc(int x, int y, int p[])
{
    x = fi(x, p);
    y = fi(y, p);
    p[x] = y;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> x[i] >> y[i];

    for (int j = 1; j <= n; ++j)
        p[0][j] = j;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
            p[i][j] = p[i - 1][j];
        kpc(x[i], y[i], p[i]);
    }

    for (int j = 1; j <= n; ++j)
        s[m + 1][j] = j;
    for (int i = m; i >= 1; --i)
    {
        for (int j = 1; j <= n; ++j)
            s[i][j] = s[i + 1][j];
        kpc(x[i], y[i], s[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int t[N];
        for (int j = 1; j <= n; ++j)
            t[j] = p[l - 1][j];
        for (int j = 1; j <= n; ++j)
        {
            if (p[l - 1][j] != s[r + 1][j])
                kpc(p[l - 1][j], s[r + 1][j], t);
        }
        for (int i = 1; i <= n; ++i)
            t[i] = fi(i, t);
        sort(t + 1, t + n + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (t[i] != t[i - 1])
                ++ans;
        }
        cout << ans << endl;
    }

    return 0;
}