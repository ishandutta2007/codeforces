#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];
int p[N];

int t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = p[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    if (r <= m)
        return qry(tl, m, l, r, pos * 2);
    if (l > m)
        return qry(m + 1, tr, l, r, pos * 2 + 1);
    return min(qry(tl, m, l, m, pos * 2), qry(m + 1, tr, m + 1, r, pos * 2 + 1));
}

int v[N];

int main()
{
    scanf("%s", &a);
    n = strlen(a);
    int minu = 0;
    for (int i = 0; i < n; ++i)
    {
        p[i + 1] = p[i];
        if (a[i] == '(')
            p[i + 1]++;
        else
            p[i + 1]--;
        minu = min(minu, p[i + 1]);
    }
    for (int i = 0; i <= n; ++i)
        p[i] -= minu;

    bil(0, n, 1);

    int ans = 0, ansq = 1;
    for (int i = n; i >= 0; --i)
    {
        if (v[p[i]] == 0)
        {
            v[p[i]] = i;
            continue;
        }
        if (qry(0, n, i, v[p[i]], 1) - p[i] >= 0)
        {
            if (v[p[i]] - i > ans)
            {
                ans = v[p[i]] - i;
                ansq = 1;
            }
            else if (v[p[i]] - i == ans)
                ++ansq;
        }
        else
            v[p[i]] = i;
    }
    cout << ans << ' ' << ansq << endl;
    return 0;
}