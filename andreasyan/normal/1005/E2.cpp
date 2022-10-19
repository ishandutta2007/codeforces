#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
int a[N];

struct ban
{
    ban *l, *r;
    int q;
    ban()
    {
        l = r = 0;
        q = 0;
    }
};

ban *z, *k;

void ave(ban* pos)
{
    if (pos->l == 0)
        pos->l = new ban;
    if (pos->r == 0)
        pos->r = new ban;
}

void ubd(int tl, int tr, int x, ban* pos)
{
    if (tl == tr)
    {
        pos->q++;
        return;
    }
    ave(pos);
    int m = (tl + tr) / 2;
    if (m == tr)
        m = tl;
    if (x <= m)
        ubd(tl, m, x, pos->l);
    else
        ubd(m + 1, tr, x, pos->r);
    pos->q = pos->l->q + pos->r->q;
}

int qry(int tl, int tr, int l, int r, ban* pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return pos->q;
    ave(pos);
    int m = (tl + tr) / 2;
    if (m == tr)
        m = tl;
    if (r <= m)
        return qry(tl, m, l, r, pos->l);
    if (l > m)
        return qry(m + 1, tr, l, r, pos->r);
    return qry(tl, m, l, m, pos->l) + qry(m + 1, tr, m + 1, r, pos->r);
}

int p[N];
long long pp()
{
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] <= m)
            p[i]++;
    }

    long long ans = 0;

    z = new ban;
    k = new ban;

    int i = 0;

    ubd(-n, n, 2 * p[i] - i, z);

    for (i = 1; i <= n; ++i)
    {
        if (i == 3)
            cout << "";
        if (i % 2)
        {
            ans += qry(-n, n, -n, 2 * p[i] - i - 1, z);
            ans += qry(-n, n, -n, 2 * p[i] - i, k);
        }
        else
        {
            ans += qry(-n, n, -n, 2 * p[i] - i - 1, k);
            ans += qry(-n, n, -n, 2 * p[i] - i, z);
        }
        if (i % 2)
            ubd(-n, n, 2 * p[i] - i, k);
        else
            ubd(-n, n, 2 * p[i] - i, z);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    long long ans = pp();
    --m;
    ans -= pp();
    cout << ans << endl;
    return 0;
}