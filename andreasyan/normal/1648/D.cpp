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
const ll INF = 1000000009000000009;

int n;
int a[4][N];
int q;
int l1[N], r1[N], k1[N];

ll p0[N], s0[N];
ll p[N];

vector<int> v[N];

bool c[N];
priority_queue<pair<int, int> > s[N * 4];
ll maxu[N * 4], t[N * 4];

void ubd0(int tl, int tr, int x, ll y, int pos)
{
    while (!s[pos].empty() && !c[s[pos].top().se])
        s[pos].pop();
    if (tl == tr)
    {
        maxu[pos] = y;
        if (!s[pos].empty())
            t[pos] = max(t[pos], maxu[pos] + s[pos].top().fi);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd0(tl, m, x, y, pos * 2);
    else
        ubd0(m + 1, tr, x, y, pos * 2 + 1);

    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
    if (!s[pos].empty())
        t[pos] = max(t[pos], maxu[pos] + s[pos].top().fi);
}

void ubd(int tl, int tr, int l, int r, int y, int yi, int pos)
{
    if (l > r)
        return;
    while (!s[pos].empty() && !c[s[pos].top().se])
        s[pos].pop();
    if (tl == l && tr == r)
    {
        if (y > 0)
            s[pos].push(m_p(-y, yi));
        if (tl == tr)
            t[pos] = -INF;
        else
            t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
        if (!s[pos].empty())
            t[pos] = max(t[pos], maxu[pos] + s[pos].top().fi);
        return;
    }
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, yi, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, yi, pos * 2 + 1);

    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
    if (!s[pos].empty())
        t[pos] = max(t[pos], maxu[pos] + s[pos].top().fi);
}

ll dp[N];

void solv()
{
    cin >> n >> q;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= q; ++i)
        cin >> l1[i] >> r1[i] >> k1[i];

    for (int j = 1; j <= n; ++j)
    {
        p0[j] = p0[j - 1] + a[1][j];
        p[j] = p[j - 1] + a[2][j];
    }
    for (int j = n; j >= 1; --j)
        s0[j] = s0[j + 1] + a[3][j];

    for (int i = 1; i <= q; ++i)
    {
        v[l1[i]].push_back(i);
        v[r1[i] + 1].push_back(-i);
    }

    for (int i = 0; i < N * 4; ++i)
    {
        maxu[i] = -INF;
        t[i] = -INF;
    }

    ll ans = -INF;
    multiset<ll> ss;
    dp[0] = -INF;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j] > 0)
            {
                c[v[i][j]] = true;
                ubd(1, n, l1[v[i][j]], r1[v[i][j]], k1[v[i][j]], v[i][j], 1);
                ss.insert(dp[l1[v[i][j]] - 1] - p[l1[v[i][j]] - 1] - k1[v[i][j]]);
            }
            else
            {
                v[i][j] *= -1;
                c[v[i][j]] = false;
                ubd(1, n, l1[v[i][j]], r1[v[i][j]], -k1[v[i][j]], v[i][j], 1);
                ss.erase(ss.find(dp[l1[v[i][j]] - 1] - p[l1[v[i][j]] - 1] - k1[v[i][j]]));
            }
        }
        ubd0(1, n, i, p0[i] - p[i - 1], 1);
        dp[i] = t[1] + p[i];
        if (!ss.empty())
            dp[i] = max(dp[i], *(--ss.end()) + p[i]);
        ans = max(ans, dp[i] + s0[i]);
    }

    cout << ans << "\n";
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
    {
        solv();
    }
    return 0;
}