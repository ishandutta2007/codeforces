#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
struct ban
{
    int i, j, w;
};

bool inside(int x1, int x2, int y1, int y2, ban t)
{
    return (x1 <= t.i && t.i <= x2 && y1 <= t.j && t.j <= y2);
}

int n, m, k;
vector<ban> a[N];

long long t[N][N];
void ubd(int i, int x, int y)
{
    ++x;
    while (x <= a[i].size())
    {
        t[i][x] += y;
        x += (x & (-x));
    }
}

long long qry(int i, int l, int r)
{
    if (l > r)
        return 0;
    ++r;
    long long ans = 0;
    while (r > 0)
    {
        ans += t[i][r];
        r -= (r & (-r));
    }
    while (l > 0)
    {
        ans -= t[i][l];
        l -= (l & (-l));
    }
    return ans;
}

int b[N][N], bb[N][N];

bool c[N];

vector<int> v[N];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= m + 1; ++j)
            b[i][j] = -1;
    }
    for (int i = 0; i < k; ++i)
    {
        int m;
        scanf("%d", &m);
        while (m--)
        {
            ban t;
            scanf("%d%d%d", &t.i, &t.j, &t.w);
            a[i].push_back(t);
        }
        for (int j = 0; j < a[i].size(); ++j)
        {
            ubd(i, j, a[i][j].w);
            b[a[i][j].i][a[i][j].j] = i;
            bb[a[i][j].i][a[i][j].j] = j;
        }
        c[i] = true;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char s[10];
        scanf("%s", s);
        if (s[0] == 'S')
        {
            int x;
            scanf("%d", &x);
            --x;
            c[x] ^= 1;
        }
        else
        {
            for (int i = 0; i < k; ++i)
            {
                v[i].clear();
                v[i].push_back(-1);
                v[i].push_back(a[i].size());
            }
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            for (int i = x1; i <= x2; ++i)
            {
                if (b[i][y1 - 1] != -1)
                    v[b[i][y1 - 1]].push_back(bb[i][y1 - 1]);
                if (b[i][y2 + 1] != -1)
                    v[b[i][y2 + 1]].push_back(bb[i][y2 + 1]);
            }
            for (int j = y1; j <= y2; ++j)
            {
                if (b[x1 - 1][j] != -1)
                    v[b[x1 - 1][j]].push_back(bb[x1 - 1][j]);
                if (b[x2 + 1][j] != -1)
                    v[b[x2 + 1][j]].push_back(bb[x2 + 1][j]);
            }
            long long ans = 0;
            for (int i = 0; i < k; ++i)
            {
                if (!c[i])
                    continue;
                sort(v[i].begin(), v[i].end());
                bool z;
                if (inside(x1, x2, y1, y2, a[i][0]))
                    z = true;
                else
                    z = false;
                for (int j = 1; j < v[i].size(); ++j)
                {
                    if (z)
                        ans += qry(i, v[i][j - 1] + 1, v[i][j] - 1);
                    if (z)
                        z = false;
                    else
                    {
                        if (v[i][j] >= a[i].size() - 1)
                            continue;
                        if (inside(x1, x2, y1, y2, a[i][v[i][j] + 1]))
                            z = true;
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}