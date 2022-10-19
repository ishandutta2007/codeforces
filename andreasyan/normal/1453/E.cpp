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

int n;
vector<int> g[N];

int dp[N];
void dfs(int x, int p, int k)
{
    int minu = N;
    int maxu = 0;
    int q = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x, k);
        minu = min(minu, dp[h]);
        maxu = max(maxu, dp[h]);
        if (dp[h] == 1)
            ++q;
    }

    if (minu < 1)
    {
        dp[x] = minu - 1;
        return;
    }
    if (minu == 1)
    {
        if (q == 1)
            dp[x] = minu - 1;
        else
            dp[x] = minu - 2;
        return;
    }

    if (minu == N)
    {
        dp[x] = k;
        return;
    }

    dp[x] = maxu - 1;
}

bool stg(int k)
{
    dfs(1, 1, k);
    return (dp[1] >= 0);
}

void solv()
{
    scanf("%d", &n);
    for (int x = 1; x <= n; ++x)
        g[x].clear();
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int l = 1, r = n;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}