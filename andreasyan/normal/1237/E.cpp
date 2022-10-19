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
const int N = 1000006, M = 998244353;

int n;
int dp[N][2];

void solv()
{
    scanf("%d", &n);
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int j = 0;
        while (((1 << (j + 1)) - 1) <= i)
            ++j;
        for (int k = max(0, i / 2 - 3); k <= min(i - 1, i / 2 + 3); ++k)
        {
            int l1 = 1;
            int r1 = l1 + k - 1;
            int m = r1 + 1;
            int l2 = m + 1;
            int r2 = i;
            if (r1 - l1 + 1 > ((1 << j) - 1) || r2 - l2 + 1 > ((1 << j) - 1))
                continue;
            if (r1 - l1 + 1 < ((1 << (j - 1)) - 1) || r2 - l2 + 1 < ((1 << (j - 1)) - 1))
                continue;
            if (m % 2 == 0)
            {
                dp[i][0] = (dp[i][0] + dp[r1 - l1 + 1][1] * 1LL * dp[r2 - l2 + 1][0]) % M;
            }
            else
            {
                dp[i][1] = (dp[i][1] + dp[r1 - l1 + 1][0] * 1LL * dp[r2 - l2 + 1][0]) % M;
            }
        }
    }
    printf("%d\n", (dp[n][0] + dp[n][1]) % M);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}