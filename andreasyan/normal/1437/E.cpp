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
const int N = 500005;
const int INF = N * 3;

int n, k;
int a[N];
int b[N];
bool c[N];

int dp[N];

int minu[N * 8];

void ubd(int tl, int tr, int x, int y, bool z, int pos)
{
    if (tl == tr)
    {
        if (!z)
            minu[pos] = min(minu[pos], y);
        else
            minu[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, z, pos * 2);
    else
        ubd(m + 1, tr, x, y, z, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return INF;
    if (tl == l && tr == r)
        return minu[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d%d", &n, &k);
    a[0] = -INF;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    c[0] = true;
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d", &b[i]);
        c[b[i]] = true;
    }

    vector<int> v;
    for (int i = 0; i <= n; ++i)
    {
        v.push_back(a[i]);
        v.push_back(a[i] - i);
    }
    sort(all(v));

    for (int i = 0; i < N * 8; ++i)
        minu[i] = INF;

    int u = 0;
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = qry(0, sz(v), 0, lower_bound(all(v), a[i] - i) - v.begin(), 1) + i - 1;
        if (i == 0)
            dp[i] = 0;
        else
        {
            if (c[i])
            {
                for (int j = u; j < i; ++j)
                    ubd(0, sz(v), lower_bound(all(v), a[j] - j) - v.begin(), INF, true, 1);
                u = i;
            }
        }
        ubd(0, sz(v), lower_bound(all(v), a[i] - i) - v.begin(), dp[i] - i, false, 1);
    }

    int ans = INF;
    for (int i = u; i <= n; ++i)
        ans = min(ans, dp[i] + (n - i));

    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    while (tt--)
        solv();
    return 0;
}