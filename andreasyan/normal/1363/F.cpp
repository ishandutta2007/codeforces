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
const int N = 2003;

int n;
char a[N], b[N];

int pa[N][26], pb[N][26];

int dp[N][N];

void solv()
{
    scanf("%d", &n);
    scanf(" %s", (a + 1));
    scanf(" %s", (b + 1));
    /*n = 2000;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 26 + 'a';
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    for (int i = n; i >= 1; --i)
        swap(b[i], b[rnf() % i + 1]);*/
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            pa[i][j] = pa[i - 1][j];
        pa[i][a[i] - 'a']++;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 26; ++j)
            pb[i][j] = pb[i - 1][j];
        pb[i][b[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (pa[n][i] != pb[n][i])
        {
            printf("-1\n");
            return;
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[i][j] = N;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (pa[i][b[j + 1] - 'a'] - pb[j][b[j + 1] - 'a'])
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
        for (int j = 0; j <= i; ++j)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (a[i + 1] == b[j + 1])
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        }
    }
    int ans = N;
    for (int j = 0; j <= n; ++j)
        ans = min(ans, dp[n][j]);
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}