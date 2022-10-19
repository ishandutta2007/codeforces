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
const int N = 200005, M = 1000000009;

int n, qq;
int a[N];

int maxu[N * 4];
int s[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = a[tl];
        s[pos] = a[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    s[pos] = min(M, s[pos * 2] + s[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        maxu[pos] = y;
        s[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    s[pos] = min(M, s[pos * 2] + s[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return -1;
    if (maxu[pos] < y)
        return -1;
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qry(tl, m, l, min(m, r), y, pos * 2);
    if (u != -1)
        return u;
    return qry(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return s[pos];
    int m = (tl + tr) / 2;
    return min(M, qry(tl, m, l, min(m, r), pos * 2) +
                    qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    bil(1, n, 1);

    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x] = y;
        ubd(1, n, x, y, 1);

        int u = 0;
        int p = 0;
        while (1)
        {
            int x = qry(1, n, u + 1, n, p, 1);
            if (x == -1)
            {
                printf("-1\n");
                break;
            }
            int s = qry(1, n, 1, x - 1, 1);
            if (a[x] == s)
            {
                printf("%d\n", x);
                break;
            }
            p = min(M, s + a[x]);
            u = x;
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