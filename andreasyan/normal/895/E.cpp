#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n;

double t[N * 4];
double lazg[N * 4], lazb[N * 4];

void shi(int tl, int tr, int pos)
{
    int m = (tl + tr) / 2;
    t[pos * 2] = t[pos * 2] * lazb[pos] + (m - tl + 1) * lazg[pos];
    lazb[pos * 2] *= lazb[pos];
    lazg[pos * 2] = lazg[pos * 2] * lazb[pos] + lazg[pos];
    t[pos * 2 + 1] = t[pos * 2 + 1] * lazb[pos] + (tr - m) * lazg[pos];
    lazb[pos * 2 + 1] *= lazb[pos];
    lazg[pos * 2 + 1] = lazg[pos * 2 + 1] * lazb[pos] + lazg[pos];
    lazb[pos] = 1;
    lazg[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, double x, double y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        t[pos] = t[pos] * x + (r - l + 1) * y;
        lazb[pos] *= x;
        lazg[pos] = lazg[pos] * x + y;
        return;
    }
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), x, y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

double qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    for (int i = 0; i < N * 4; ++i)
        lazb[i] = 1;
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        ubd(1, n, i, i, 1, x, 1);
    }
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            double d1 = r1 - l1 + 1;
            double d2 = r2 - l2 + 1;
            double s1 = qry(1, n, l1, r1, 1);
            double s2 = qry(1, n, l2, r2, 1);
            ubd(1, n, l1, r1, (d1 - 1) / d1, (s2 / d2) / d1, 1);
            ubd(1, n, l2, r2, (d2 - 1) / d2, (s1 / d1) / d2, 1);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%.9f\n", qry(1, n, l, r, 1));
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}