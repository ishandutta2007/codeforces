#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, q;
char a[N];

int t[N * 4][26];
int laz[N * 4];

void shi(int pos)
{
    if (laz[pos] == -1)
        return;

    for (int i = 0; i < 26; ++i)
        t[pos * 2][i] = t[pos * 2 + 1][i] = 0;

    t[pos * 2][laz[pos]] = t[pos][laz[pos]] / 2 + t[pos][laz[pos]] % 2;
    t[pos * 2 + 1][laz[pos]] = t[pos][laz[pos]] / 2;

    laz[pos * 2] = laz[pos * 2 + 1] = laz[pos];
    laz[pos] = -1;
}

void mer(int pos)
{
    for (int i = 0; i < 26; ++i)
        t[pos][i] = t[pos * 2][i] + t[pos * 2 + 1][i];
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos][a[tl - 1] - 'a']++;
        laz[pos] = a[tl - 1] - 'a';
        return;
    }
    laz[pos] = -1;
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    mer(pos);
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
    {
        for (int i = 0; i < 26; ++i)
            t[pos][i] = 0;
        t[pos][y] = (r - l + 1);
        laz[pos] = y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, y, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, y, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, y, pos * 2);
        ubd(m + 1, tr, m + 1, r, y, pos * 2 + 1);
    }
    mer(pos);
}

int qry(int tl, int tr, int l, int r, int y, int pos)
{
    if (tl == l && tr == r)
        return t[pos][y];
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, y, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, y, pos * 2 + 1);
    return qry(tl, m, l, m, y, pos * 2) + qry(m + 1, tr, m + 1, r, y, pos * 2 + 1);
}

void tpel(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        cout << (char)(laz[pos] + 'a');
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    tpel(tl, m, pos * 2);
    tpel(m + 1, tr, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    cin >> a;
    bil(1, n, 1);
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int u[26];
        for (int i = 0; i < 26; ++i)
            u[i] = qry(1, n, l, r, i, 1);
        if (k == 1)
        {
            int ll = l;
            for (int i = 0; i < 26; ++i)
            {
                if (!u[i])
                    continue;
                ubd(1, n, ll, ll + u[i] - 1, i, 1);
                ll = ll + u[i];
            }
        }
        else
        {
            int ll = l;
            for (int i = 25; i >= 0; --i)
            {
                if (!u[i])
                    continue;
                ubd(1, n, ll, ll + u[i] - 1, i, 1);
                ll = ll + u[i];
            }
        }
    }
    tpel(1, n, 1);
    cout << endl;
    return 0;
}