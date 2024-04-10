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
const int N = 100015;

int n;
char aa[N], a[N];

int dp[N][2][2];

void solv()
{
    scanf(" %s", aa);
    n = strlen(aa);

    for (int i = 3; i <= n + 3; ++i)
        a[i] = aa[i - 3];

    for (int i = 0; i <= n + 3; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = N;

    dp[2][1][1] = 0;

    for (int i = 2; i <= n + 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                for (int z = 0; z < 2; ++z)
                {
                    if ((z || j || a[i + 1] != a[i - 1]))
                    {
                        if ((z || k || a[i + 1] != a[i]))
                        {
                            dp[i + 1][k][z] = min(dp[i + 1][k][z], dp[i][j][k] + z);
                        }
                    }
                }
            }
        }
    }

    int ans = N;
    for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
            ans = min(ans, dp[n + 3][j][k]);

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
        solv();
    return 0;
}