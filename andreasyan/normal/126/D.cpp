#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;
const long long M = 1000000000000000000;

int m;
long long f[N];
void pre()
{
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; ; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > M)
        {
            m = i;
            break;
        }
    }
}

long long dp[N][2];

void solv()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        long long n;
        scanf("%I64d", &n);
        vector<int> v;
        for (int i = m - 1; i >= 0; --i)
        {
            if (n >= f[i])
            {
                v.push_back(i);
                n -= f[i];
            }
        }
        reverse(v.begin(), v.end());
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < v.size(); ++i)
        {
            if (i == 0)
            {
                dp[i][0] = 1;
                dp[i][1] = (v[i] / 2);
            }
            else
            {
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                dp[i][1] = ((v[i] - v[i - 1] - 1) / 2) * (dp[i - 1][0] + dp[i - 1][1]);
                if ((v[i] - v[i - 1]) % 2 == 0)
                    dp[i][1] += dp[i - 1][1];
            }
        }
        printf("%I64d\n", dp[v.size() - 1][0] + dp[v.size() - 1][1]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}