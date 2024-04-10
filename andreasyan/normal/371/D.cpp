#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;
int a[N];

long long t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

void shi(int pos)
{
    if (t[pos] == 0)
    {
        t[pos * 2] = t[pos * 2 + 1] = 0;
    }
}

int x;
void ubd(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
    {
        if (x > t[pos])
        {
            x -= t[pos];
            t[pos] = 0;
            return;
        }
        if (tl == tr)
        {
            if (t[pos] > x)
            {
                t[pos] -= x;
                x = 0;
            }
            else
            {
                t[pos] = 0;
                x = 0;
            }
            return;
        }
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, pos * 2);
        if (x)
            ubd(m + 1, tr, m + 1, r, pos * 2 + 1);
    }
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return t[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    else
        return qry(m + 1, tr, x, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
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
            cin >> i >> x;
            ubd(1, n, i, n, 1);
        }
        else
        {
            int i;
            cin >> i;
            cout << a[i] - qry(1, n, i, 1) << endl;
        }
    }
    return 0;
}