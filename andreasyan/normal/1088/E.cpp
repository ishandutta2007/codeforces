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
const int N = 300005, INF = 1000000009;

int n;
int a[N];
vector<int> g[N];

ll dp[N];

ll ans1 = -INF;

void dfs0(int x, int p)
{
    dp[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        dp[x] += max(0LL, dp[h]);
    }
    ans1 = max(ans1, dp[x]);
}

ll ans2;

void dfs1(int x, int p)
{
    dp[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs1(h, x);
        dp[x] += max(0LL, dp[h]);
    }
    if (dp[x] == ans1)
    {
        ++ans2;
        dp[x] = 0;
    }
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs0(1, 1);
    dfs1(1, 1);
    printf("%lld %lld\n", ans1 * ans2, ans2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}