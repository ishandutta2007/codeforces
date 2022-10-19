#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;
struct dsu
{
    int p[N];
    dsu()
    {
        for (int i = 1; i < N; ++i)
            p[i] = i;
    }
    int fi(int x)
    {
        if (x == p[x])
            return x;
        return p[x] = fi(p[x]);
    }
    void kpc(int x, int y)
    {
        x = fi(x);
        y = fi(y);
        p[y] = x;
    }
};


int n, q;
dsu a, b;
int bb[N];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i)
        bb[i] = i;
    while (q--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            a.kpc(x, y);
        }
        else if (ty == 2)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int x = b.fi(l);
            while (1)
            {
                if (bb[x] + 1 <= r)
                {
                    a.kpc(x, bb[x] + 1);
                    b.kpc(x, bb[x] + 1);
                    bb[x] = bb[bb[x] + 1];
                }
                else
                    break;
            }
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (a.fi(x) == a.fi(y))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}