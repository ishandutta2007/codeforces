#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

int n, m;
long long u;
int a[N][N];

char ans[N + N];

int minu[N + N];

long long dp[N + N][N + N];

void solv()
{
    scanf("%d%d%lld", &n, &m, &u);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n + m - 1; ++i)
    {
        minu[i] = N * N * N;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            minu[i + j] = min(minu[i + j], a[i][j]);
        }
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < n + m - 1; ++i)
    {
        v.push_back(m_p(minu[i], i));
    }
    sort(v.begin(), v.end());
    for (int ii = 0; ii < v.size(); ++ii)
    {
        int i = v[ii].second;
        ans[i] = '(';
        memset(dp, 0, sizeof dp);
        dp[v.size()][0] = 1;
        for (int j = v.size() - 1; j >= 0; --j)
        {
            for (int k = 0; k < v.size(); ++k)
            {
                if (ans[j] == '(')
                {
                    if (k - 1 >= 0)
                    {
                        dp[j][k - 1] += dp[j + 1][k];
                        dp[j][k - 1] = min(dp[j][k - 1], u + 1);
                    }
                }
                else if (ans[j] == ')')
                {
                    dp[j][k + 1] += dp[j + 1][k];
                    dp[j][k + 1] = min(dp[j][k + 1], u + 1);
                }
                else
                {
                    if (k - 1 >= 0)
                    {
                        dp[j][k - 1] += dp[j + 1][k];
                        dp[j][k - 1] = min(dp[j][k - 1], u + 1);
                    }
                    dp[j][k + 1] += dp[j + 1][k];
                    dp[j][k + 1] = min(dp[j][k + 1], u + 1);
                }
            }
        }
        if (dp[0][0] >= u)
            continue;
        ans[i] = ')';
        u -= dp[0][0];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%c", ans[i + j]);
        }
        printf("\n");
    }
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