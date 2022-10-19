#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006;
const int z = 1000000;
const long long INF = 1000000009000000009;
struct ban
{
    int x;
    int cx;
    ban(){}
    ban(int x, int cx)
    {
        this->x = x;
        this->cx = cx;
    }
};
struct ban1
{
    int x, y, z;
};

int n, m, k;
ban a[N];
ban b[N];
ban1 c[N];

long long t[N * 4];
long long laz[N * 4];

void shi(int pos)
{
    if (laz[pos] == 0)
        return;
    t[pos * 2] += laz[pos];
    laz[pos * 2] += laz[pos];
    t[pos * 2 + 1] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, long long y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
}

/*long long qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return -INF;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}*/

long long maxu[N];

vector<ban> v[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].cx);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &b[i].x, &b[i].cx);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].z);
    ////////////////////////////////////////////////////////
    for (int i = 1; i <= z + 1; ++i)
        maxu[i] = -INF;
    for (int i = 1; i <= m; ++i)
        maxu[b[i].x] = max(maxu[b[i].x], -b[i].cx * 1LL);
    for (int i = z; i >= 1; --i)
        maxu[i] = max(maxu[i], maxu[i + 1]);
    for (int i = 1; i <= z; ++i)
        ubd(1, z, i, i, maxu[i], 1);
    ////////////////////////////////////////////////////////
    for (int i = 1; i <= z + 1; ++i)
        maxu[i] = -INF;
    for (int i = 1; i <= n; ++i)
        maxu[a[i].x] = max(maxu[a[i].x], -a[i].cx * 1LL);
    for (int i = z; i >= 1; --i)
        maxu[i] = max(maxu[i], maxu[i + 1]);
    /////////////////////////////////////////////////////////
    for (int i = 1; i <= k; ++i)
        v[c[i].x].push_back(ban(c[i].y, c[i].z));
    /////////////////////////////////////////////////////////
    long long ans = -INF;
    for (int i = 1; i <= z; ++i)
    {
        ans = max(ans, maxu[i] + t[1]);
        for (int j = 0; j < v[i].size(); ++j)
            ubd(1, z, v[i][j].x + 1, z, v[i][j].cx, 1);
    }
    printf("%lld\n", ans);
    return 0;
}