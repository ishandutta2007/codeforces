#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 15);
struct ban
{
    int q, x;
    ban()
    {
        q = x = 0;
    }
};

int fi(int x, ban p[])
{
    if (x == p[x].x)
        return x;
    return p[x].x = fi(p[x].x, p);
}
void kpc(int x, int y, ban p[])
{
    x = fi(x, p);
    y = fi(y, p);
    if (p[x].q < p[y].q)
        p[x].x = y;
    else
        p[y].x = x;
}

int n, m;
char aa[N];
bool a[N];
ban p[N];

int main()
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    while (n--)
    {
        //////////////////////////////////////
        scanf(" %s", aa);
        for (int i = 1; i <= m; ++i)
            a[i] = false;
        for (int i = 0; i < m / 4; ++i)
        {
            int x;
            if ('0' <= aa[i] && aa[i] <= '9')
                x = aa[i] - '0';
            if ('A' <= aa[i] && aa[i] <= 'F')
                x = aa[i] - 'A' + 10;
            for (int j = 0; j < 4; ++j)
            {
                if ((x & (1 << (4 - j - 1))))
                    a[i * 4 + j + 1] = true;
            }
        }
        //////////////////////////////////////
        ban pp[N];
        for (int i = 1; i <= m; ++i)
        {
            if (a[i] == true)
                pp[i].x = i;
        }
        for (int i = 1; i < m; ++i)
        {
            if (a[i] == true && a[i + 1] == true)
                kpc(i, i + 1, pp);
        }

        int v[N] = {};
        bool c[N] = {};
        for (int i = 1; i <= m; ++i)
        {
            if (p[i].x)
            {
                c[fi(i, p)] = true;
                if (a[i])
                {
                    if (!v[fi(i, p)])
                        v[fi(i, p)] = i;
                    else
                        kpc(v[fi(i, p)], i, pp);
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            if (c[i] && !v[i])
                ++ans;
        }
        memcpy(p, pp, sizeof pp);
    }
    int v[N] = {};
    for (int i = 1; i <= m; ++i)
    {
        if (p[i].x)
        {
            if (!v[fi(i, p)])
                v[fi(i, p)] = i;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        if (v[i])
            ++ans;
    }
    cout << ans << endl;
    return 0;
}