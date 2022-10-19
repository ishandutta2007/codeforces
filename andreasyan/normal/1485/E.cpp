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
const int N = 200005;
const ll INF = 1000000009000000009;

int n;
vector<int> g[N];
int a[N];

int d[N];
vector<int> v[N];
void dfs0(int x, int p)
{
    v[d[x]].push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        d[h] = d[x] + 1;
        dfs0(h, x);
    }
}

ll dp[N];

void solv()
{
    scanf("%d", &n);

    for (int i = 0; i <= n; ++i)
    {
        g[i].clear();
        d[i] = 0;
        v[i].clear();
        dp[i] = 0;
    }

    for (int x = 2; x <= n; ++x)
    {
        int y;
        scanf("%d", &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 2; x <= n; ++x)
        scanf("%d", &a[x]);

    dfs0(1, 1);

    for (int i = 0; i < n; ++i)
    {
        if (v[i + 1].empty())
            break;

        int maxh = a[v[i + 1][0]];
        int minh = a[v[i + 1][0]];
        for (int j = 0; j < v[i + 1].size(); ++j)
        {
            int x = v[i + 1][j];
            maxh = max(maxh, a[x]);
            minh = min(minh, a[x]);
        }

        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            for (int k = 0; k < g[x].size(); ++k)
            {
                int h = g[x][k];
                if (d[h] != d[x] + 1)
                    continue;
                dp[h] = max(dp[h], dp[x] + abs(a[h] - maxh));
                dp[h] = max(dp[h], dp[x] + abs(a[h] - minh));
            }
        }

        ll maxu = -INF;
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            for (int k = 0; k < g[x].size(); ++k)
            {
                int h = g[x][k];
                if (d[h] != d[x] + 1)
                    continue;
                maxu = max(maxu, dp[x] - a[h]);
            }
        }
        for (int j = 0; j < v[i + 1].size(); ++j)
        {
            int x = v[i + 1][j];
            dp[x] = max(dp[x], maxu + a[x]);
        }

        maxu = -INF;
        for (int j = 0; j < v[i].size(); ++j)
        {
            int x = v[i][j];
            for (int k = 0; k < g[x].size(); ++k)
            {
                int h = g[x][k];
                if (d[h] != d[x] + 1)
                    continue;
                maxu = max(maxu, dp[x] + a[h]);
            }
        }
        for (int j = 0; j < v[i + 1].size(); ++j)
        {
            int x = v[i + 1][j];
            dp[x] = max(dp[x], maxu - a[x]);
        }
    }

    ll ans = 0;
    for (int x = 1; x <= n; ++x)
        ans = max(ans, dp[x]);

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}