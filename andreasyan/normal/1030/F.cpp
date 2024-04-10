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
const int N = 200005, M = 1000000007;

int n;
int a[N];
int w[N];

ll s[N * 4];

ll qrys(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return s[pos];
    int m = (tl + tr) / 2;
    return qrys(tl, m, l, min(m, r), pos * 2) +
        qrys(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
}

int qryu(int tl, int tr, ll y, int pos)
{
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    if (s[pos * 2] >= y)
        return qryu(tl, m, y, pos * 2);
    return qryu(m + 1, tr, y - s[pos * 2], pos * 2 + 1);
}

void ubds(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        s[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubds(tl, m, x, y, pos * 2);
    else
        ubds(m + 1, tr, x, y, pos * 2 + 1);
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
}

int s1[N * 4];
void ubd1(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        s1[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd1(tl, m, x, y, pos * 2);
    else
        ubd1(m + 1, tr, x, y, pos * 2 + 1);
    s1[pos] = (s1[pos * 2] + s1[pos * 2 + 1]) % M;
}

int qry1(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return s1[pos];
    int m = (tl + tr) / 2;
    return (qry1(tl, m, l, min(m, r), pos * 2) +
            qry1(m + 1, tr, max(m + 1, l), r, pos * 2 + 1)) % M;
}

void solv()
{
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; ++i)
        ubds(1, n, i, w[i], 1);
    for (int i = 1; i <= n; ++i)
        ubd1(1, n, i, ((a[i] - i) * 1LL * w[i]) % M, 1);

    while (qq--)
    {
        int x, y;
        int l, r;
        scanf("%d%d", &x, &y);
        l = x;
        r = y;
        if (x < 0)
        {
            x *= -1;
            ubds(1, n, x, y, 1);
            ubd1(1, n, x, ((a[x] - x) * 1LL * y) % M, 1);
        }
        else
        {
            ll s = qrys(1, n, l, r, 1);
            s = s / 2 + s % 2;
            s += qrys(1, n, 1, l - 1, 1);
            int u = qryu(1, n, s, 1);

            int ans = 0;
            ans = (ans + qry1(1, n, u, r, 1)) % M;
            ans = (ans - (qrys(1, n, u, r, 1) % M * 1LL * (a[u] - u)) % M + M) % M;

            ans = (ans - qry1(1, n, l, u, 1) + M) % M;
            ans = (ans + (qrys(1, n, l, u, 1) % M * 1LL * (a[u] - u)) % M) % M;

            printf("%d\n", ans);
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