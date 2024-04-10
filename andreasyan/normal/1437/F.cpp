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

int f[N];
int c[N][N];
void pre()
{
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = (f[i - 1] * 1LL * i) % M;
    for (int i = 0; i < N; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
}

int n;
int a[N];

int q[N];
int uu[N];

int dp[N][N];
int s[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    if (a[n - 1] * 2 > a[n])
    {
        printf("0\n");
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[j] * 2 <= a[i])
                ++q[i];
        }
        uu[i] = n + 1;
        for (int j = n; j >= 1; --j)
        {
            if (a[j] >= a[i] * 2)
                --uu[i];
        }
    }

    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j == n)
            {
                dp[i][j] = f[n - i];
                continue;
            }
            int qq = (q[j] - (i - 1));
            dp[i][j] = (dp[i + 1][j] * 1LL * qq) % M;
            for (int k = i + 1; k <= min(n, i + 1); ++k)
            {
                if (k - i - 1 > q[j] - (i - 1))
                    continue;
                dp[i][j] = (dp[i][j] + (s[k][uu[j]] * 1LL * c[q[j] - (i - 1)][k - i - 1]) % M * 1LL * f[k - i - 1]) % M;
            }
        }
        for (int j = n; j >= 1; --j)
            s[i][j] = (s[i][j + 1] + dp[i][j]) % M;
    }

    int ans = 0;
    for (int j = 1; j <= n; ++j)
        ans = (ans + dp[1][j]) % M;

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    int tt = 1;
    while (tt--)
        solv();
    return 0;
}