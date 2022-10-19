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
const int N = 30004, K = 200005;
const ll INF = 1000000009000000009;

int n, m, k;
char a[K];
int q[26];

int dp[K];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    scanf(" %s", a);
    for (int i = 0; i < 26; ++i)
        q[i] = 0;
    for (int i = 0; i < k; ++i)
    {
        q[a[i] - 'A']++;
    }
    for (int i = 0; i <= k; ++i)
        dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < 26; ++i)
    {
        if (!q[i])
            continue;
        for (int j = k - q[i]; j >= 0; --j)
        {
            dp[j + q[i]] += dp[j];
        }
    }
    ll ans = INF;
    for (int j = n; j <= k; ++j)
    {
        if (dp[j])
        {
            if (k - j >= m)
            {
                ans = 0;
                break;
            }
            break;
        }
    }
    if (ans == 0)
    {
        printf("%lld\n", ans);
        return;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (!q[i])
            continue;
        for (int j = 0; j <= k - q[i]; ++j)
        {
            dp[j + q[i]] -= dp[j];
        }
        for (int j = 0; j < n; ++j)
        {
            if (dp[j])
            {
                if (j + q[i] >= n)
                {
                    ans = min(ans, (n - j) * 1LL * (m - (k - q[i] - j)));
                }
            }
        }
        if (!ans)
            break;
        for (int j = k - q[i]; j >= 0; --j)
        {
            dp[j + q[i]] += dp[j];
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}