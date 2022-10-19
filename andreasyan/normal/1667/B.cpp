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
const int N = 500005, INF = 1000000009;

int n;
int a[N];

ll p[N];

int maxu[2][N * 4];

void bil(int ti, int tl, int tr, int pos)
{
    maxu[ti][pos] = -INF;
    if (tl == tr)
        return;
    int m = (tl + tr) / 2;
    bil(ti, tl, m, pos * 2);
    bil(ti, m + 1, tr, pos * 2 + 1);
}

void ubd(int ti, int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        maxu[ti][pos] = max(maxu[ti][pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(ti, tl, m, x, y, pos * 2);
    else
        ubd(ti, m + 1, tr, x, y, pos * 2 + 1);
    maxu[ti][pos] = max(maxu[ti][pos * 2], maxu[ti][pos * 2 + 1]);
}

int qry(int ti, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return -INF;
    if (tl == l && tr == r)
        return maxu[ti][pos];
    int m = (tl + tr) / 2;
    return max(qry(ti, tl, m, l, min(m, r), pos * 2),
               qry(ti, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

int u[N];
int dp[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    vector<ll> v;
    for (int i = 0; i <= n; ++i)
        v.push_back(p[i]);
    sort(all(v));

    for (int i = 0; i <= n; ++i)
        p[i] = lower_bound(all(v), p[i]) - v.begin() + 1;

    bil(0, 1, sz(v), 1);
    bil(1, 1, sz(v), 1);
    for (int i = 1; i <= sz(v); ++i)
        u[i] = -INF;

    ubd(0, 1, sz(v), p[0], dp[0] - 0, 1);
    ubd(1, 1, sz(v), p[0], dp[0] + 0, 1);
    u[p[0]] = max(u[p[0]], dp[0]);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = u[p[i]];
        dp[i] = max(dp[i], qry(0, 1, sz(v), 1, p[i] - 1, 1) + i);
        dp[i] = max(dp[i], qry(1, 1, sz(v), p[i] + 1, sz(v), 1) - i);

        ubd(0, 1, sz(v), p[i], dp[i] - i, 1);
        ubd(1, 1, sz(v), p[i], dp[i] + i, 1);
        u[p[i]] = max(u[p[i]], dp[i]);
    }

    cout << dp[n] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}