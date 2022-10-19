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
const int N = 3003;

ll ans;

int n, k;
vector<int> a[N];
ll s[N];

ll dp[N * 4][N];

void rec(int l, int r, int pos)
{
    if (l == r)
    {
        ll p = 0;
        for (int q = 0; q <= sz(a[l]); ++q)
        {
            if (q)
                p += a[l][q - 1];
            ans = max(ans, p + dp[pos][k - q]);
        }
        return;
    }

    int m = (l + r) / 2;
    for (int i = 0; i <= k; ++i)
        dp[pos * 2][i] = dp[pos * 2 + 1][i] = dp[pos][i];

    for (int u = m + 1; u <= r; ++u)
    {
        for (int i = k; i >= 0; --i)
        {
            if (i + sz(a[u]) <= k)
                dp[pos * 2][i + sz(a[u])] = max(dp[pos * 2][i + sz(a[u])],
                                                dp[pos * 2][i] + s[u]);
        }
    }
    for (int u = l; u <= m; ++u)
    {
        for (int i = k; i >= 0; --i)
        {
            if (i + sz(a[u]) <= k)
                dp[pos * 2 + 1][i + sz(a[u])] = max(dp[pos * 2 + 1][i + sz(a[u])],
                                                    dp[pos * 2 + 1][i] + s[u]);
        }
    }

    rec(l, m, pos * 2);
    rec(m + 1, r, pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
        while (sz(a[i]) > k)
            a[i].pop_back();
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
            s[i] += a[i][j];
    }

    rec(1, n, 1);

    printf("%lld\n", ans);
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