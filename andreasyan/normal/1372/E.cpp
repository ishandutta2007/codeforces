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
const int N = 102;

int n, m;
pair<int, int> u[N][N];

int dp[N][N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            for (int j = l; j <= r; ++j)
                u[i][j] = m_p(l, r);
        }
    }
    for (int d = 1; d <= m; ++d)
    {
        for (int l = 1; l <= m - d + 1; ++l)
        {
            int r = l + d - 1;
            for (int j = l; j <= r; ++j)
            {
                int q = 0;
                for (int i = 1; i <= n; ++i)
                {
                    if (l <= u[i][j].fi && u[i][j].se <= r)
                    {
                        ++q;
                    }
                }
                dp[l][r] = max(dp[l][r], dp[l][j - 1] + dp[j + 1][r] + q * q);
            }
        }
    }
    printf("%d\n", dp[1][m]);
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