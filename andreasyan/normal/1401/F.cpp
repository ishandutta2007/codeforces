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
const int N = (1 << 18) + 18, sN = 20;

int n;

bool r[sN], s[sN];

ll t[N * 4];
void ubd(int tl, int tr, int x, int y, int d, int z, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;

    z ^= r[d];
    int lpos = pos * 2;
    int rpos = pos * 2 + 1;
    if (s[d - 1])
        swap(lpos, rpos);
    if (z)
        swap(lpos, rpos);

    if (x <= m)
        ubd(tl, m, x, y, d - 1, z, lpos);
    else
        ubd(m + 1, tr, x, y, d - 1, z, rpos);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll qry(int tl, int tr, int l, int r, int d, bool z, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;

    z ^= ::r[d];
    int lpos = pos * 2;
    int rpos = pos * 2 + 1;
    if (s[d - 1])
        swap(lpos, rpos);
    if (z)
        swap(lpos, rpos);

    return (qry(tl, m, l, min(m, r), d - 1, z, lpos) +
            qry(m + 1, tr, max(m + 1, l), r, d - 1, z, rpos));
}

void solv()
{
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= (1 << n); ++i)
    {
        int x;
        scanf("%d", &x);
        ubd(1, (1 << n), i, x, n, false, 1);
    }
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            ubd(1, (1 << n), x, y, n, false, 1);
        }
        else if (ty == 2)
        {
            int x;
            scanf("%d", &x);
            r[x] ^= true;
        }
        else if (ty == 3)
        {
            int x;
            scanf("%d", &x);
            s[x] ^= true;
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", qry(1, (1 << n), l, r, n, false, 1));
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}