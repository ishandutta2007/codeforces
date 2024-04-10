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
const int N = 20, INF = 1000000009;

int n, m;
char a[N][N];
int g[N][N];

int s[N][26], maxu[N][26], xx[N][26], minu[N];

int dp[(1 << N)];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf(" %c", &a[i][j]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &g[i][j]);
    }
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            s[j][a[i][j] - 'a'] += g[i][j];
            maxu[j][a[i][j] - 'a'] = max(maxu[j][a[i][j] - 'a'], g[i][j]);
            xx[j][a[i][j] - 'a'] |= (1 << i);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        minu[i] = INF;
        for (int j = 0; j < m; ++j)
            minu[i] = min(minu[i], g[i][j]);
    }
    for (int x = 0; x < (1 << n); ++x)
        dp[x] = INF;
    dp[0] = 0;
    for (int x = 0; x < (1 << n) - 1; ++x)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!(x & (1 << i)))
            {
                dp[(x | (1 << i))] = min(dp[(x | (1 << i))],
                                         dp[x] + minu[i]);
                for (int j = 0; j < m; ++j)
                {
                    dp[(x | xx[j][a[i][j] - 'a'])] = min(dp[(x | xx[j][a[i][j] - 'a'])],
                                                         dp[x] + s[j][a[i][j] - 'a'] - maxu[j][a[i][j] - 'a']);
                }
                break;
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1]);
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