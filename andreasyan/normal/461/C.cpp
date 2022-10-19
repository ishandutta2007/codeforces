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

int t[N * 4];

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int n, qq;
bool r;
int l0, r0;

void solv()
{
    scanf("%d%d", &n, &qq);
    l0 = 1, r0 = n;
    for (int i = 1; i <= n; ++i)
        ubd(1, n, i, 1, 1);
    while (qq--)
    {
        int ty;
        scanf("%d", &ty);
        if (ty == 1)
        {
            int u;
            scanf("%d", &u);
            if (u <= (r0 - l0 + 1) / 2)
            {
                if (!r)
                {
                    for (int i = l0, j = l0 + u + u - 1; i <= l0 + u - 1; ++i, --j)
                    {
                        ubd(1, n, j, qry(1, n, i, i, 1), 1);
                    }
                    l0 = l0 + u;
                }
                else
                {
                    for (int i = r0, j = r0 - u - u + 1; i >= r0 - u + 1; --i, ++j)
                    {
                        ubd(1, n, j, qry(1, n, i, i, 1), 1);
                    }
                    r0 = r0 - u;
                }
            }
            else
            {
                u = (r0 - l0 + 1) - u;
                if (r)
                {
                    for (int i = l0, j = l0 + u + u - 1; i <= l0 + u - 1; ++i, --j)
                    {
                        ubd(1, n, j, qry(1, n, i, i, 1), 1);
                    }
                    l0 = l0 + u;
                }
                else
                {
                    for (int i = r0, j = r0 - u - u + 1; i >= r0 - u + 1; --i, ++j)
                    {
                        ubd(1, n, j, qry(1, n, i, i, 1), 1);
                    }
                    r0 = r0 - u;
                }
                r ^= true;
            }
            /*printf("%d %d\n", l0, r0);
            for (int i = l0; i <= r0; ++i)
                printf("%d ", qry(1, n, i, i, 1));
            printf("\n");*/
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (!::r)
                printf("%d\n", qry(1, n, l0 + l, l0 + r - 1, 1));
            else
                printf("%d\n", qry(1, n, r0 - r + 1, r0 - l, 1));
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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}