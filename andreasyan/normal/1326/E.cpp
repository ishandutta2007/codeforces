#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 300005;

int n;
int p[N];
int u[N];
int q[N];

int maxu[N * 4];
int laz[N * 4];

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    maxu[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    maxu[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        maxu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p[i]);
        u[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &q[i]);
    }
    int j = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        while (maxu[1] <= 0)
        {
            --j;
            ubd(1, n, 1, u[j], 1, 1);
        }
        printf("%d ", j);
        ubd(1, n, 1, q[i], -1, 1);
    }
    printf("\n");
    return 0;
}