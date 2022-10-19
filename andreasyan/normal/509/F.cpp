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
const int N = 503, M = 1000000007;

int n;
int a[N];

int dp[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int d = 0; d <= n - 1; ++d)
    {
        for (int l = 2; l <= n - d + 1; ++l)
        {
            int r = l + d - 1;
            if (d == 0)
            {
                dp[l][r] = 1;
                continue;
            }
            for (int i = l; i <= r; ++i)
            {
                if (i == r || a[l] < a[i + 1])
                    dp[l][r] = (dp[l][r] + dp[l + 1][i] * 1LL * dp[i + 1][r]) % M;
            }
        }
    }
    printf("%d\n", dp[2][n]);
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