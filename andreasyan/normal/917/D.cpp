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

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int n;
vector<int> g[N];

int q[N];
int dp[N][N][N];
int ndp[N][N];

void dfs(int x, int p)
{
    q[x] = 1;
    dp[x][1][1] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);

        memset(ndp, 0, sizeof ndp);
        for (int qx = 1; qx <= q[x]; ++qx)
        {
            for (int vx = 1; vx <= q[x]; ++vx)
            {
                for (int qh = 1; qh <= q[h]; ++qh)
                {
                    for (int vh = 1; vh <= q[h]; ++vh)
                    {
                        ndp[qx + qh][vx] = (ndp[qx + qh][vx] + dp[x][qx][vx] * 1LL * dp[h][qh][vh] % M * vh) % M;
                        ndp[qx + qh - 1][vx + vh] = (ndp[qx + qh - 1][vx + vh] + dp[x][qx][vx] * 1LL * dp[h][qh][vh]) % M;
                    }
                }
            }
        }
        q[x] += q[h];
        memcpy(dp[x], ndp, sizeof ndp);
    }
}

int c[N][N];

int ans[N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
        }
    }

    for (int k = n - 1; k >= 0; --k)
    {
        for (int vx = 1; vx <= n; ++vx)
        {
            ans[k] = (ans[k] + dp[1][n - k][vx] * 1LL * vx) % M;
        }
        if (k == n - 1)
            ans[k] = 1;
        else
            ans[k] = (ans[k] * 1LL * ast(n, n - k - 2)) % M;
        for (int kk = k + 1; kk < n; ++kk)
        {
            ans[k] = (ans[k] - ans[kk] * 1LL * c[kk][kk - k]) % M;
        }
        ans[k] = (ans[k] + M) % M;
    }

    for (int k = 0; k < n; ++k)
        cout << ans[k] << ' ';
    cout << "\n";
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