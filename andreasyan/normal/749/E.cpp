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
int a[N];

ll t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += qry(1, n, a[i], n, 1);
        ubd(1, n, a[i], 1, 1);
    }
    memset(t, 0, sizeof t);
    ll pans = 0;
    ll yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        yans -= qry(1, n, a[i], n, 1);
        yans += qry(1, n, 1, a[i], 1);
        pans += yans;
        ubd(1, n, a[i], i, 1);
    }
    ans = (ans + ((double)pans / 2) / ((n * 1LL * (n + 1)) / 2));
    printf("%.12f\n", ans);
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