#include<bits/stdc++.h>

using namespace std;
const int maxn = 10000;

int main()
{
    int n, m, i, j, k, we, t, ans, a[maxn], b[maxn], w[maxn], u[maxn], p[maxn], w1[maxn];
    cin >> n >> m;
    k = 0;
    for (i = 0; i < n; i++)
        cin >> w1[i];
    for (i = 1; i <= n; i++)
        u[i] = 0;
    for (j = 0; j < m; j++)
    {
        cin >> b[j];
        if (u[b[j]] == 0)
        {
            u[b[j]] = 1;
            a[k] = b[j];
            w[k] = w1[b[j] - 1];
            p[b[j]] = k;
            k++;
        }
    }
    for (i = 1; i <= n; i++)
        if (u[i] == 0)
        {
            u[i] = 1;
            a[k] = i;
            w[k] = w1[i - 1];
            p[i] = k;
            k++;
        };
    ans = 0;
    for (i = 0; i < m; i++)
    {
        we = 0;
        t = w[p[b[i]]];
        for (j = 0; j < p[b[i]]; j++)
            ans += w[j];
        for (j = p[b[i]] - 1; j > -1; j--)
        {
            p[a[j]] = j + 1;
            a[j + 1] = a[j];
            w[j + 1] = w[j];
        }
        p[b[i]] = 0;
        a[0] = b[i];
        w[0] = t;
    }
    cout << ans;

}