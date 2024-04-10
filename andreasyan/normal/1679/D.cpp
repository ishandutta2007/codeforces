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

int n, m;
ll k;
int a[N];
vector<int> g[N];

int c[N];
bool dfs(int x, int u)
{
    c[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (a[h] > u)
            continue;
        if (c[h] == 1)
            return true;
        if (c[h] == 0)
        {
            if (dfs(h, u))
                return true;
        }
    }
    c[x] = 2;
    return false;
}

int dp[N];
void dfs1(int x, int u)
{
    c[x] = 1;
    dp[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (a[h] > u)
            continue;
        if (!c[h])
            dfs1(h, u);
        dp[x] = max(dp[x], dp[h] + 1);
    }
}

bool stg(int u)
{
    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (a[x] > u)
            continue;
        if (!c[x])
        {
            if (dfs(x, u))
                return true;
        }
    }

    for (int x = 1; x <= n; ++x)
        c[x] = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (a[x] > u)
            continue;
        if (!c[x])
        {
            dfs1(x, u);
            if (dp[x] >= k)
                return true;
        }
    }

    return false;
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    int l = 1, r = 1000000009;
    int u = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            u = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << u << "\n";
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