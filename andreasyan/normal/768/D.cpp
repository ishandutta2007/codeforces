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
const int N = 10004, K = 1003;

int k, q;

double dp[N][K];

void solv()
{
    scanf("%d%d", &k, &q);
    dp[0][0] = 1;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            dp[i + 1][j + 1] += dp[i][j] * (k - j) / double(k);
            dp[i + 1][j] += dp[i][j] * j / (double)(k);
        }
    }
    while (q--)
    {
        int p;
        scanf("%d", &p);
        int l = 0, r = N - 1;
        int ans;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (dp[m][k] * 2000 >= p - 0.00000001)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        printf("%d\n", ans);
    }
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}