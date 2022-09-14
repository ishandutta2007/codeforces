#include<bits/stdc++.h>

using namespace std;

const int maxn = 200000;

int main()
{
    int n, m, i, c[maxn], a[maxn], b[maxn], f[maxn];
    pair<int, int> ans[maxn];
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> c[i];
    a[0] = 0;
    b[0] = 0;
    for (i = 1; i <= n; i++)
    {
        if (c[i] == 1)
        {
            a[i] = a[i - 1] + 1;
            b[i] = b[i - 1];
        }
        if (c[i] == 2)
        {
            a[i] = a[i - 1];
            b[i] = b[i - 1] + 1;
        }
    }

    int l, r, x, t, s, u, k, p, q, j, z;
    m = 0;
    for (t = 1; t <= n; t++)
    {
        s = 0;
        u = 0;
        z = 0;
        while (u < n)
        {
            l = u;
            r = n + 1;
            while (r - l > 1)
            {
                x = (l + r) / 2;
                if (a[x] - a[u] >= t || b[x] - b[u] >= t)
                    r = x;
                else
                    l = x;
            }

            if (a[r] - a[u] == t)
                f[z] = 1;
            else
                f[z] = 2;
            u = r;
            z++;
        }

        if (u == n)
        {
            p = 0;
            q = 0;
            for (j = 0; j < z; j++)
            {
                if (f[j] == 1)
                    p++;
                else
                    q++;
            }

            if ((p > q && f[z - 1] == 1) || (p < q && f[z - 1] == 2))
            {

                ans[m]. first = max(p, q);
                ans[m]. second = t;
                m++;
            }
        }

    }
    cout << m << '\n';
    sort(ans, ans + m);
    for (i = 0; i < m; i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}