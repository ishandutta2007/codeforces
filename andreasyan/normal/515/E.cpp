#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m;
int d[N], h[N];

struct ban
{
    long long ans;
    long long l, r;
    long long d;
    ban(){}
    ban(int h)
    {
        ans = -1;
        l = h * 2;
        r = h * 2;
        d = 0;
    }
};

ban mer(const ban& l, const ban& r, int d)
{
    ban res;
    res.l = max(l.l, l.d + d + r.l);
    res.r = max(r.r, l.r + d + r.d);
    res.ans = max(l.ans, r.ans);
    res.ans = max(res.ans, l.r + d + r.l);
    res.d = l.d + d + r.d;
    return res;
}

ban t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = ban(h[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1], d[m]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1), d[m]);
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &d[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &h[i]);
    bil(1, n, 1);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        ban u;
        if (l <= r)
        {
            if (l == 1)
                u = qry(1, n, r + 1, n, 1);
            else if (r == n)
                u = qry(1, n, 1, l - 1, 1);
            else
                u = mer(qry(1, n, r + 1, n, 1), qry(1, n, 1, l - 1, 1), d[n]);
        }
        else
        {
            u = qry(1, n, r + 1, l - 1, 1);
        }
        printf("%lld\n", u.ans);
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