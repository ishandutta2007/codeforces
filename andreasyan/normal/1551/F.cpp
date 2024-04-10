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
const int N = 102, M = 1000000007;

int c[N][N];
void pre()
{
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
}

int n, k;
vector<int> g[N];

int d[N];
int q[N][N];
void dfs(int x, int p)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    for (int i = 0; i < n; ++i)
        q[x][i] = 0;
    q[x][d[x]] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        for (int j = 0; j < n; ++j)
            q[x][j] += q[h][j];
    }
}

int dp[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if (k == 2)
    {
        cout << n * (n - 1) / 2 << "\n";
        return;
    }

    int ans = 0;
    for (int r = 1; r <= n; ++r)
    {
        dfs(r, r);
        for (int i = 0; i < n; ++i)
        {
            for (int i = 0; i <= n; ++i)
                dp[i] = 0;
            dp[0] = 1;
            for (int j = 0; j < g[r].size(); ++j)
            {
                int h = g[r][j];
                for (int k = n; k >= 0; --k)
                {
                    if (!dp[k])
                        continue;
                    dp[k + 1] = (dp[k + 1] + dp[k] * 1LL * q[h][i]) % M;
                }
            }
            ans = (ans + dp[k]) % M;
        }
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

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}