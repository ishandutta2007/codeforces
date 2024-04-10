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
const int N = 5003, M = 1000000007;

int n, k;

int dp[N][N];

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

void solv()
{
    scanf("%d%d", &n, &k);
    dp[0][0] = 1;
    for (int i = 0; i <= min(n, k); ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * 1LL * (n - i)) % M;
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * 1LL * i) % M;
        }
    }
    int ans = 0;
    for (int i = 1; i <= min(n, k); ++i)
    {
        ans = (ans + dp[i][k] * 1LL * ast(2, n - i)) % M;
    }
    //for (int i = 1; i <= k; ++i)
    //    ans = (ans * 1LL * ast(i, M - 2)) % M;
    //for (int i = 1; i <= k; ++i)
    //    ans = (ans * 1LL * ast(i, M - 2)) % M;
    printf("%d\n", ans);
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