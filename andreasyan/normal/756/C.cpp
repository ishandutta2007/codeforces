#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, M = 1000000007;

struct ban
{
    int maxu;
    int sum;
    ban()
    {
        maxu = sum = 0;
    }
    ban(int x)
    {
        if (x == 1)
        {
            maxu = sum = x;
        }
        else
        {
            maxu = 0;
            sum = x;
        }
    }
};

ban t[N * 4];

ban mer(const ban& l, const ban& r)
{
    ban ans;
    ans.sum = l.sum + r.sum;
    ans.maxu = max(r.maxu, l.maxu + r.sum);
    return ans;
}

void ubd(int tl, int tr, int x, int y, int pos)
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

int qry(int tl, int tr, int y, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (t[pos * 2 + 1].maxu + y > 0)
        return qry(m + 1, tr, y, pos * 2 + 1);
    return qry(tl, m, y + t[pos * 2 + 1].sum, pos * 2);
}

int n;
int a[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        int ty;
        scanf("%d", &ty);
        if (ty == 0)
            ubd(1, n, x, -1, 1);
        else
        {
            ubd(1, n, x, 1, 1);
            int y;
            scanf("%d", &y);
            a[x] = y;
        }
        if (t[1].maxu > 0)
            printf("%d\n", a[qry(1, n, 0, 1)]);
        else
            printf("-1\n");
    }
    return 0;
}