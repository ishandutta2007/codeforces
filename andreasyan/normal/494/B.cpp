#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, M = 1000000007;

int n, m;
char a[N], b[N];

int uu[N];

int z[N];

int t[N * 4];
int laz[N * 4];

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    t[pos * 2] = (t[pos * 2] + laz[pos]) % M;
    t[pos * 2 + 1] = (t[pos * 2 + 1] + laz[pos]) % M;
    laz[pos * 2] = (laz[pos * 2] + laz[pos]) % M;
    laz[pos * 2 + 1] = (laz[pos * 2 + 1] + laz[pos]) % M;
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = (t[pos] + y) % M;
        laz[pos] = (laz[pos] + y) % M;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = (t[pos * 2] + t[pos * 2 + 1]) % M;
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf(" %s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    int mm = m;
    b[m++] = '#';
    for (int i = 0; i < n; ++i)
        b[m++] = a[i];
    int j = 0, r = 0;
    int u = 0;
    for (int i = 1; i < m; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - j]);
        }
        while (b[z[i]] == b[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
        if (z[i] == mm)
        {
            uu[i + mm - 1] = i;
        }
        u = max(u, uu[i]);
        if (u)
        {
            ubd(0, m, i, m, qry(0, m, 0, u - 1, 1) + (u - mm), 1);
        }
    }
    printf("%d\n", qry(0, m, m, m, 1));
    return 0;
}