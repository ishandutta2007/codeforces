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
const int K = 1003, M = 7340033;

int dp[31][K];

void pre()
{
    dp[0][0] = 1;
    for (int i = 1; i <= 30; ++i)
    {
        dp[i][1] = 1;
        for (int ii = 0; ii < 4; ++ii)
        {
            for (int j = K - 1; j >= 0; --j)
            {
                for (int q = 1; j + q < K; ++q)
                {
                    dp[i][j + q] = (dp[i][j + q] + dp[i][j] * 1LL * dp[i - 1][q]) % M;
                }
            }
        }
        dp[i][0] = 1;
    }
}

void solv()
{
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int i = 0;
        while (n % 2 == 1 && n > 1)
        {
            ++i;
            n /= 2;
        }
        printf("%d\n", dp[i][k]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}