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
const int N = 35003, K = 102, INF = 1000000009;

int n, k;
int a[N];
int dp[K][N];

int minu[N * 4];
int laz[N * 4];

void bil(int tl, int tr, int j, int pos)
{
    laz[pos] = 0;
    if (tl == tr)
    {
        minu[pos] = dp[j][tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, j, pos * 2);
    bil(m + 1, tr, j, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

void shi(int pos)
{
    minu[pos * 2] += laz[pos];
    minu[pos * 2 + 1] += laz[pos];
    laz[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        minu[pos] += y;
        laz[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return minu[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int u[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (u[a[i]])
            s += (i - u[a[i]]);
        u[a[i]] = i;
        dp[1][i] = s;
    }

    for (int j = 2; j <= k; ++j)
    {
        bil(1, n, j - 1, 1);

        for (int i = 1; i <= n; ++i)
            u[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (u[a[i]])
                ubd(1, n, 1, u[a[i]] - 1, i - u[a[i]], 1);
            u[a[i]] = i;
            dp[j][i] = qry(1, n, 1, i - 1, 1);
        }
    }

    cout << dp[k][n] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}