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
const int N = 203, M = 1000000007;

int n;
int m;
char a[N];

int u[N];

int dp[N][2][N][N];

void solv()
{
    scanf("%d", &n);
    n *= 2;
    scanf(" %s", a);
    m = strlen(a);
    for (int i = 0; i <= m; ++i)
    {
        vector<char> v;
        for (int j = 0; j < i; ++j)
            v.push_back(a[j]);
        if (i != m)
        {
            if (a[i] == '(')
                v.push_back(')');
            else
                v.push_back('(');
        }
        for (int k = m - 1; k >= 1; --k)
        {
            if (k > v.size())
                continue;
            bool z = true;
            for (int j = v.size() - k; j < v.size(); ++j)
            {
                if (v[j] != a[j - (v.size() - k)])
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                u[i] = k;
                break;
            }
        }
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int q = 0; q < 2; ++q)
        {
            for (int p = 0; p <= n; ++p)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (a[j] == '(')
                    {
                        if (j < m - 1)
                            dp[i + 1][q][p + 1][j + 1] = (dp[i + 1][q][p + 1][j + 1] + dp[i][q][p][j]) % M;
                        else
                            dp[i + 1][(q | 1)][p + 1][u[m]] = (dp[i + 1][(q | 1)][p + 1][u[m]] + dp[i][q][p][j]) % M;
                        if (p > 0)
                            dp[i + 1][q][p - 1][u[j]] = (dp[i + 1][q][p - 1][u[j]] + dp[i][q][p][j]) % M;
                    }
                    else
                    {
                        if (p > 0)
                        {
                            if (j < m - 1)
                                dp[i + 1][q][p - 1][j + 1] = (dp[i + 1][q][p - 1][j + 1] + dp[i][q][p][j]) % M;
                            else
                                dp[i + 1][(q | 1)][p - 1][u[m]] = (dp[i + 1][(q | 1)][p - 1][u[m]] + dp[i][q][p][j]) % M;
                        }
                        dp[i + 1][q][p + 1][u[j]] = (dp[i + 1][q][p + 1][u[j]] + dp[i][q][p][j]) % M;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < m; ++j)
        ans = (ans + dp[n][1][0][j]) % M;
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