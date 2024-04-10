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

int n, q;
char s[N], f[N];
pair<int, int> b[N];

int t[N * 4];

void shi(int tl, int tr, int pos)
{
    int m = (tl + tr) / 2;
    if (t[pos] == 0)
        t[pos * 2] = t[pos * 2 + 1] = 0;
    if (t[pos] == tr - tl + 1)
    {
        t[pos * 2] = m - tl + 1;
        t[pos * 2 + 1] = tr - m;
    }
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (y == 0)
        {
            t[pos] = 0;
        }
        else
        {
            t[pos] = r - l + 1;
        }
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d", &n, &q);
    scanf(" %s", (s + 1));
    scanf(" %s", (f + 1));
    for (int i = 1; i <= q; ++i)
        scanf("%d%d", &b[i].fi, &b[i].se);

    for (int i = 1; i <= (n + 3) * 4; ++i)
        t[i] = 0;

    bool z = true;
    for (int i = 1; i <= n; ++i)
        ubd(1, n, i, i, f[i] - '0', 1);
    for (int i = q; i >= 1; --i)
    {
        int l = b[i].fi, r = b[i].se;
        int q = qry(1, n, l, r, 1);
        if (q == (r - l + 1) - q)
        {
            z = false;
            break;
        }
        else if (q < (r - l + 1) - q)
            ubd(1, n, l, r, 0, 1);
        else
            ubd(1, n, l, r, 1, 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] - '0' != qry(1, n, i, i, 1))
        {
            z = false;
            break;
        }
    }

    if (!z)
        printf("NO\n");
    else
        printf("YES\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}