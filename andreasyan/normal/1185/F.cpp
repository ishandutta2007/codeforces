#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005, INF = 2000000009;
const int k = 10;

int n, m;
int b[N];
int a[N];
int c[N];

int min1, mini1, min2, mini2;

int minu[1 << k], mini[1 << k];

int g[1 << k];
pair<int, int> t[1 << k];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int q;
        cin >> q;
        while (q--)
        {
            int j;
            cin >> j;
            --j;
            b[i] = (b[i] | (1 << j));
        }
    }
    min1 = INF;
    min2 = INF;
    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i];
        if (c[i] < min1)
        {
            min2 = min1;
            mini2 = mini1;
            min1 = c[i];
            mini1 = i;
        }
        else if (c[i] < min2)
        {
            min2 = c[i];
            mini2 = i;
        }
        int q;
        cin >> q;
        while (q--)
        {
            int j;
            cin >> j;
            --j;
            a[i] = (a[i] | (1 << j));
        }
    }
    for (int x = 0; x < (1 << k); ++x)
        minu[x] = INF;
    for (int i = 1; i <= m; ++i)
    {
        if (c[i] < minu[a[i]])
        {
            minu[a[i]] = c[i];
            mini[a[i]] = i;
        }
    }
    for (int x = 0; x < (1 << k); ++x)
        g[x] = INF;
    for (int x = 0; x < (1 << k); ++x)
    {
        for (int y = 0; y < (1 << k); ++y)
        {
            if (minu[x] == INF || minu[y] == INF)
                continue;
            if (x != y)
            {
                if (minu[x] + minu[y] < g[(x | y)])
                {
                    g[(x | y)] = minu[x] + minu[y];
                    t[(x | y)] = m_p(mini[x], mini[y]);
                }
            }
            else
            {
                if (mini1 == mini[x])
                {
                    if (minu[x] + min2 < g[(x | y)])
                    {
                        g[(x | y)] = minu[x] + min2;
                        t[(x | y)] = m_p(mini[x], mini2);
                    }
                }
                else
                {
                    if (minu[x] + min1 < g[(x | y)])
                    {
                        g[(x | y)] = minu[x] + min1;
                        t[(x | y)] = m_p(mini[x], mini1);
                    }
                }
            }
        }
    }

    int maxu = -1, maxx;
    for (int x = 0; x < (1 << k); ++x)
    {
        if (g[x] == INF)
            continue;
        int q = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((b[i] & x) == b[i])
                ++q;
        }
        if (q > maxu || (q == maxu && g[x] < g[maxx]))
        {
            maxu = q;
            maxx = x;
        }
    }
    cout << t[maxx].first << ' ' << t[maxx].second << endl;
    return 0;
}