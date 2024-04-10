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
const int N = 1503, INF = 1000000009;

int n, s, m, k;
int a[N];
int l[N], r[N];

int u[N];

int p[N];
int dp[N][N];
bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] <= x)
            ++p[i];
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = -INF;
        }
    }

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (u[i] != INF && j > 0)
                dp[i][j] = max(dp[i][j], dp[u[i] - 1][j - 1] + p[i] - p[u[i] - 1]);
        }
    }

    return (dp[n][m] >= k);
}

void solv()
{
    cin >> n >> s >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= s; ++i)
        cin >> l[i] >> r[i];

    for (int i = 1; i <= n; ++i)
        u[i] = INF;
    for (int i = 1; i <= s; ++i)
    {
        for (int j = l[i]; j <= r[i]; ++j)
        {
            u[j] = min(u[j], l[i]);
        }
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i)
        v.push_back(a[i]);

    sort(all(v));
    if (stg(v.back()) == false)
    {
        cout << "-1\n";
        return;
    }
    int l = 0, r = sz(v) - 1;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(v[m]))
        {
            ans = v[m];
            r = m - 1;
        }
        else
            l = m + 1;
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