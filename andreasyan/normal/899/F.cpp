#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 65;
int ctoi(char u)
{
    if ('a' <= u && u <= 'z')
        return u - 'a';
    else if ('A' <= u && u <= 'Z')
        return 26 + u - 'A';
    return 26 + 26 + u - '0';
}

int n, q;
char a[N];

int t[N * 4][M];

void mer(int pos)
{
    for (int i = 0; i < M; ++i)
        t[pos][i] = t[pos * 2][i] + t[pos * 2 + 1][i];
}

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos][ctoi(a[tl])] = 1;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    mer(pos);
}

void shi(int pos)
{
    for (int i = 0; i < M; ++i)
    {
        if (t[pos][i] == 0)
            t[pos * 2][i] = t[pos * 2 + 1][i] = 0;
    }
}

void ubd(int tl, int tr, int l, int r, int u, int pos)
{
    if (tl == l && tr == r)
    {
        t[pos][u] = 0;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, u, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, u, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, u, pos * 2);
        ubd(m + 1, tr, m + 1, r, u, pos * 2 + 1);
    }
    mer(pos);
}

int sum(int pos)
{
    int ans = 0;
    for (int i = 0; i < M; ++i)
        ans += t[pos][i];
    return ans;
}

int qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return tl;
    shi(pos);
    int m = (tl + tr) / 2;
    int suml = sum(pos * 2);
    if (x <= suml)
        return qry(tl, m, x, pos * 2);
    else
        return qry(m + 1, tr, x - suml, pos * 2 + 1);
}

void printf(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        for (int i = 0; i < M; ++i)
            if (t[pos][i])
                cout << a[tl];
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    printf(tl, m, pos * 2);
    printf(m + 1, tr, pos * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    cin >> a;
    bil(0, n - 1, 1);
    while (q--)
    {
        int l, r;
        char u;
        cin >> l >> r >> u;
        l = qry(0, n - 1, l, 1);
        r = qry(0, n - 1, r, 1);
        ubd(0, n - 1, l, r, ctoi(u), 1);
    }
    printf(0, n - 1, 1);
    cout << endl;
    return 0;
}