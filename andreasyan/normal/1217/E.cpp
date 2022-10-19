#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, INF = 1000000009;

int n, qq;
int a[N];

struct ban
{
    int ans;
    int u[9];
    ban()
    {
        ans = INF * 2;
        for (int i = 0; i < 9; ++i)
            u[i] = INF;
    }
    ban(int x)
    {
        ans = INF * 2;
        for (int i = 0; i < 9; ++i)
            u[i] = INF;
        int i = 0;
        int y = x;
        while (y)
        {
            if (y % 10 != 0)
                u[i] = min(u[i], x);
            y /= 10;
            ++i;
        }
    }
};

ban t[N * 4];

ban mer(const ban& a, const ban& b)
{
    ban res;
    res.ans = min(a.ans, b.ans);
    for (int i = 0; i < 9; ++i)
    {
        if (a.u[i] != INF && b.u[i] != INF)
            res.ans = min(res.ans, a.u[i] + b.u[i]);
        res.u[i] = min(a.u[i], b.u[i]);
    }
    return res;
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
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
            ubd(1, n, x, y, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int ans = qry(1, n, l, r, 1).ans;
            if (ans == INF * 2)
                printf("-1\n");
            else
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}