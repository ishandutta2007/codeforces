#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];

struct ban
{
    int minu;
    int sum;
    int maxu;
    ban()
    {
        minu = 0;
        sum = 0;
        maxu = 0;
    }
    ban(char x)
    {
        if (x == '(')
        {
            minu = 0;
            sum = 1;
            maxu = 1;
        }
        else if (x == ')')
        {
            minu = -1;
            sum = -1;
            maxu = 0;
        }
        else
        {
            minu = 0;
            sum = 0;
            maxu = 0;
        }
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.sum = l.sum + r.sum;
    res.minu = min(l.minu, l.sum + r.minu);
    res.maxu = max(l.maxu, l.sum + r.maxu);
    return res;
}

ban t[N * 4];
void ubd(int tl, int tr, int x, char y, int pos)
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

int main()
{
    scanf("%d", &n);
    scanf(" %s", a);
    int x = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 'L')
        {
            x = max(1, x - 1);
        }
        else if (a[i] == 'R')
        {
            x = x + 1;
        }
        else
        {
            ubd(1, 1000002, x, a[i], 1);
        }
        if (t[1].sum == 0 && t[1].minu >= 0)
            printf("%d ", t[1].maxu);
        else
            printf("-1 ");
    }
    printf("\n");
    return 0;
}