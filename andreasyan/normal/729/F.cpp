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
const int N = 4003, S = 70, INF = 1000000009;

int n;
int a[N];
int p[N];

int m;
int mp[100000000];
int dp[7000000];

int sum(int l0, int r0, int l, int r)
{
    if (!(l0 <= l && r <= r0 && l <= r))
        return -INF - INF / 2;
    return p[r] - p[l - 1];
}

int rec(int l, int r, int z, int k)
{
    if (l > r)
        return 0;

    int uu = l * (S * 3) * 2 * S + ((n - r) - (l - 1)) * 2 * S + z * S + k;
    int u = mp[uu];
    if (u)
        return dp[u];
    u = ++m;
    mp[uu] = u;

    if (!z)
    {
        dp[u] = -INF;
        dp[u] = max(dp[u], rec(l + k, r, (z ^ 1), k) + sum(l, r, l, l + k - 1));
        dp[u] = max(dp[u], rec(l + k + 1, r, (z ^ 1), k + 1) + sum(l, r, l, l + k));
        if (dp[u] == -INF)
            dp[u] = 0;
    }
    else
    {
        dp[u] = INF;
        dp[u] = min(dp[u], rec(l, r - k, (z ^ 1), k) - sum(l, r, r - k + 1, r));
        dp[u] = min(dp[u], rec(l, r - k - 1, (z ^ 1), k + 1) - sum(l, r, r - k, r));
        if (dp[u] == INF)
            dp[u] = 0;
    }
    return dp[u];
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    printf("%d\n", rec(1, n, 0, 1));
    /*int ans = 0;
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l; r <= n; ++r)
        {
            for (int z = 0; z < 2; ++z)
            {
                ans += sz(dp[l][r][z]);
            }
        }
    }
    printf("%d\n", ans);*/
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}