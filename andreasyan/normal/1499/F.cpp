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
const int N = 5003, M = 998244353;

int n, k;
vector<int> g[N];

int q[N];
int dp[N][N];
int ndp[N];
void dfs(int x, int p)
{
    q[x] = 1;
    dp[x][0] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);

        for (int i = 0; i < q[x] + q[h]; ++i)
            ndp[i] = 0;

        for (int i = 0; i < q[x]; ++i)
        {
            for (int j = 0; j < q[h]; ++j)
            {
                ndp[i] = (ndp[i] + dp[x][i] * 1LL * dp[h][j]) % M;
                if (i + j + 1 <= k)
                    ndp[max(i, j + 1)] = (ndp[max(i, j + 1)] + dp[x][i] * 1LL * dp[h][j]) % M;
            }
        }

        q[x] += q[h];
        for (int i = 0; i < q[x]; ++i)
            dp[x][i] = ndp[i];
    }
}

void solv()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + dp[1][i]) % M;

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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}