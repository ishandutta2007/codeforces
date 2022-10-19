#include <bits/stdc++.h>
using namespace std;
const int N = 200005, K = 6;

int n, k;
int* a[N];
int hak[1 << K];

struct ban
{
    int maxu[1 << K];
    int ans;
    ban(){}
    ban(int* b)
    {
        for (int x = 0; x < (1 << k); ++x)
        {
            maxu[x] = 0;
            for (int i = 0; i < k; ++i)
            {
                if ((x & (1 << i)))
                    maxu[x] += b[i];
                else
                    maxu[x] -= b[i];
            }
        }
        ans = 0;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.ans = max(l.ans, r.ans);
    for (int x = 0; x < (1 << k); ++x)
    {
        res.ans = max(res.ans, l.maxu[x] + r.maxu[hak[x]]);
    }
    for (int x = 0; x < (1 << k); ++x)
        res.maxu[x] = max(l.maxu[x], r.maxu[x]);
    return res;
}

ban t[N * 4];

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
    if (tl == 1 && tr == 2)
        cout << "";
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int* y, int pos)
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
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return mer(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = new int[k];
        for (int j = 0; j < k; ++j)
            cin >> a[i][j];
    }
    for (int x = 0; x < (1 << k); ++x)
    {
        for (int i = 0; i < k; ++i)
        {
            if (!(x & (1 << i)))
                hak[x] |= (1 << i);
        }
    }
    bil(1, n, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int i;
            int *b;
            cin >> i;
            b = new int[k];
            for (int j = 0; j < k; ++j)
                cin >> b[j];
            ubd(1, n, i, b, 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << qry(1, n, l, r, 1).ans << endl;
        }
    }
    return 0;
}