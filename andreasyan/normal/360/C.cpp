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
const int N = 2003, M = 1000000007;

int n, k;
char a[N];

int dp[N][N];
int p[N][N];

void solv()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", (a + 1));
    dp[0][0] = 1;
    p[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            for (int q = 0; q + (i - j) * (n - i + 1) <= k; ++q)
            {
                dp[i][q + (i - j) * (n - i + 1)] = (dp[i][q + (i - j) * (n - i + 1)] +
                                                    dp[j][q] * 1LL * ('z' - a[i])) % M;
            }
        }
        for (int q = 0; q <= k; ++q)
            dp[i][q] = (dp[i][q] + p[i - 1][q] * 1LL * (a[i] - 'a')) % M;
        for (int q = 0; q <= k; ++q)
            p[i][q] = (p[i - 1][q] + dp[i][q]) % M;
    }
    printf("%d\n", p[n][k]);
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