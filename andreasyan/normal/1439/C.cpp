#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005;

int n, qq, s;
int a[N];

ll sum[N * 4];
int minu[N * 4];
int laz[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        sum[pos] = a[tl];
        minu[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
    minu[pos] = minu[pos * 2 + 1];
}

void shi(int tl, int tr, int pos)
{
    if (!laz[pos])
        return;
    laz[pos * 2] = laz[pos * 2 + 1] = laz[pos];
    int m = (tl + tr) / 2;
    sum[pos * 2] = (m - tl + 1) * 1LL * laz[pos];
    sum[pos * 2 + 1] = (tr - m) * 1LL * laz[pos];
    minu[pos * 2] = minu[pos * 2 + 1] = laz[pos];
    laz[pos] = 0;
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return sum[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        laz[pos] = y;
        sum[pos] = (r - l + 1) * 1LL * y;
        minu[pos] = y;
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    sum[pos] = sum[pos * 2] + sum[pos * 2 + 1];
    minu[pos] = minu[pos * 2 + 1];
}

int y;
int u;
bool qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return false;
    if (tl == l && tr == r)
    {
        if (y >= sum[pos])
        {
            y -= sum[pos];
            u += (r - l + 1);
            return false;
        }
        if (tl == tr)
        {
            return true;
        }
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    bool z = qry1(tl, m, l, min(m, r), pos * 2);
    if (z)
        return true;
    return qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int qry2(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return n + 1;
    if (minu[pos] > y)
        return n + 1;
    if (tl == tr)
        return tl;
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    int u = qry2(tl, m, l, min(m, r), y, pos * 2);
    if (u != n + 1)
        return u;
    return qry2(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    bil(1, n, 1);

    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);

            int l = 1, r = x;
            int xx = x + 1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (qry(1, n, m, m, 1) < y)
                {
                    xx = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            ubd(1, n, xx, x, y, 1);
        }
        else
        {
            int x;
            scanf("%d%d", &x, &y);
            int ans = 0;
            while (x <= n)
            {
                if (qry(1, n, x, x, 1) <= y)
                {
                    u = 0;
                    qry1(1, n, x, n, 1);
                    ans += u;
                    x += u;
                }
                else
                {
                    x = qry2(1, n, x, n, y, 1);
                }
            }
            printf("%d\n", ans);
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}